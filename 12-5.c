#include<stdio.h>
#include<stdlib.h>

#define QUEUE_SIZE 5
#define NO_DATA -1

int EnQueue(int data);
int DeQueue();
void ShowQueue();

int queue[QUEUE_SIZE];
int front=-1;
int rear=-1;
int num=0;

int main()
{
  int data,id,ctrl;
  for(int i=0;i<QUEUE_SIZE;i++){
    queue[i]=NO_DATA;
  }
  while(1){
    printf("(1) Enqueue (2) Dequeue (0) Exit :");
    scanf("%d",&ctrl);
    switch(ctrl){
    case 1:
      printf("Data:");
      scanf("%d",&data);
      id=EnQueue(data);
      if(id==-1){
	printf("Queue is Full!\n");
	printf("Enqueue is failed!\n");
      }else{
	ShowQueue();
      }
      break;
    case 2:
      id=DeQueue();
      if(id==-1){
	printf("Queue is Empty!\n");
	printf("Dequeue is failed!\n");
      }else{
	printf("Dequeue data is %d\n",id);
	ShowQueue();
      }
      break;
    case 0:
      exit(0);
      break;
    }
  }
  return 0;
}

int EnQueue(int data)
{
  if(num>=QUEUE_SIZE){
    return -1;
  }
  rear++;
  if(rear>=QUEUE_SIZE){
    rear=0;
  }
  queue[rear]=data;
  num++;
  return 0;
}

int DeQueue()
{
  int data;
  if(num<=0){
    return -1;
  }else{
    front++;
    if(front>=QUEUE_SIZE){
      front=0;
    }
    data=queue[front];
    queue[front]=NO_DATA;
    num--;
    return data;
  }
}

void ShowQueue()
{
  printf("Queue :");
  for(int i=0;i<QUEUE_SIZE;i++){
    if(queue[i]!=-1){
      printf("[%d]",queue[i]);
    }else{
      printf("[   ]");
    }
  }
  printf("\n");
}
