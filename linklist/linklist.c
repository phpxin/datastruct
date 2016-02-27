// link list 链表结构
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linklist.h"


int init_llink(LLink *llink)
{
    llink->head = (struct _LNode *)calloc(1, sizeof(struct _LNode));
    llink->tail = (struct _LNode *)calloc(1, sizeof(struct _LNode));

    llink->head->prev = NULL;
    llink->head->next = llink->tail;
    llink->head->data = 0;

    llink->tail->prev = llink->head;
    llink->tail->next = NULL;
    llink->tail->data = 0;

    llink->len = 0;

    return 1;
}

int len_llink(LLink *llink)
{
    return llink->len;
}

int isempty_llink(LLink *llink)
{
    if (len_llink(llink)>0) {
        /* code */
        return 0 ;
    }
    return  1;
}

//添加数据
int append_data_llink(LLink *llink, EleType e)
{
    /* code */
    struct _LNode *node = (struct _LNode *)calloc(1, sizeof(struct _LNode));

    node->prev = llink->tail->prev ;
    node->next = llink->tail;
    node->data = e ;

    llink->tail->prev->next = node;
    llink->tail->prev = node;
    llink->len ++ ;

    return 1;
}

void foreach_llink(LLink *llink)
{
    if (isempty_llink(llink)) {
        /* code */
        printf("list is empty\n");
        return ;
    }

    LNode *node = llink->head->next ;

    while(node->next != NULL)
    {
        printf("%d \n", node->data);
        node = node->next ;
    }
}
