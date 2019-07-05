#include<stdio.h>
#include<stdlib.h>

#define STACK_SIZE 5
#define QUEUE_SIZE 5
#define NO_DATA -1

int Push(int data);
int Pop();
void Show_Stack();
int Enqueue(int data);
int Dequeue();
void Show_Queue();

int stack[STACK_SIZE],queue[QUEUE_SIZE];
int sp=-1;
int front=-1;
int rear=-1;
int num=0;

int main()
{
  int ctrl,data,id,id2;
  for(int i=0;i<STACK_SIZE;i++){
    stack[i]=NO_DATA;
  }
  for(int i=0;i<QUEUE_SIZE;i++){
    queue[i]=NO_DATA;
  }
  while(1){
    printf("(1) Push  (2) Pop  (3) Enq (4) Deq (5) Push(Deq)  (6) Enq(Pop)  (0) Exit :");
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
	Show_Stack();
      }
      break;
    case 2:
      id=Pop();
      if(id==-1){
	printf("Stack Empty!\n");
	printf("Stack Pop is failed!\n");
      }else{
	printf("Pop data is %d\n",id);
	Show_Stack();
      }
      break;
    case 3:
      printf("Data:");
      scanf("%d",&data);
      id=Enqueue(data);
      if(id==-1){
	printf("Queue is Full!\n");
	printf("Enqueue is failed!\n");
      }else{
	Show_Queue();
      }
      break;
    case 4:
      id=Dequeue();
      if(id==-1){
	printf("Queue is Empty!\n");
	printf("Dequeue is failed!\n");
      }else{
	printf("Dequeue data is %d\n",id);
	Show_Queue();
      }
      break;
    case 5:
      id=Dequeue();
      if(id==-1){
	printf("Queue is Empty!\n");
	printf("Dequeue is failed!\n");
      }else{
	printf("Dequeue data is %d\n",id);
	Show_Queue();
	id2=Push(id);
	if(id2==-1){
	  printf("Stack Overflow!\n");
	  printf("Stack Push is failed!\n");
	  id2=Enqueue(id);
	}else{
	  Show_Stack();
	}
      }
      break;
    case 6:
      id=Pop();
      if(id==-1){
	printf("Stack Empty!\n");
	printf("Stack Pop is failed!\n");
      }else{
	printf("Pop data is %d\n",id);
	Show_Stack();
	id2=Enqueue(id);
	if(id2==-1){
	  printf("Queue is Full!\n");
	  printf("Enqueue is failed!\n");
	  id2=Push(id);
	}else{
	  Show_Queue();
	}
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

void Show_Stack()
{
  printf("Stack : ");
  for(int i=0;i<=sp;i++){
    if(stack[i]!=-1){
      printf("[%d]",stack[i]);
    }
  }
  printf("\n");
}


int Enqueue(int data)
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

int Dequeue()
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

void Show_Queue()
{
  printf("Queue : ");
  for(int i=0;i<QUEUE_SIZE;i++){
    if(queue[i]!=-1){
      printf("[%d]",queue[i]);
    }else{
      printf("[   ]");
    }
  }
  printf("\n");
}
