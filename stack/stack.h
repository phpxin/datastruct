/* 数据结构 - 栈 */

#define STACK_INIT_SIZE 100         //存储空间初始分配量
#define STACK_INCR      10          //存储空间分配增量

typedef int SElemType ;

typedef struct {
    SElemType *base;                //在栈构造前和析构后，base为null
    SElemType *top;                 //栈顶指针
    int stacksize;                  //当前已分配的存储空间，以元素为单位
}SqStack ;

// 构造一个空栈
int InitStack(SqStack *s) ;

// 销毁一个栈
int DestoryStack(SqStack *s) ;

// 清空栈
int ClearStack(SqStack *s) ;

// 栈s是否为空栈
int EmptyStack(SqStack *s) ;

// 返回元素的个数（栈的长度）
int StackLength(SqStack *s) ;

// 获取栈顶元素
int GetTop(SqStack *s, SElemType *e) ;

// 入栈
int Push(SqStack *s, SElemType e) ;

// 出栈 : 删除栈顶元素，并用e返回其值
int Pop(SqStack *s, SElemType *e) ;
