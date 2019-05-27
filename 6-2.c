#include<stdio.h>
#include<stdlib.h>
int main()
{
  int year,month,day;
  double height,weight;
  char family_name[30];
  char name[30];
  FILE *fp;
  fp=fopen("kadai2.txt","w");
  printf("誕生年:");
  scanf("%d",&year);
  printf("誕生月:");
  scanf("%d",&month);
  printf("誕生日:");
  scanf("%d",&day);
  fprintf(fp,"%d %d %d\n",year,month,day);
  printf("\n身長:");
  scanf("%lf",&height);
  printf("体重:");
  scanf("%lf",&weight);
  fprintf(fp,"%.6lf %.6lf\n",height,weight);
  printf("\n名字:");
  scanf("%s",family_name);
  printf("名前:");
  scanf("%s",name);
  fprintf(fp,"%s %s\n",family_name,name);
  fclose(fp);
  return 0;
}
