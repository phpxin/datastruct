/*
 * matrix.c
 *
 *  Created on: 2015年7月2日
 *      Author: lixin
 */

#include "apue.h"
#include "matrix.h"

/**
 * 对称矩阵压缩
 */
void matrixdemo1()
{
	int a[MATRIXL][MATRIXL] = {{0},{0},{0},{0}};

	//创建一个4阶对称矩阵

	int i,j,k=5;

	for(i=1; i<=MATRIXL; i++){
		for(j=1; j<=MATRIXL; j++){
			if(a[i-1][j-1]>0)	continue;
			int _kk = k;
			a[i-1][j-1] = _kk;
			a[j-1][i-1] = _kk;
			k = k+1;
		}
	}

	for(i=1; i<=MATRIXL; i++){
		for(j=1; j<=MATRIXL; j++){
			printf("%d\t",a[i-1][j-1]);
		}
		printf("\n");
	}

	//矩阵压缩 n(n+1)/2 个元的空间

	int space_len = (MATRIXL*(MATRIXL+1))/2 ;
	printf("%d \n", space_len);

	int *cmp = (int *)calloc(space_len, sizeof(int));

	k=0;	//矩阵压缩临时下标

	for(i=1; i<=MATRIXL; i++){
		for(j=1; j<=MATRIXL; j++){
			if(i>=j){
				k = ((i*(i-1))/2)+j-1;
			}else{
				k = ((j*(j-1))/2)+i-1;
			}
			printf("k = %d \n", k);
			cmp[k] = a[i-1][j-1];
		}
	}

	//打印压缩后的矩阵
	for(i=0; i<space_len; i++){
		printf("cmp[%d] = %d\n", i, cmp[i]);
	}
	printf("\n");

	free(cmp);
}
