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

int head=0;  //先頭の添字

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
  int i=head;
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

int InsertNode(int no,int insdata,LIST data[])  //データの末尾に挿入不可　修正必須
{
  int blank; //空いてる場所
  int num=0,i=head,pre=0;
  for(blank=0;blank<MAX;blank++){ //空いてる場所を探す
    if(data[blank].nodedata==-1){
      break;
    }
  }
  if(no<0||blank==MAX){ //挿入位置対象外と空きがない場合挿入不可
    return -1;
  }
  while(1){
    if(data[i].nodedata!=-1){
      num++;
      if(num==no){
        if(no==1){
          data[blank].nodedata=insdata;
          data[blank].nextindex=head;
          head=blank;
        }else{
          data[blank].nodedata=insdata;
          data[blank].nextindex=data[pre].nextindex;
          data[pre].nextindex=blank;
        }
        return 0;
      }
    }
    pre=i;
    i=data[i].nextindex;
    if(data[i].nextindex==-1){
      return -1;
    }
  }
}

int DeleteNode(int no,LIST data[])
{
  int num=0,i=head,pre=-1;
  if(no<0){
    return -1;
  }
  while(1){
    if(data[i].nodedata!=-1){
      num++;
      if(no==num){
        if(no==1){
          head=data[i].nextindex;
          data[i].nodedata=-1;
          data[i].nextindex=-1;
        }else{
          data[pre].nextindex=data[i].nextindex;
          data[i].nodedata=-1;
          data[i].nextindex=-1;
        }
        return 0;
      }
    }
    pre=i;
    i=data[i].nextindex;
    if(i==-1){
      return -1;
    }
  }
}

int getNode(int no,LIST data[])  //本来は表示できない場所が表示される　修正
{
  int num=0,i=head;
  int ans;
  if(no<0){
    return -1;
  }
  while(1){
    if(data[i].nodedata!=-1){
      num++;
      if(no==num){
        ans=data[i].nodedata;
        return 0;
      }
    }
    i=data[i].nextindex;
    if(num==MAX){
      return -1;
    }
  }
}
