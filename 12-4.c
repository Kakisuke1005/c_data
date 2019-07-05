#include<stdio.h>
#include<stdlib.h>

#define STACK_SIZE 5
#define NO_DATA -1

int Push(int data);
int Pop();
void ShowStack();

int stack[STACK_SIZE];
int sp=-1;

int main()
{
  int i,ctrl,data,id;
  for(i=0;i<STACK_SIZE;i++){
    stack[i]=NO_DATA;
  }
  while(1){
    printf("(1) Push  (2) Pop  (0) Exit :");
    scanf("%d",&ctrl);
    switch(ctrl){
    case 1:
      printf("Data:");
      scanf("%d",&data);
      id=Push(data);
      if(id==-1){
	printf("Stack Overflow!\n");
	printf("Stack Push is failed!\n");
      }else{
	ShowStack();
      }
      break;
    case 2:
      id=Pop();
      if(id==-1){
	printf("Stack Empty!\n");
	printf("Stack Pop is failed!\n");
      }else{
	printf("Pop data is %d\n",id);
	ShowStack();
      }
      break;
    case 0:
      exit(0);
      break;
    }
  }
  return 0;
}

int Push(int data)
{
  sp++;
  if(sp>=STACK_SIZE){
    sp--;
    return -1;
  }else{
    stack[sp]=data;
    return 0;
  }
}

int Pop()
{
  if(sp<0){
    return -1;
  }else{
    sp--;
    return stack[sp+1];
  }
}

void ShowStack()
{
  int i;
  printf("Stack : ");
  for(i=0;i<=sp;i++){
    if(stack[i]!=-1){
      printf("[%d]",stack[i]);
    }
  }
  printf("\n");
}
