#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"


int InitQueue(Queue *q)
{
    q->headptr = q->tailptr = (QNode *)malloc(sizeof(QNode));
    q->headptr->next = NULL;

    return 1;
}

int DestoryQueue(Queue *q)
{
    ClearQueue(q) ;
    free(q->headptr) ;
    return 1;
}

int ClearQueue(Queue *q)
{
    QElemType tmp;

    while(!EmptyQueue(q)){
        DeQueue(q, &tmp);
    }
    return 1;
}

int EmptyQueue(Queue *q)
{
    if(q->headptr->next == NULL)
        return 1;

    return 0;
}

size_t QueueLength(Queue *q){
    return 1; 
}

int GetHead(Queue *q, QElemType *e)
{
    if(EmptyQueue(q))
        return 0;

    *e = q->headptr->data;

    return 1;
}

int EnQueue(Queue *q, QElemType e)
{
    QNode *node = (QNode *)malloc(sizeof(QNode));
    node->data = e;
    node->next = NULL;

    q->tailptr->next = node;
    
    q->tailptr = node;

    return 1;
}

int DeQueue(Queue *q, QElemType *e)
{
    if(EmptyQueue(q))  return 0;

    QNode *node = q->headptr->next ;
    *e = node->data;

    q->headptr->next = node->next;

    free(node) ;

    return 1;
}
