// 二叉树
typedef int TElemType ;
typedef enum  { LEFT=0, RIGHT=1 } LR;

typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild, *rchild, *parent;
} BiTNode, *BiTree;

//初始化空二叉树
int InitBiTree(BiTree *T);

//销毁二叉树
int DestroyBiTree(BiTree *T);

//构造二叉树
int CreateBiTree(BiTree T);

//清空二叉树
int ClearBiTree(BiTree T);

//二叉树是否为空树
int BiTreeEmpty(BiTree  T);

//二叉树深度
int BiTreeDepth(BiTree T);

//结节点赋值
int Assign(BiTree T, BiTree e, TElemType value);

//返回节点双亲
BiTree Parent(BiTree T, BiTree e);

//返回节点左子树
BiTree LeftChild(BiTree T, BiTree e);

//返回节点右子树
BiTree RightChild(BiTree T, BiTree e);

//插入子节点
int InsertChild(BiTree T, BiTree p, LR lr, BiTree c);

//中根序遍历二叉树 l p r
int InOrderTraverse(BiTree T, int (* Visit)(TElemType e));
