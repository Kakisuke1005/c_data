#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM 100000

void swap(int *a, int *b);
void quick(int x[],int left,int right);
void bubble(int y[],int num);

int main()
{
  int num,i,j;
  int a[NUM],b[NUM];
  time_t start,end;
  srand(0);
  num=5000;
  for(i=0;i<5;i++){ //実行化数のループ
    for(j=0;j<num;j++){
      a[j]=rand();
      b[j]=a[j];
    }
    printf("データ数 %d個\n",num);
    start=clock();
    quick(a,0,num-1);
    end=clock();
    printf("クイックソートの計算時間 %.3f秒\n",(float)(end-start)/CLOCKS_PER_SEC);
    start=clock();
    bubble(b,num);
    end=clock();
    printf("バブルソートの計算時間 %.3f秒\n",(float)(end-start)/CLOCKS_PER_SEC);
    num*=2;
  }
  return 0;
}

void swap(int *a, int *b)
{
  int tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
}

void quick(int x[], int left, int right)
{
  int pl,pr,pivot;
  pl=left;
  pr=right;
  pivot=x[(pl+pr)/2];
  do{
    while(x[pl]<pivot){
      pl++;
    }
    while(x[pr]>pivot){
      pr--;
    }
    if(pl<=pr){
      swap(&x[pl],&x[pr]);
      pl++;
      pr--;
    }
  }while(pl<=pr);
  if(left<pr){
    quick(x,left,pr);
  }
  if(pl<right){
    quick(x,pl,right);
  }
}

void bubble(int y[], int num)
{
  int i,j;
  for(i=num-1;i>=0;i--){
    for(j=0;j<i;j++){
      if(y[j]>y[j+1]){
	      swap(&y[j],&y[j+1]);
      }
    }
  }
}