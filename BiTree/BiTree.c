#include "apue.h"
#include "BiTree.h"


//初始化空二叉树
int InitBiTree(BiTree *T){
    
    *T = malloc(sizeof(BiTNode));
    
    BiTNode tmp = {0, NULL, NULL, NULL} ;
    
    memcpy(*T, &tmp, sizeof(BiTNode));
    
    
    (*T)->data = 0 ;
    (*T)->parent = NULL;
    (*T)->lchild = NULL;
    (*T)->rchild = NULL;
    
    
    return 1;
}


int InsertChild(BiTree T, BiTree p, LR lr, BiTree c){
    //校验节点是否存在
    
    //插入节点
    if(lr==LEFT){
        //左子树
        BiTree tmp = p->lchild ;
        p->lchild = c ;
        c->rchild = tmp ;
    }else{
        //右子树
        BiTree tmp = p->rchild ;
        p->rchild = c ;
        c->rchild = tmp ;
    }
    
    return 1;
}


int InOrderTraverse(BiTree T, int (* Visit)(TElemType e)){
    
    if(T->lchild!=NULL){
        InOrderTraverse(T->lchild, Visit) ;
    }
    
    if(!Visit(T->data))
        return 0;
    
    if(T->rchild!=NULL){
        InOrderTraverse(T->rchild, Visit) ;
    }
    
    return 1;
}