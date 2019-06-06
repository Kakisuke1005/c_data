#include<stdio.h>
#define NUM 1000

void bubble(int x[], int num);
void swap(int *a, int *b);

int n_comp=0, n_exchange=0; //比較回数と交換回数（グローバル変数）

int main()
{
	int i,num,x[NUM];
}

void bubble(int x[],int num)
{}

void swap(int *a, int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}