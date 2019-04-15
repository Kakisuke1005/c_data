#include<stdio.h>
void print_board(int board[15][15]);
void mark_board(int board[15][15], int turn);
void error_check(int board[15][15],int vertical,int horizon,int turn);
int judge(int board[15][15]);
int main()
{
  int turn=1,win;
  int board[15][15]={0};
  print_board(board);
  while(1){
    switch(turn){
    case 1:
      printf("先手の番です\n");
      break;
    case -1:
      printf("後手の番です\n");
      break;
    }
    mark_board(board,turn);
    print_board(board);
    win=judge(board);
    switch(win){
    case 1:
      printf("先手の勝ちです\n");
      return 0;
      break;
    case -1:
      printf("後手の勝ちです\n");
      return 0;
      break;
    case 0:
      break;
      case -2:
      printf("引き分けです\n");
      return 0;
      break;
    }
    switch(turn){
    case 1:
      turn=-1;
      break;
    case -1:
      turn=1;
      break;
    }
  }
  return 0;
}
 
void print_board(int board[15][15])
{
  int i,j;
  printf(" 012345678901234\n");
  for(i=0;i<15;i++){
    switch(i){
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
      printf("%d",i);
      break;
    case 10:
      printf("0");
      break;
    case 11:
      printf("1");
      break;
    case 12:
      printf("2");
      break;
    case 13:
      printf("3");
      break;
    case 14:
      printf("4");
      break;
    }
    for(j=0;j<15;j++){
      switch(board[i][j]){
      case 0:
    printf(" ");
    break;
      case 1:
    printf("o");
    break;
      case -1:
    printf("x");
    break;
      }
    }
    printf("\n");
  }
}
 
void mark_board(int board[15][15], int turn)
{
  int vertical,horizon;
  printf("縦位置は？");
  scanf("%d",&vertical);
  printf("横位置は？");
  scanf("%d",&horizon);
  error_check(board,vertical,horizon,turn);
}
 
void error_check(int board[15][15],int vertical,int horizon,int turn)
{
  int check;
  if((vertical>=15)||(horizon>=15)||(vertical<0)||(horizon<0)){
    check=2;
  }else if(board[vertical][horizon]!=0){
    check=2;
  }else{
    check=1;
  }
  switch(check){
  case 1:
    board[vertical][horizon]=turn;
    break;
  case 2:
    printf("そこには置けません\n");
    mark_board(board,turn);
    break;
  }
}
 
int judge(int board[15][15])
{
  int judge=0,zero_flag=0,i,j;
  for(i=0;i<11;i++){
    for(j=0;j<11;j++){
      if(((board[i][j]==1)&&(board[i][j+1]==1)&&(board[i][j+2]==1)&&(board[i][j+3]==1)&&(board[i][j+4]==1))||((board[i][j]==1)&&(board[i+1][j]==1)&&(board[i+2][j]==1)&&(board[i+3][j]==1)&&(board[i+4][j]==1))||((board[i][j]==1)&&(board[i+1][j+1]==1)&&(board[i+2][j+2]==1)&&(board[i+3][j+3]==1)&&(board[i+4][j+4]==1))){
	judge=1;
	break;
      }else if(((board[i][j]==-1)&&(board[i][j+1]==-1)&&(board[i][j+2]==-1)&&(board[i][j+3]==-1)&&(board[i][j+4]==-1))||((board[i][j]==-1)&&(board[i+1][j]==-1)&&(board[i+2][j]==-1)&&(board[i+3][j]==-1)&&(board[i+4][j]==-1))||((board[i][j]==-1)&&(board[i+1][j+1]==-1)&&(board[i+2][j+2]==-1)&&(board[i+3][j+3]==-1)&&(board[i+4][j+4]==-1))){
	judge=-1;
	break;
      }
    }
  }
  for(i=14;i>=0;i--){
    for(j=0;j<15;j++){
      if((board[i][j]==1)&&(board[i-1][j+1]==1)&&(board[i-2][j+2]==1)&&(board[i-3][j+3]==1)&&(board[i-4][j+4]==1)){
	judge=1;;
	break;
      }else if((board[i][j]==-1)&&(board[i-1][j+1]==-1)&&(board[i-2][j+2]==-1)&&(board[i-3][j+3]==-1)&&(board[i-4][j+4]==-1)){
	judge=-1;
	break;
      }
    }
  }
  for(i=0;i<15;i++){
    for(j=0;j<15;j++){
      if(board[i][j]== 0) {
	zero_flag=1;
      }
    }
  }
  if((judge==0)&&(zero_flag==0)){
    judge=-2;
  }
  return judge;
}
