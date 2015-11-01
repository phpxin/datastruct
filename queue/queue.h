typedef int QElemType ;

typedef struct QNode{
    QElemType data ;
    struct QNode *next;
}QNode;

typedef struct {
    QNode *headptr; //队头指针
    QNode *tailptr; //队尾指针
    size_t length;
}Queue;

// 构造队列
int InitQueue(Queue *q) ;

// 销毁队列
int DestoryQueue(Queue *q) ;

// 清空队列
int ClearQueue(Queue *q) ;

// 是否空队列
int EmptyQueue(Queue *q) ;

// 队列长度（元素个数）
size_t QueueLength(Queue *q) ;

// 返回队列头元素
int GetHead(Queue *q, QElemType *e);

// 加入队列（在表尾插入新元素）
int EnQueue(Queue *q, QElemType e);

// 离开队列（删除表头元素，并返回）
int DeQueue(Queue *q, QElemType *e);

// 为每个元素执行函数 n
