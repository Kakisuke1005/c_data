#include<stdio.h>
int point(int n);
int main()
{
	int num,point_sum;
	printf("いくつ買いますか:");
	scanf("%d",&num);
	point_sum=point(num);
	printf("ポイントは%.0d点です\n",point_sum);
	return 0;
}

int point(int n)
{
	int sum=0;
	if(n==1){
		sum=10;
	}else if(n<=10){
		sum=5+point(n-1);
	}else{
		sum=point(n-1)*1.1;
	}
	return sum;
}