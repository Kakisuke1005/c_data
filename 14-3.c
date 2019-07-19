#include<stdio.h>

#define NUM 10

typedef struct{
  int id;
  char name[20];
  int jap;
  int math;
  int eng;
}STUDENT;

int search(STUDENT a[],int key);

int main()
{
  STUDENT person[]={
    {6101,"Erika",98,76,85},{6102,"Fumiyasu",47,88,91},
    {6103,"Rika",56,90,78},{6104,"Shoya",65,76,83},
    {6105,"Sho",79,73,82},{6106,"Tatsuya",89,48,90},
    {6107,"Kazunori",68,77,85},{6108,"Katsuhiro",91,65,59},
    {6109,"Tomohiro",79,62,89},{6110,"Masato",85,88,79}};
  int index,key;
  printf("学生番号を入力してください：");
  scanf("%d",&key);
  index=search(person,key);
  if(index==-1){
    printf("その番号の学生はいません\n");
  }else{
    printf("%sさん(%d)の成績は，国語%d点，数学%d点，英語%d点，合計%d点です\n",person[index].name,person[index].id,person[index].jap,person[index].math,person[index].eng,person[index].jap+person[index].math+person[index].eng);
  }
  return 0;
}

int  search(STUDENT a[],int key)
{
  int pl=0;
  int pr=NUM-1;
  int pc;
  while(1){
    if(pl>pr){
      return -1;
    }
    pc=(pl+pr)/2;
    if(a[pc].id<key){
      pl=pc+1;
    }else if(a[pc].id>key){
      pr=pc-1;
    }else if(a[pc].id==key){
      return pc;
    }
  }
}
