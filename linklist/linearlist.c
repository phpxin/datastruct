/*
 * linearlist.c
 *
 *  Created on: 2015年6月21日
 *      Author: lixin
 */

#include "apue.h"
#include "linearlist.h"

BOOL traverse_list(linearlist *list, BOOL (* callback)(ELE_TYPE *e))
{
	int _i = 0;
	BOOL flag = TRUE;

	for( ; _i<list->length; ++_i)
	{
		if(!callback(list->elem+_i)){
			flag = FALSE;
			break;
		}
	}
	return flag;
}

STATUS delete_list(linearlist *list, int index, ELE_TYPE *e)
{
	if(index<1 || index>list->length)	return ERR;
	BOOL flag = get_item_list(list, index, e);

	if(!flag)	return FALSE;

	//删除元素
	int _i=index-1;
	for( ; _i<list->length-1; _i++)
		*(list->elem+_i) = *(list->elem+_i+1);
	--list->length;

	return SUCC;
}

BOOL next_elem(linearlist *list, ELE_TYPE e, ELE_TYPE *e_pre)
{
	int e_index = locate_elem(list, e, compare_callback) ;

	if(e_index == 0 || e_index>=list->length)	return FALSE;

	return get_item_list(list, e_index+1, e_pre);
}

BOOL prior_elem(linearlist *list, ELE_TYPE e, ELE_TYPE *e_pre)
{
	int e_index = locate_elem(list, e, compare_callback) ;

	if(e_index <= 1)	return FALSE;

	return get_item_list(list, e_index-1, e_pre);
}

int length_list(linearlist *list)
{
	return list->length ;
}

int locate_elem(linearlist *list, ELE_TYPE e, int (* callback)(ELE_TYPE, ELE_TYPE))
{
	int index = 0;

	if(!empty_list(list)){
		int flag = -1;

		int _i = 0;
		for(; _i<list->length; _i++){
			//printf( "list[%d] = %d \n", _i, *(list->elem+_i) ) ;
			flag = (* callback)(e, *(list->elem+_i));
			if(flag == 0){
				index = _i+1;
				break;
			}
		}
	}

	return index;
}

STATUS clear_list(linearlist *list)
{
	memset(list->elem, '\0', list->listsize*sizeof(ELE_TYPE));
	list->length = 0;
	return SUCC;
}

BOOL empty_list(linearlist *list){
	if(list->length > 0){
		return FALSE;
	}

	return TRUE;
}

STATUS init_list(linearlist *list)
{
	list->elem = (ELE_TYPE *)malloc(LIST_INIT_SIZE*sizeof(ELE_TYPE)) ;
	if(!list->elem)
	{
		return ERR ;
	}
	list->length = 0 ;
	list->listsize = LIST_INIT_SIZE ;
	return SUCC ;
}

STATUS destory_list(linearlist *list)
{
	if(list == NULL){
		return FAIL ;
	}

	free(list->elem);
	list->elem = NULL;

	free(list);
	list = NULL;

	return SUCC ;
}

BOOL get_item_list(linearlist *list, int index, ELE_TYPE *item)
{
	if(index<1 || index>list->length+1)
		return FALSE ;
	//return (list->elem)[index];
	*item = (list->elem)[index-1];
	return TRUE ;
}

STATUS insert_list(linearlist *list, int index, ELE_TYPE item)
{
	if(index<1 || index>list->length+1)	return ERR ;

	if(list->length >= list->listsize)
	{
		list->elem = (ELE_TYPE *)realloc(list->elem, (list->listsize+LIST_INIT_SIZE)*sizeof(ELE_TYPE));
		list->listsize += LIST_INIT_SIZE;
	}

	if(list->length == 0){
		*(list->elem) = item ;
		return SUCC ;//如果为空表，必定为插入到位置0
	}

	//插入位置后面的元素向后移动
	ELE_TYPE *_q = list->elem+(index-1) ;
	ELE_TYPE *_p = list->elem+(list->length-1);
	for(; _p>=_q; --_p)
		*(_p+1) = *_p ;
	*_q = item ;

	++(list->length);

	return SUCC ;
}

STATUS append_list(linearlist *list, ELE_TYPE item)
{
	if(list->length >= list->listsize)
	{
		//realloc
		list->elem = (ELE_TYPE *)realloc(list->elem, (list->listsize+LIST_INIT_SIZE)*sizeof(ELE_TYPE));
		list->listsize += LIST_INIT_SIZE;
	}

	//appent to tail
	*(list->elem+list->length) = item ;

	++(list->length) ;
	return SUCC ;
}

/*******    callback funcs ********/


int compare_callback(ELE_TYPE a, ELE_TYPE b)
{
	if(a == b)	return 0;
	return -1;
}
