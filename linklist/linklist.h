/*
 * linklist.h
 *
 *  Created on: 2015年6月22日
 *      Author: lixin
 */

#ifndef LINKLIST_H_
#define LINKLIST_H_

typedef void* EleType ;

typedef struct _LNode{
	struct _LNode *prev, *next ;
	EleType data;
} LNode;

typedef struct LLink {
	LNode *head, *tail;
	int len;
};

#endif /* LINKLIST_H_ */
