#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct{
  int nodedata;
  int nextindex;
}LIST;

void ShowList(LIST data[]);
int InsertNode(int no,int insdata,LIST data[]);
int DeleteNode(int no,LIST data[]);
int getNode(int no,LIST data[]);

int main()
{
  LIST data[MAX];
  int ctrl,no,insdata,id;
  for(int i=0;i<MAX;i++){
    data[i].nodedata=-1;
    data[i].nextindex=-1;
  }
  data[0].nodedata=1,data[0].nextindex=3;
  data[1].nodedata=9,data[1].nextindex=2;
  data[2].nodedata=4,data[2].nextindex=5;
  data[3].nodedata=3,data[3].nextindex=4;
  data[4].nodedata=5,data[4].nextindex=1;
  data[5].nodedata=15,data[5].nextindex=-1;
  while(1){
    ShowList(data);
    printf("編集選択（挿入=0，削除=1，取得=2，編集終了=-1）：");
    scanf("%d",&ctrl);
    switch(ctrl){
    case 0:
      printf("挿入位置: ");
      scanf("%d",&no);
      printf("挿入データ:");
      scanf("%d",&insdata);
      id=InsertNode(no,insdata,data);
      if(id==-1){
	printf("---挿入できませんでした---\n");
      }
      break;
    case 1:
      printf("削除位置：");
      scanf("%d",&no);
      id=DeleteNode(no,data);
      if(id==-1){
	printf("---削除できませんでした---\n");
      }
      break;
    case 2:
      printf("取得位置：");
      scanf("%d",&no);
      id=getNode(no,data);
      if(id==-1){
	printf("---取得できませんでした---\n");
      }
      break;
    case -1:
      exit(0);
    }
  }
  return 0;
}

void ShowList(LIST data[])
{
  int i=0;
  printf("リスト：");
  while(1){
    printf("%d ",data[i].nodedata);
    i=data[i].nextindex;
    if(i==-1){
      break;
    }
  }
  printf("\n");
}

int InsertNode(int no,int insdata,LIST data[])
{}

int DeleteNode(int no,LIST data[])
{}

int getNode(int no,LIST data[])
{}
