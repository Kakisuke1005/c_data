#include<stdio.h>
#define NUM 10

void quick(int a[], int left, int right); //クイックソート関数
void swap(int *a, int *b);

int bus=0; //バス　グローバル変数

int main()
{
  int a[]={7,2,5,3,1,10,6,8,9,4};
  quick(a,0,NUM-1);
  printf("ソート終了：");
  for(int i=0;i<NUM;i++){
    printf("%d ",a[i]);
  }
  printf("\n");
  return 0;
}

void quick(int a[], int left, int right)
{
  int pl,pr,pivot;
  pl=left;
  pr=right;
  pivot=a[(pl+pr)/2]; //配列の中央
  bus++;
  printf("%d回目の呼び出し:\n",bus);
  printf("＜開始時＞\n");
  printf("左端の値：%d 添え字：%d\n",a[left],left);
  printf("右端の値：%d 添え字：%d\n",a[right],right);
  printf("ピボットの値：%d\n",pivot);
  printf("左端から右端の値：");
  for(int i=left;i<=right;i++){
    printf("%d ",a[i]);
  }
  printf("\n");
  do{
    while(a[pl]<pivot){
      pl++;
    }
    while(a[pr]>pivot){
      pr--;
    }
    if(pl<=pr){
      swap(&a[pl],&a[pr]);
      pl++;
      pr--;
    } 
  }while(pl<=pr);
  printf("＜ピボットによる分類結果＞\n");
  printf("左端から右端の値：");
  for(int i=left;i<=right;i++){
    printf("%d ",a[i]);
  }
  printf("\n");
  if(left<pr){
    quick(a,left,pr);
  }
  if(pl<right){
    quick(a,pl,right);
  }
}

void swap(int *a,int *b)
{
  int tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
}
