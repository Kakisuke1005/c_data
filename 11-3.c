#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void ShowList(int data[]);
int InsertNode(int no,int insdata,int data[]);
int DeleteNode(int no,int data[]);

int main()
{
  int Data[MAX]={2,4,6,8,10,12,14,16,18,-1};
  int ctrl,no,insdata,id;
  while(1){
    ShowList(Data);
    printf("編集選択（挿入=0，削除=1，編集終了=-1）：");
    scanf("%d",&ctrl);
    switch(ctrl){
    case 0:
      printf("挿入位置：");
      scanf("%d",&no);
      printf("挿入データ：");
      scanf("%d",&insdata);
      id=InsertNode(no,insdata,Data);
      if(id==-1){
	printf("---挿入できませんでした---\n");
      }
      break;
    case 1:
      printf("削除位置：");
      scanf("%d",&no);
      id=DeleteNode(no,Data);
      if(id==-1){
	printf("---削除できませんでした---\n");
      }
      break;
    case -1:
      exit(0);
    }
  }
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

int InsertNode(int no,int insdata,int data[])
{
  int i,num;
  no-=1;
  for(num=0;num<MAX;num++){
    if(data[num]==-1){
      break;
    }
  }
    if(num==MAX){
      return -1;
    }else if(num<no){
      return -1;
    }else{
      for(i=num-1;i>=no;i--){
	data[i+1]=data[i];
      }
      data[no]=insdata;
      return 0;
    }
}

int DeleteNode(int no,int data[])
{
  int i,num;
  no-=1;
  for(num=0;num<MAX;num++){
    if(data[num]==-1){
      break;
    }
  }
  if(no<0||num<=no){
    return -1;
  }else{
    for(i=no+1;i<num;i++){
      data[i-1]=data[i];
    }
    data[num-1]=-1;
    return 0;
  }
}

