#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

int InitStack(SqStack *s)
{
    s->base = (SElemType *) malloc( STACK_INIT_SIZE * sizeof(SElemType) );    
    if(!s->base)    return -1 ;
    
    memset(s->base, '\0', STACK_INIT_SIZE * sizeof(SElemType));
    
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE ;

    return 1;
}


int DestoryStack(SqStack *s)
{
    if(s==NULL || s->base==NULL)    return 0;

    free(s->base);

    s->base = NULL;
    s->top = NULL;

    return 1;
}

int ClearStack(SqStack *s)
{
    memset(s->base, '\0', s->stacksize);
    s->top = s->base;

    return 1;
}


int EmptyStack(SqStack *s)
{
    if(s->base == s->top)
        return 1;

    return 0;
}


int GetTop(SqStack *s, SElemType *e)
{
    if(s->base == s->top)
        return 0; //empty stack

    *e = *(s->top) ;

    return 1;
}

int Push(SqStack *s, SElemType e)
{
    if(s->top - s->base >= s->stacksize){
        s->base = (SElemType *) realloc( s->base, (s->stacksize + STACK_INCR) * sizeof(SElemType) );
        if(!s->base)    return -1;
        s->top = s->base + s->stacksize ;

        s->stacksize += STACK_INCR ;
    }
        
    *(++s->top) = e; 
    

    return 1;
}

int Pop(SqStack *s, SElemType *e)
{
    if(s->base == s->top)
        return 0; //empty stack

    *e = *(s->top);

    s->top-- ;

    return 1;
}

