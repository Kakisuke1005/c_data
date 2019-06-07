#include<stdio.h>
#include<string.h>
typedef struct{
  char name[30];
  double height;
  double weight;
}STUDENT;

void insertion(STUDENT gakusei[],int num);

int main()
{
  STUDENT gakusei[]={
    {"阿部",178.5,72.4},
    {"佐藤",168.8,55.5},
    {"鈴木",163.5,82.3},
    {"高橋",185.0,76.5},
    {"田中",175.1,64.2},
    {"友近",172.3,68.2},
    {"中島",179.7,77.1},
    {"原田",182.1,69.3},
    {"安田",174.5,58.8},
    {"渡辺",176.3,65.6}
  };
  int i;
  insertion(gakusei,10);
  for(i=0;i<10;i++){
    printf("%s：%f %f\n",gakusei[i].name,gakusei[i].height,gakusei[i].weight);
  }
  return 0;
}

void insertion(STUDENT gakusei[],int num)
{
  STUDENT tmp;
  int i,j;
  for(i=1;i<num;i++){
    strcpy(tmp.name,gakusei[i].name);
    tmp.height=gakusei[i].height;
    tmp.weight=gakusei[i].weight;
    for(j=i-1;j>=0;j--){
      if(gakusei[j].height>tmp.height){
	strcpy(gakusei[j+1].name,gakusei[j].name);
	gakusei[j+1].height=gakusei[j].height;
	gakusei[j+1].weight=gakusei[j].weight;
      }else{
	break;
      }
    }
    strcpy(gakusei[j+1].name,tmp.name);
    gakusei[j+1].height=tmp.height;
    gakusei[j+1].weight=tmp.weight;
  }
}
