#include<stdio.h>

typedef struct{
  char character;
  int count;
}INITIAL;

void quick(INITIAL a[],int left,int right);
void swap_num(int *a,int *b);
void swap_word(char *a,char *b);

int main()
{
  INITIAL num[25]={
    {'a',0},{'b',0},{'c',0},{'d',0},{'e',0},{'f',0},{'g',0},{'h',0},
    {'i',0},{'j',0},{'k',0},{'l',0},{'m',0},{'n',0},{'o',0},{'p',0},
    {'q',0},{'r',0},{'s',0},{'t',0},{'u',0},{'v',0},{'w',0},{'x',0},
    {'y',0}};
  char word[20];
  while(1){
    printf("英単語を入力してください：");
    scanf("%s",word);
    if(word[0]=='z'){
      break;
    }
    for(int i=0;i<25;i++){
      if(word[0]!='z'){
	if(num[i].character==word[0]){
	  num[i].count++;
	}
      }
    }
  }
  printf("出現回数順に出力します\n");
  quick(num,0,24);
  for(int i=0;i<25;i++){
    if(num[i].count!=0){
      printf("%c：%d回\n",num[i].character,num[i].count);
    }
  }
  return 0;
}

void quick(INITIAL a[],int left,int right)
{
  int pl=left;
  int pr=right;
  int pivot=a[(pl+pr)/2].count;
  do{
    while(a[pl].count>pivot){
      pl++;
    }
    while(a[pr].count<pivot){
      pr--;
    }
    if(pl<=pr){
      swap_num(&a[pl].count,&a[pr].count);
      swap_word(&a[pl].character,&a[pr].character);
      pl++;
      pr--;
    }
  }while(pl<=pr);
  if(left<pr){
    quick(a,left,pr);
  }
  if(right>pl){
    quick(a,pl,right);
  }
}

void swap_num(int *a,int *b)
{
  int tmp=*a;
  *a=*b;
  *b=tmp;
}

void swap_word(char *a,char *b)
{
  char tmp=*a;
  *a=*b;
  *b=tmp;
}
