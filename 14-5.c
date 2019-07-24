#include<stdio.h>
#include<string.h>

#define NO_DATA -1
#define STACK_SIZE 20

int push(int data);
int pop();
void swap(int *a,int *b);

int stack[STACK_SIZE];
int sp=-1; //スタックポインタ

int main()
{
	char stack_poland[STACK_SIZE];
	int i;
	int num,ans;
	int length;
	for(i=0;i<STACK_SIZE;i++){
		stack[i]=NO_DATA;
	}
	printf("逆ポーランド記法で記述された数式を入力してください\n");
	scanf("%s",stack_poland);
	length=strlen(stack_poland);
	i=0;
	while(1){
		switch(stack_poland[i]){
			case '+':
				ans=pop()+pop();
				push(ans);
			break;
			case '-':
				swap(&stack[sp],&stack[sp-1]);
				ans=pop()-pop();
				push(ans);
			break;
			case '*':
				ans=pop()*pop();
				push(ans);
			break;
			default:
				num=stack_poland[i]-'0';
				push(num);
			break;
		}
		i++;
		if(i==length){
			break;
		}
	}
	printf("計算結果 = %d\n",pop());
	return 0;
}

int push(int data)
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

int pop()
{
	int data;
	if(sp<0){
		return 0;
	}else{
		data=stack[sp];
		sp--;
		return data;
	}
}

void swap(int *a,int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
