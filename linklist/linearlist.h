/*
 * linearlist.h
 *
 *  Created on: 2015年6月21日
 *      Author: lixin
 */

#ifndef LINEARLIST_H_
#define LINEARLIST_H_

#include "apue.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ELE_TYPE ;

typedef struct {
	ELE_TYPE	*elem ;
	int			length ;
	int 		listsize ;
}linearlist ;

/**
 * 返回第一个与callback符合的元素
 */
int locate_elem(linearlist *list, ELE_TYPE e, int (* callback)(ELE_TYPE, ELE_TYPE)) ;

/**
 * 获取e的前驱
 */
BOOL prior_elem(linearlist *list, ELE_TYPE e, ELE_TYPE *e_pre) ;

/**
 * 获取e的后继
 */
BOOL next_elem(linearlist *list, ELE_TYPE e, ELE_TYPE *e_pre) ;

/**
 * 获取表长度
 */
int length_list(linearlist *list) ;

/**
 * 创建线性表
 */
STATUS init_list(linearlist *list) ;

/**
 * 销毁线性表
 */
STATUS destory_list(linearlist *list) ;

/**
 * 清空线性表
 */
STATUS clear_list(linearlist *list);

/**
 * 线性表是否为空
 */
BOOL empty_list(linearlist *list);

/**
 * 获取index位置元素
 */
BOOL get_item_list(linearlist *list, int index, ELE_TYPE *item) ;

/**
 * 追加数据到表尾
 */
STATUS append_list(linearlist *list, ELE_TYPE item) ;

/**
 * 插入数据到index位置
 */
STATUS insert_list(linearlist *list, int index, ELE_TYPE item) ;

/**
 * 删除index位置元素，并用e返回其值
 */
STATUS delete_list(linearlist *list, int index, ELE_TYPE *e) ;

/**
 * 对线性表每个元素调用callback函数
 */
BOOL traverse_list(linearlist *list, BOOL (* callback)(ELE_TYPE *e)) ;

/***** callback function ********/

int compare_callback(ELE_TYPE a, ELE_TYPE b);

#endif /* LINEARLIST_H_ */
