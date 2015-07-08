/*
 * main.c
 *
 *  Created on: 2015年6月21日
 *      Author: lixin
 */

#include "apue.h"
#include "linearlist.h"
#include "matrix.h"

int linearlist_test();
BOOL increment(ELE_TYPE *e);

int main()
{
	//int flag = linearlist_test();
	matrixdemo1();

	return 0;
}

int linearlist_test()
{
	linearlist *ll = (linearlist *)calloc(1, sizeof(linearlist));

	STATUS status = init_list(ll);

	if(status != SUCC){
		printf("初始化线性表失败 \n");
		return -1;
	}

	append_list(ll, 1);
	append_list(ll, 2);
	append_list(ll, 3);
	insert_list(ll, 2, 10);
	append_list(ll, 100);

	//遍历线性表
	if(!empty_list(ll)){
		int _i = 0;
		for(; _i<ll->length; _i++){
			printf( "list[%d] = %d \n", _i, *(ll->elem+_i) ) ;
		}
	}

	BOOL flag = traverse_list(ll, increment);
	if(flag)	printf("all complte \n");
	else	printf("someone not invoke, please check \n");
	//遍历线性表
	if(!empty_list(ll)){
		int _i = 0;
		for(; _i<ll->length; _i++){
			printf( "list[%d] = %d \n", _i, *(ll->elem+_i) ) ;
		}
	}

	/*

	int del_index = 3;
	ELE_TYPE r;

	status = delete_list(ll, del_index, &r);

	if(status == SUCC){
		printf("delete index %d ok , the value is %d \n", del_index, r);
		//遍历线性表
		if(!empty_list(ll)){
			int _i = 0;
			for(; _i<ll->length; _i++){
				printf( "list[%d] = %d \n", _i, *(ll->elem+_i) ) ;
			}
		}
	}

	*/

	/*

	ELE_TYPE r , search = 100;
	BOOL flag = prior_elem(ll, search, &r) ;
	if(flag)
		printf("%d prev is %d \n", search, r);
	else
		printf("not found or first point %d \n", search);

	search = 2;
	flag = next_elem(ll, search, &r);
	if(flag)
		printf("%d next is %d \n", search, r);
	else
		printf("not found or last point %d \n", search);

	*/

	/*

	//获取一个元素
	ELE_TYPE val = 0;
	BOOL flag = get_item_list(ll, 2, &val);
	if(flag){
		printf("%d \n", val);
	}

	*/

	//clear_list(ll);

	/*

	//获取某值在线性表中首次出现位置
	ELE_TYPE search = 20;
	printf("please entry a integer : ");
	scanf("%d", &search);

	int f_index = locate_elem(ll, search, compare_callback);

	if(f_index!=0){
		printf("%d locate is %d \n", search, f_index);
	}else{
		printf("%d not found \n", search);
	}

	*/

	destory_list(ll);

	return 0;
}

BOOL increment(ELE_TYPE *e){

	if(*e == 100)	return FALSE;

	*e += 10;
	return TRUE;
}

