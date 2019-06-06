#include<stdio.h>
#define NUM 1000

void bubble(int x[], int num);
void swap(int *a, int *b);

int n_comp=0, n_exchange=0; //比較回数と交換回数（グローバル変数）

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
	bubble(x,num);	//バブルソート
	printf("整列後データ：");
	for(i=0;i<num;i++){
		printf("%4d",x[i]);
	}
	printf("\n");
	printf("比較回数：%d\n",n_comp);
	printf("交換回数：%d\n",n_exchange);
	return 0;
}

void bubble(int x[],int num)
{
	int i,j;
}

void swap(int *a, int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}