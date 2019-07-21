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
  double max;
  int max_index;
  for(int i=0;i<4;i++){
    printf("%d番目の都道府県名は？：",i+1);
    scanf("%s",x[i].name);
    printf("人口は？：");
    scanf("%d",&x[i].population);
    printf("面積(km2)は？：");
    scanf("%d",&x[i].area);
    x[i].population_density=(double)x[i].population/x[i].area;
    if((max<x[i].population_density)||(i==0)){
      max=x[i].population_density;
      max_index=i;
    }
  }
  printf("\nファイルtest.txtに出力します\n");
  fp=fopen("test.txt","w");
  for(int i=0;i<4;i++){
    fprintf(fp,"%s %d %d %.1f\n",x[i].name,x[i].population,x[i].area,x[i].population_density);
  }
  fprintf(fp,"最も人口密度が高いのは%sです\n",x[max_index].name);
  fclose(fp);
  return 0;
}
