#include<stdio.h>
#define MAX 20

typedef struct{
  int nodedata;
  int nextindex;
}LIST;

void ShowList(LIST data[]);

int main()
{
  LIST data[MAX];
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
  ShowList(data);
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
