#include<stdio.h>
#define NUM 1000

void insertion(int x[], int num);

int n_comp=0, n_insert=0, n_shift=0; //比較回数とシフト回数（グローバル変数）

int main()
{
  int i,num,x[NUM];
  scanf("%d",&num);	//読み込む数値の数を入力
  for(i=0;i<num;i++){
    scanf("%d",&x[i]);
  }
  printf("整列前データ：");
  for(i=0;i<num;i++){
    printf("%4d",x[i]);
  }
  printf("\n");
  insertion(x,num);    
  printf("整列後データ：");
  for(i=0;i<num;i++){
    printf("%4d",x[i]);
  }
  printf("\n");
  printf("比較回数：%d\n",n_comp);
  printf("シフト回数：%d\n",n_shift);
  printf("挿入回数：%d\n",n_insert);
  return 0;
}

void insertion(int x[], int num) //挿入法
{
  int i,j,tmp;
  for(i=1;i<num;i++){
    tmp=x[i];
    for(j=i-1;j>=0;j--){
      n_comp++;
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
