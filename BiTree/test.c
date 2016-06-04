#include "apue.h"
#include "BiTree.h"

int visit_test(TElemType e) ;

int main(int argc, char *argv[]){
    
    BiTree bi_tree = NULL;
    
    InitBiTree(&bi_tree) ;
    
    BiTree left = NULL ;
    InitBiTree(&left) ;
    left->data = 100 ;
    
    InsertChild(bi_tree, bi_tree, LEFT, left);
    
    BiTree right = NULL ;
    InitBiTree(&right) ;
    right->data = 200 ;
    
    InsertChild(bi_tree, bi_tree, RIGHT, right);
    
    InOrderTraverse(bi_tree, visit_test);
    //printf("%d\n", bi_tree->lchild->data);
    
    return 1;
}


int visit_test(TElemType e){
    printf("%d\n", e);
    return 1;
}