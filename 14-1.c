#include<stdio.h>

int fibonacci(int n);

int main()
{
  int num,ans;
  printf("n番目のフィボナッチ数を求めます\n");
  printf("nの値は？：");
  scanf("%d",&num);
  ans=fibonacci(num);
  printf("%d番目のフィボナッチ数は%dです\n",num,ans);
  return 0;
}

int fibonacci(int n)
{
  if(n==0){
    return 0;
  }else if(n==1){
    return 1;
  }else{
    return fibonacci(n-1)+fibonacci(n-2);
  }
}
