#include<stdio.h>
#include<stdlib.h>

#define MAX 2000
#define FMAX 20

void swap(int *x, int *y);
void quick(int a[],int left,int right);
int bin_search(int a[],int n,int key);
int lin_search(int a[],int m,int key);

int main(void)
{
  int i;
  int seisu[MAX];
  int kosu,ky,idx0,idx1;
  char fname[FMAX];
  FILE *fp;
  kosu=MAX;
  printf("Input file name:");
  scanf("%s",fname);
  fp=fopen(fname,"r");
  if(fp==NULL){
    printf("No file found!\n");
    exit(1);
  }
  for(i=0;i<kosu;i++){
    fscanf(fp,"%d",&seisu[i]);
  }
  printf("Number to search:");
  scanf("%d",&ky);
  idx0=lin_search(seisu,kosu,ky);  //線形探索を行いidx0に格納
  quick(seisu,0,kosu);
  idx1=bin_search(seisu,kosu,ky);  //二分探索を行いidx1に格納
  printf("線形探索にかかった計算回数：%d\n",idx0);
  printf("二分探索にかかった計算回数：%d\n",idx1);
  fclose(fp);
  return 0;
}

void swap(int *x, int *y)
{
  int tmp=*x;
  *x=*y;
  *y=tmp;
}

void quick(int a[],int left,int right)
{
  int pl,pr,pivot;
  pl=left;
  pr=right;
  pivot=a[(pl+pr)/2];
  do{
    while(a[pl]<pivot){
      pl++;
    }
    while(a[pr]>pivot){
      pr--;
    }
    if(pl<=pr){
      swap(&a[pl],&a[pr]);
      pl++;
      pr--;
    }
  }while(pl<=pr);
  if(left<pr){
    quick(a,left,pr);
  }
  if(pl<right){
    quick(a,pl,right);
  }
}

int bin_search(int a[],int n,int key)
{
  int pl,pr,pc;
  int count=0;
  pl=0;
  pr=n-1;
  while(1){
    if(pl>pr){
      return -1;
    }
    pc=(pl+pr)/2;   
    if(a[pc]<key){
      count++;
      pl=pc+1;
    }else if(a[pc]>key){
      count++;
      pr=pc-1;
    }else if(a[pc]==key){
      count++;
      return count;
    }
  }
}

int lin_search(int a[],int n,int key)
{
  int i=0;
  while(1){
    if(i==n){
      return -1;
    }
    if(a[i]==key){
      return i+1;
    }
    i++;
  }
}
