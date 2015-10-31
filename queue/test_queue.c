#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "queue.h"

void test_input() ;

int main(int argc, char *argv[])
{
    test_input();

    return 0;
}



//测试程序：输入任意多数字，倒叙输出
void test_input()
{
    Queue q;

    InitQueue(&q);

    int input_n = 0;

    while(1)
    {
        printf("please input a int value , 0 stop : "); 
        scanf("%d", &input_n);
        if(input_n == 0)
        {
            break;
        }
        EnQueue(&q, (QElemType)input_n);
    }


    if(EmptyQueue(&q))
    {
        printf("queue is empty \n");

    }else{
        QElemType e;
        while(!EmptyQueue(&q)){
            DeQueue(&q, &e);
            printf("value is %d \n", (int)e);
        }
    }

    DestoryQueue(&q);    
}
