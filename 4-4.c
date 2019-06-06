#include<stdio.h>
#define N 15
int get_length(char word[]);
int main()
{
  int num[N]={0};
  char word[16];
  int i=0,word_length;
  while(1){
    printf("%d番目の英単語を入力してください(15文字以内)：\n",i+1);
    printf("-->  ");
    scanf("%s",word);
    if(word[0]=='*'){
      break;
    }else{
      word_length=get_length(word);
      num[word_length-1]++;
    }
    i++;
  }
  printf("文字数  出現回数\n");
  for(i=0;i<N;i++){
    printf("%d      %d\n",i+1,num[i]);
  }
  return 0;
}

int get_length(char word[])
{
  int i=0;
  while(word[i]!='\0'){
    i++;
  }
  return i;
}
