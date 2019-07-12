#include<stdio.h>

int search(int x[],int key,int center[]);

int main()
{
  int x[]={1,2,4,5,6,7,9,10,11,13,15,16,17,18,19,20,22,24,27,29};
  int key[]={13,22,0};
  int pc[5];
  int id;
  for(int i=0;i<3;i++){
    for(int j=0;j<5;j++){
      pc[j]=-1;
    }
    id=search(x,key[i],pc);
    printf("探索する値->%d\n",key[i]);
    printf("中央のインデックス->");
    for(int j=0;j<5;j++){
      if(pc[j]!=-1){
	printf("%d ",pc[j]);
      }else{
	break;
      }
    }
    printf("\n");
    if(id==-1){
      printf("探索失敗\n");
    }else{
      printf("インデックス->%d\n",id);
    }
    printf("\n");
  }
  return 0;
}

int search(int x[],int key,int center[])
{
  int pl=0;
  int pr=19;
  int pc;
  int i=0;
  while(1){
    if(pl>pr){
      return -1;
    }
    pc=(pl+pr)/2;
    center[i]=pc;
    i++;
    if(x[pc]<key){
      pl=pc+1;
    }else if(x[pc]>key){
      pr=pc-1;
    }else if(x[pc]==key){
      return pc;
    }
  }
}
