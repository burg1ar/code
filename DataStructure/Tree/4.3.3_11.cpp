#include"forTest.h"
void del_tree(BiNode* &bt){
    if(bt){
        del_tree(bt->lchild);
        del_tree(bt->rchild);
        free(bt);
    }
}
void delete_x(BiNode* &bt,elemType x){
    if(!bt) return;
    //delete the entire tree if the value of root is x
    if(bt->val==x) del_tree(bt);
    queue<BiNode*> que;
    BiNode* tmp;
    que.push(bt);
    while(!que.empty()){
        tmp=que.front();
        que.pop();
        if(tmp->lchild){
            if(tmp->lchild->val==x){
                del_tree(tmp->lchild);
                tmp->lchild=nullptr;
            }else{
                que.push(tmp->lchild);
            }
        }
        if(tmp->rchild){
            if(tmp->rchild->val==x){
                del_tree(tmp->rchild);
                tmp->rchild=nullptr;
            }else{
                que.push(tmp->rchild);
            }
        }
    }
}
int main(){
    BiNode* bt;
    elemType arr[]={'1','2','3','4','5','2','6','#','#','#','#','7','8'};
    build_tree(bt,arr,0,13);
    display_by_level(bt);
    cout<<"delete_x('2')"<<endl;
    delete_x(bt,'2');
    display_by_level(bt);
    return 0;
}
