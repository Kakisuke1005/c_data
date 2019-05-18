#include<stdio.h>
#include<math.h>
typedef struct{
  double x;
  double y;
}COORDINATES;
double get_distance(COORDINATES point[],int i);
int judge(double distance[]);
int main()
{
  COORDINATES point[3];
  double  distance[3]={0};
  double sum=0;
  int i,judgement;
  printf("XY座標面上の任意の3点を入力してください\n");
  for(i=0;i<3;i++){
    printf("%d点目\n",i+1);
    printf("X座標：");
    scanf("%lf",&point[i].x);
    printf("Y座標：");
    scanf("%lf",&point[i].y);
  }
  for(i=0;i<3;i++){
    distance[i]=get_distance(point,i);
    sum+=distance[i];
  }
  judgement=judge(distance);
  switch(judgement){
  case 1:
    printf("三角形の周囲は%.6fです\n",sum);
    break;
  case 2:
    printf("計算不能\n");
    break;
  }
  return 0;
}

double get_distance(COORDINATES point[],int i)
{
  double ans;
  switch(i){
  case 0:
  case 1:
    ans=sqrt((point[i].x-point[i+1].x)*(point[i].x-point[i+1].x)+(point[i].y-point[i+1].y)*(point[i].y-point[i+1].y));
    break;
  case 2:
    ans=sqrt((point[i].x-point[0].x)*(point[i].x-point[0].x)+(point[i].y-point[0].y)*(point[i].y-point[0].y));
    break;
  }
  return ans;
}

int judge(double distance[])
{
  int ans,i,j;
  double sum_distance[3]={0};
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      sum_distance[i]=sum_distance[i]+distance[j];
    }
    sum_distance[i]=sum_distance[i]-distance[i];
  }
  if((sum_distance[0]>distance[0])&&(sum_distance[1]>distance[1])&&(sum_distance[2]>distance[2])){
    ans=1;
  }else{
    ans=2;
  }
  return ans;
}