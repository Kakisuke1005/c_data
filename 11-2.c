#include<stdio.h>
#define MAX 10

void ShowList(int data[]);

int main()
{
  int Data[MAX]={2,4,6,8,10,12,14,16,18,-1};
  ShowList(Data);
  return 0;
}

void ShowList(int data[])
{
  int i;
  printf("リスト：");
  for(i=0;i<MAX;i++){
    if(data[i]!=-1){
      printf("%d ",data[i]);
    }else{
      break;
    }
  }
  printf("\n");
}
