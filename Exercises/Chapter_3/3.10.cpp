#include"BinaryTree.h"
bool isOperator(char c){
    return c=='+'||c=='-'||c=='*'||c=='/';
}
int postEval(BTree bt){
    char buffer[5];
    int lv,rv,result;
    if(bt){
        lv=postEval(bt->lchild);
        rv=postEval(bt->rchild);
        if(isOperator(bt->val)){
            switch(bt->val){
                case '+':result=lv+rv;break;
                case '-':result=lv-rv;break;
                case '*':result=lv*rv;break;
                case '/':result=lv/rv;
            }
        }else{
            buffer[0]=bt->val;
            result=atoi(buffer);
        }
    }
    return result;
}
int main(){
    BTree bt;
    char arr[]={'+','*','4','2','3'};
    makeBTree(bt,arr,0,5);
    cout<<postEval(bt)<<endl;
    return 0;
}
