// link list 链表结构
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <linklist.h>


int init_llink(LLink *llink)
{
    llink = (LLink *)calloc(sizeof(LLink), 1);
    llink->head = (LNode *)calloc(sizeof(LNode), 1);
    llink->tail = (LNode *)calloc(sizeof(LNode), 1);

    llink->head->prev = NULL;
    llink->head->next = NULL;

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

int add_data_llink(LLink *llink, EleType data)
{
    //if(len_l)
    if (isempty_llink(llink)) {
        /* code */
        return 0;
    }
}
