#include<stdio.h>
int find(char *s,char c);
int main()
{
  char name[]="NihonUniversity";
  char *str;
  int i,num;
  num=find(name,' ');
  switch(num){
  case -1:
    printf("スペース記号は見つかりませんでした\n");
    break;
  default:
    printf("%d文字目に見つかりました！\n",num);
    str=(char*)malloc(7*sizeof(char));
    for(i=0;i<num;i++){
      str[i]=name[i];
    }
    str[num]='\0';
    printf("%s\n",str);
    free(str);
    break;
  }
  return 0;
}

int find(char *s ,char c)
{
  int num=0,i=0;
  while(*s!='\0'){
    i++;
    if(*s==c){
      num=i;
      break;
    }
    s++;
  }
  if(num!=i){
    num=-1;
  }
  return num;
}
