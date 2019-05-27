#include<stdio.h>
#include<stdlib.h>
typedef struct{
  int id;
  char name[35];
}STUDENT;
int main()
{
  int i;
  FILE *fp;
  STUDENT gakusei[3]={
    {306001,"sato"},
    {306002,"suzuki"},
    {306003,"tanaka"}
  };
  fp=fopen("kadai1.txt","w");
  for(i=0;i<3;i++){
    fprintf(fp,"学生番号:%d, 氏名:%s\n",gakusei[i].id,gakusei[i].name);
  }
  fclose(fp);
  return 0;
}
