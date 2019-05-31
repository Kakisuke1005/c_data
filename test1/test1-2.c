#include<stdio.h>
typedef struct{
  int id;
  char name[20];
  double height;
  double weight;
}STUDENT;

int main()
{
  STUDENT gakusei[4];
  FILE *fp;
  int i;
  double std_weight[4];
  double weight_difference[4];
  for(i=0;i<4;i++){
    printf("%d人目の学生番号は（6桁）?:",i+1);
    scanf("%d",&gakusei[i].id);
    printf("氏名は? :");
    scanf("%s",gakusei[i].name);
    printf("身長(cm)は? :");
    scanf("%lf",&gakusei[i].height);
    printf("体重(kg)は? :");
    scanf("%lf",&gakusei[i].weight);
    std_weight[i]=(gakusei[i].height/100)*(gakusei[i].height/100)*22.0;
    weight_difference[i]=gakusei[i].weight-std_weight[i];
  }
  printf("\nファイルtest.datに出力します。\n");
  fp=fopen("test.dat","w");
  for(i=0;i<4;i++){
    fprintf(fp,"%d %s %.1f %.1f %.1f\n",gakusei[i].id,gakusei[i].name,gakusei[i].height,gakusei[i].weight,weight_difference[i]);
  }
  fclose(fp);
  return 0;
}
