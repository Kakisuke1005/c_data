#include<stdio.h>
#define NUM 10

void insertion(int a[],int n);
int bin_search(int a[], int n,int key);

int main()
{
  int i,ky,idx;
  int x[NUM];
  printf("Input integer number %d times\n", NUM);
  for(i=0;i<NUM;i++){
    printf("x[%d]:",i);
    scanf("%d",&x[i]);
  }
  insertion(x,NUM);
  for(i=0;i<NUM;i++){   //ソート後の配列表示
    printf("%d ",x[i]);
  }
  printf("\n");
  printf("Number to search:");
  scanf("%d",&ky);
  idx=bin_search(x,NUM,ky);
  if(idx == -1){
    printf("Searching was failed!\n");
  }else{
    printf("%d is located at %d\n",ky,idx);
  }
  return 0;
}

void insertion(int a[],int n)
{
  int i,j,tmp;
  for(i=1;i<n;i++){
    tmp=a[i];
    for(j=i-1;j>=0;j--){
      if(a[j]>tmp){
	a[j+1]=a[j];
      }else{
	break;
      }
    }
    a[j+1]=tmp;
  }
}

int bin_search(int a[],int n,int key)
{
  int pl,pr,pc;
  pl=0;
  pr=n-1;
  while(1){
    if(pl>pr){
      return -1;
    }
    pc=(pl+pr)/2;
    if(a[pc]<key){
      pl=pc+1;
    }else if(a[pc]>key){
      pr=pc-1;
    }else if(a[pc]==key){
      return pc;
    }
  }
}
