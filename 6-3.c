#include<stdio.h>
#include<stdlib.h>
int main()
{
  int year,month,day,age;
  double height,weight;
  char family_name[30],name[30];
  FILE *fp;
  fp=fopen("kadai2.txt","r");
  if(fp==NULL){
    printf("Cannot open the file\n");
    exit(1);
  }
  fscanf(fp,"%d %d %d",&year,&month,&day);
  fscanf(fp,"%lf %lf",&height,&weight);
  fscanf(fp,"%s %s",family_name,name);
  fclose(fp);
  if((month>=5)&&(day>=24)){
    age=2019-year;
  }else{
    age=2019-year-1;
  }
  printf("氏名は %s  %sです\n",family_name,name);
  printf("生年月日は%d年%d月%d日です（%d歳）\n",year,month,day,age);
  printf("身長は%.1f cm  体重は%.1f kgです\n",height,weight);
  return 0;
}

  
