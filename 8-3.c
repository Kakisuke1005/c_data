#include<stdio.h>
#include<stdlib.h>
#define NUM 100

void bubble(int x[], int num);
void insertion(int x[], int num);
void swap(int *a, int *b);

int n_exchange=0,n_shift=0,n_insert=0,n_bub_comp=0,n_ins_comp=0;

int main()
{
  int data_bub[NUM],data_ins[NUM];
  int i,j,num;
  for(i=0;i<5;i++){
    num=(i*20)+20;
    for(j=0;j<NUM;j++){
      data_bub[j]=rand();
      data_ins[j]=data_bub[j];
    }
    bubble(data_bub,num);
    insertion(data_ins,num);
    printf("データの個数 %d個\n",num);
    printf("単純交換法：比較回数 %d 交換回数 %d\n",n_bub_comp,n_exchange);
    printf("単純挿入法：比較回数 %d シフト回数 %d 挿入回数 %d\n",n_ins_comp,n_shift,n_insert);
    /* n_exchange=0;
    n_bub_comp=0;
    n_ins_comp=0;
    n_shift=0;
    n_insert=0;*/
  }
  return 0;
}

  void bubble(int x[], int num)
{
  int i,j;
  for(i=num-1;i>=0;i--){
    for(j=0;j<i;j++){
      n_bub_comp++;
      if(x[i]>x[j+1]){
	n_exchange++;
	swap(&x[j],&x[j+1]);
      }
    }
  }
}

void insertion(int x[], int num)
{
  int i,j,tmp;
  for(i=1;i<num;i++){
    tmp=x[i];
    for(j=i-1;j>=0;j--){
      n_ins_comp++;
      if(x[j]>tmp){
	n_shift++;
	x[j+1]=x[j];
      }else{
	break;
      }
    }
    n_insert++;
    x[j+1]=tmp;
  }
}

void swap(int *a, int *b)
{
  int tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
}
