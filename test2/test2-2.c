#include<stdio.h>
#include<string.h>

#define NUM 5

typedef struct{
  int id;
  char name[20];
  int math;
  int japa;
}STUDENT;

void quick_japa(STUDENT a[],int left,int right);
void swap(int *a,int *b);
void show_student(STUDENT a[]);

int main()
{
  STUDENT gakusei[NUM]={
    {101,"斉藤",76,80},
    {102,"田中",53,40},
    {103,"中野",81,90},
    {104,"松本",93,33},
    {105,"吉田",85,45}
  };
  printf("[ソート前]\n");
  show_student(gakusei);
  printf("\n");
  printf("[ソート後]\n");
  quick_japa(gakusei,0,NUM-1);
  for(int i=0;i<NUM;i++){
    if(gakusei[i].id==101){
      strcpy(gakusei[i].name,"斉藤");
    }else if(gakusei[i].id==102){
      strcpy(gakusei[i].name,"田中");
    }else if(gakusei[i].id==103){
      strcpy(gakusei[i].name,"中野");
    }else if(gakusei[i].id==104){
      strcpy(gakusei[i].name,"松本");
    }else if(gakusei[i].id==105){
      strcpy(gakusei[i].name,"吉田");
    }
  }
  show_student(gakusei);
  return 0;
}

void show_student(STUDENT a[])
{
  int i;
  printf("学生番号        名前    数学    国語\n");
  for(i=0;i<NUM;i++){
    printf("%d             %s    %d      %d\n",a[i].id,a[i].name,a[i].math,a[i].japa);
  }
}

void quick_japa(STUDENT a[],int left,int right)
{
  int pl=left;
  int pr=right;
  int pivot=a[(pl+pr)/2].japa;
  do{
    while(a[pl].japa>pivot){
      pl++;
    }
    while(a[pr].japa<pivot){
      pr--;
    }
    if(pl<=pr){
      swap(&a[pl].id,&a[pr].id);
      swap(&a[pl].math,&a[pr].math);
      swap(&a[pl].japa,&a[pr].japa);
      pl++;
      pr--;
    }
  }while(pl<=pr);
  if(left<pr){
    quick_japa(a,left,pr);
  }
  if(pl<right){
    quick_japa(a,pl,right);
  }
}

void swap(int *a,int *b)
{
  int tmp=*a;
  *a=*b;
  *b=tmp;
}
