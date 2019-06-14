#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM 100

void swap(int *a, int *b);
void quick(int x[],int left,int right);
void bubble(int y[],int num);

int n_comp_quick=0,n_comp_bubble=0,n_exchange_quick=0,n_exchange_bubble=0;

int main()
{
  int num,i,j;
  int x[NUM],y[NUM];
  for(i=0;i<5;i++){ //実行回数のループ
    num=20;
    srand(time(NULL));
    srand(0);
    for(j=0;j<num;j++){
      x[j]=rand();
      y[j]=x[j];
    }
    bubble(y,num);
    quick(x,0,num-1);
    printf("データ数%d個\n",num);
    printf("＜クイックソート法＞\n");
    printf("比較回数 %d回\n",n_comp_quick);
    printf("交換回数 %d回\n",n_exchange_quick);
    printf("＜バブルソート法＞\n");
    printf("比較回数 %d回\n",n_comp_bubble);
    printf("交換回数 %d回\n",n_comp_bubble);
    printf("--\n");
    num+=20;
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
    n_comp_quick++;
    if(pl<=pr){
      n_exchange_quick++;
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
      n_comp_bubble++;
      if(y[j]>y[j+1]){
	n_exchange_bubble++;
	swap(&y[j],&y[j+1]);
      }
    }
  }
}
