#include<stdio.h>
#include<stdlib.h>
#include "bmp.h"

#define MAX_SIZE 256

int main()
{
	FILE *fp_in, *fp_out;
	int x,y;
	int width,height;
	char r[MAX_SIZE][MAX_SIZE];
  	char g[MAX_SIZE][MAX_SIZE];
  	char b[MAX_SIZE][MAX_SIZE];
	char r_out[MAX_SIZE][MAX_SIZE];
	char g_out[MAX_SIZE][MAX_SIZE];
	char b_out[MAX_SIZE][MAX_SIZE];

	//画像の黒い部分を赤にする

	//バイナリモードでファイルを開く
	fp_in=fopen("N.bmp","rb");
	if(fp_in==NULL){
		printf("Cannnot open the file!\n");
	}

	//ビットマップヘッダを読み込む
	readBMPHeader(fp_in,&height,&width);

	//画像データの読み込み
	for(y=0;y<height;y++){
		for(x=0;x<width;x++){
			fread(&b[y][x],sizeof(b[y][x]),1,fp_in);
			fread(&g[y][x],sizeof(g[y][x]),1,fp_in);
			fread(&r[y][x],sizeof(r[y][x]),1,fp_in);
		}
	}

	//画像データの加工
	for(y=0;y<height;y++){
		for(x=0;x<width;x++){
			if((r[y][x]==0)&&(g[y][x]==0)&&(b[y][x]==0)){
				r[y][x]=255;
			}
		}
	}

	//バイナリモードで書き込むファイルを開く
	fp_out=fopen("red.bmp","wb");

	//ビットマップヘッダの読み込み
	writeBMPHeader(fp_out,height,width);

	//画像データの書き込み
	for(y=0;y<height;y++){
    	for(x=0;x<width;x++){
      		fwrite(&b[y][x],sizeof(b[y][x]),1,fp_out);
      		fwrite(&g[y][x],sizeof(g[y][x]),1,fp_out);
      		fwrite(&r[y][x],sizeof(r[y][x]),1,fp_out);
    	}
  	}
	fclose(fp_in);
	fclose(fp_out);


	//左右反転処理

	//red.bmpをバイナリモードで読み込み
	fp_in=fopen("red.bmp","rb");
	if(fp_in==NULL){
		printf("Cannnot open the file!\n");
	}

	//ビットマップヘッダ読み込み
	readBMPHeader(fp_in,&height,&width);

	//画像データの読み込み
	for(y=0;y<height;y++){
		for(x=0;x<width;x++){
			fread(&b[y][x],sizeof(b[y][x]),1,fp_in);
			fread(&g[y][x],sizeof(g[y][x]),1,fp_in);
			fread(&r[y][x],sizeof(r[y][x]),1,fp_in);
		}
	}

	//画像データ反転の加工
	for(y=0;y<height;y++){
		for(x=0;x<width;x++){
			b_out[y][x]=b[y][width-x-1];
			g_out[y][x]=g[y][width-x-1];
			r_out[y][x]=r[y][width-x-1];
		}
	}

	//バイナリモードで書き込むファイルを開く
	fp_out=fopen("redMirror.bmp","wb");

	//ビットマップヘッダの書き込み
	writeBMPHeader(fp_out,height,width);

	//画像データの書き込み
	for(y=0;y<height;y++){
    	for(x=0;x<width;x++){
      		fwrite(&b_out[y][x],sizeof(b_out[y][x]),1,fp_out);
      		fwrite(&g_out[y][x],sizeof(g_out[y][x]),1,fp_out);
      		fwrite(&r_out[y][x],sizeof(r_out[y][x]),1,fp_out);
    	}
  	}
	fclose(fp_in);
	fclose(fp_out);
	return 0;
}