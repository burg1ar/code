#include"forTest.h"
void pairSwap(BiNode* bt){
    BiNode* tmp;
    if(bt){
        pairSwap(bt->lchild);
        pairSwap(bt->rchild);
        tmp=bt->lchild;
        bt->lchild=bt->rchild;
        bt->rchild=tmp;
    }
}
void pairSwap2(BiNode* bt){
    BiNode* tmp;
    if(bt){
        tmp=bt->lchild;
        bt->lchild=bt->rchild;
        bt->rchild=tmp;
        pairSwap(bt->lchild);
        pairSwap(bt->rchild);
    }
}
int main(){
    BiNode* bt;
    char arr[]={'1','#','2','#','#','3','4','#','#','#','#','#','5'};
    build_tree(bt,arr,0,13);

    cout<<"before pair swap:"<<endl;
    display_by_level(bt);

    pairSwap(bt);
    cout<<"after pair swap:"<<endl;
    display_by_level(bt);

    pairSwap(bt);

    pairSwap2(bt);
    cout<<"after pair swap2:"<<endl;
    display_by_level(bt);

    return 0;
}
