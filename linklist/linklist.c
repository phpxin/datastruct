// link list 链表结构
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linklist.h"


int init_llink(LLink *llink)
{
    llink = (LLink *)calloc(sizeof(LLink), 1);
    llink->head = (LNode *)calloc(sizeof(LNode), 1);
    llink->tail = (LNode *)calloc(sizeof(LNode), 1);

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
int append_data_llink(LLink *llink, LNode *node)
{
    /* code */
    //LNode *node = (LNode *)calloc(sizeof(LNode), 1);
    //LNode *node = _node;

    LNode *prev = llink->tail->prev;

    node->prev = prev ;
    node->next = llink->tail;
    //node->data = data ;

    //prev->next = node;

    //llink->tail->prev = node;

    return 1;
}

void foreach_llink(LLink *llink)
{
    if (isempty_llink(llink)) {
        /* code */
        printf("list is empty");
        return ;
    }

    LNode *node = llink->head ;

    while(node->next != NULL)
    {
        printf("%d \n", node->data);
        node = node->next ;
    }
}
