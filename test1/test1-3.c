#include<stdio.h>
int koyakusu(int a, int b);

int main()
{
  int a,b;
  int divisor;
  printf("2つの自然数を入力しなさい\n");
  printf("aの値は?:");
  scanf("%d",&a);
  printf("bの値は?:");
  scanf("%d",&b);
  divisor=koyakusu(a,b);
  printf("%dと%dの最大公約数は%dです\n",a,b,divisor);
  return 0;
}

int koyakusu(int a,int b)
{
  int r;
  r=a%b;
  if(r==0){
    return b;
  }else{
    a=b;
    b=r;
  }
  return koyakusu(a,b);
}

