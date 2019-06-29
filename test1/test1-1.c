#include<stdio.h>

typedef struct{
  char name[20];
  int id;
  int english;
  int math;
  int physics;
}STUDENT;

int main()
{
  STUDENT gakusei[]={
    {"Abe",306001,80,73,44},
    {"Igarashi",306021,62,92,50},
    {"Sato",306041,82,77,61},
    {"Suzuki",306051,74,85,94},
    {"Takahashi",306061,76,54,87}
  };
  int sum[5]={0};
  int sum_subject[3]={0};
  int i,max,min;
  double ave;
  for(i=0;i<5;i++){
    sum[i]=gakusei[i].english+gakusei[i].math+gakusei[i].physics;
  }
  for(i=0;i<5;i++){
      sum_subject[0]+=gakusei[i].english;
      sum_subject[1]+=gakusei[i].math;
      sum_subject[2]+=gakusei[i].physics;
  }
  max=sum[0];
  for(i=1;i<5;i++){
    if(max<sum[i]){
      max=sum[i];
    }
  }
  min=sum[0];
  for(i=1;i<5;i++){
    if(min>sum[i]){
      min=sum[i];
    }
  }
    ave=(double)(sum[0]+sum[1]+sum[2]+sum[3]+sum[4])/5;
    for(i=0;i<5;i++){
      printf("%s (%d)の合計点は : %d点\n",gakusei[i].name,gakusei[i].id,sum[i]);
    }
    printf("---\n");
    printf("合計点の最高は : %d点\n",max);
    printf("合計点の最低は : %d点\n",min);
    printf("合計点の平均は : %.1f点\n",ave);
    printf("英語の平均点は : %.1f点\n",(double)sum_subject[0]/5);
    printf("数学の平均点は : %.1f点\n",(double)sum_subject[1]/5);
    printf("物理の平均点は : %.1f点\n",(double)sum_subject[2]/5);
    return 0;
  }
