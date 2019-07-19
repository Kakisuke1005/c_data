#include<stdio.h>
#include<stdlib.h>

typedef struct{
  char name[20];
  int population;
  int area;
  double population_density;
}PREFECTURE;

int main()
{
  FILE *fp;
  PREFECTURE x[4];
  for(int i=0;i<4;i++){
    printf("%d番目の都道府県名は？：",i+1);
    scanf("%s",x[i].name);
    printf("人口は？：");
    scanf("%d",&x[i].population);
    printf("面積(km2)は？：");
    scanf("%d",&x[i].area);
    x[i].population_density=(double)x[i].population/x[i].area;
  }
  printf("\nファイルtest.txtに出力します\n");
  fp=fopen("test.txt","w");
  for(int i=0;i<4;i++){
    fprinf("%s %d %d %f\n",x[i].name,x[i].population,x[i].area,x[i].population_density);
  }
  fclose(fp);
  return 0;
}
