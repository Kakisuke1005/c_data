#include<stdio.h>
int Factorial(int num);
int main()
{
	int num,ans;
	printf("自然数を入力して下さい:");
	scanf("%d",&num);
	ans=Factorial(num);
	printf("%dの階乗は%dです\n",num,ans);
	return 0;
}

int Factorial(int num)
{
	int ans;
	printf("関数Factorial(%d)にはいりました\n",num);
	if(num==0){
		ans=1;
	}else{
		ans=num*Factorial(num-1);
	}
	printf("関数Factorial(%d)から出ます:Factorial(%d)=%d\n",num,num,ans);
	return ans;
}