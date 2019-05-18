#include<stdio.h>
typedef struct{
  int id;
  char name[20];
  int math;
  int english;
  int japanese;
}STUDENT;

int main(){
  STUDENT student[5]={
    {306001,"阿部",82,72,90},
    {306051,"佐藤",68,50,62},
    {306101,"鈴木",42,65,52},
    {306151,"高橋",92,34,46},
    {306201,"渡辺",50,70,74}
  };
  int i;
  int sum[5]={0};
  int subject_sum[3]={0};
  double ave[3]={0};
  for(i=0;i<5;i++){
    sum[i]=student[i].math+student[i].english+student[i].japanese;
  }
  for(i=0;i<5;i++){
    subject_sum[0]+=student[i].math;
    subject_sum[1]+=student[i].english;
    subject_sum[2]+=student[i].japanese;
  }
  for(i=0;i<3;i++){
    ave[i]=(double)subject_sum[i]/5;
  }
  printf("成績リスト\n");
  printf("番号    氏名    数学    英語    国語    合計\n");
  for(i=0;i<5;i++){
    printf("%d  %s    %d点    %d点    %d点    %d点\n",student[i].id,student[i].name,student[i].math,student[i].english,student[i].japanese,sum[i]);
  }
  printf("平均点          %.1f点  %.1f点  %.1f点\n",ave[0],ave[1],ave[2]);
  return 0;
}
