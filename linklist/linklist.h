/*
 * linklist.h
 * 双向链表结构
 *  Created on: 2015年6月22日
 *      Author: lixin
 */

#ifndef LINKLIST_H_
#define LINKLIST_H_

typedef int EleType ;

typedef struct _LNode{
	struct _LNode *prev, *next ;
	EleType data;
} LNode;

typedef struct  {
	LNode *head, *tail;
	int len;
} LLink;

int init_llink(LLink *llink) ;
int len_llink(LLink *llink) ;
int isempty_llink(LLink *llink) ;
int append_data_llink(LLink *llink, LNode *_node) ;
void foreach_llink(LLink *llink) ;

#endif /* LINKLIST_H_ */
