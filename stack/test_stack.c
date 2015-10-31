#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stack.h"

void test_conver() ;
void test_input() ;

int main(int argc, char *argv[])
{
    test_conver();

    return 0;
}

//测试程序：10-8 进制转换 
void test_conver()
{
    SqStack s = {NULL, NULL, 0};

    InitStack(&s) ;

    int Dec = 0;  /// conver to Oct

    printf("input a Dec number : ");
    scanf("%d", &Dec);

    int N = Dec;
    while(N){
        Push(&s, (SElemType)N%8);
        N = (int)(N/8);
    }    

    
    if(EmptyStack(&s))
    {
        printf("stack is empty \n");

    }else{
        SElemType e;
        printf("Oct = ");
        while(!EmptyStack(&s)){
            Pop(&s, &e);
            printf("%d", (int)e);
        }
        printf("\n");
    }
}

//测试程序：输入任意多数字，倒叙输出
void test_input()
{
    SqStack s = {NULL, NULL, 0};

    InitStack(&s) ;

    int input_n = 0;

    while(1)
    {
        printf("please input a int value , 0 stop : "); 
        scanf("%d", &input_n);
        if(input_n == 0)
        {
            break;
        }

        Push(&s, (SElemType)input_n);
    }


    if(EmptyStack(&s))
    {
        printf("stack is empty \n");

    }else{
        SElemType e;
        while(!EmptyStack(&s)){
            Pop(&s, &e);
            printf("value is %d \n", (int)e);
        }
    }

    DestoryStack(&s);    
}
