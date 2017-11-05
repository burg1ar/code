/** judge if a binary tree is complete */
#include"BinaryTree.h"
#include<queue>
bool isComplete(BTree bt){
    BTree tmp;
    queue<BTree> que;
    que.push(bt);
    while(!que.empty()){
        tmp=que.front();
        que.pop();
        if(tmp){
            que.push(tmp->lchild);
            que.push(tmp->rchild);
        }else{
            //check if there is a non-null node after a null node
            while(!que.empty()){
                if(que.front()) return false;
                que.pop();
            }
        }
    }
    return true;
}
int main(){
    BTree btT; //T means true
    char arr1[]={'1','2','3','4','5'};
    makeBTree(btT,arr1,0,5);

    BTree btF1; //F means false
    char arr2[]={'1','2','3','#','#','4','5'};
    makeBTree(btF1,arr2,0,7);

    BTree btF2;
    char arr3[]={'1','2','3','4','#','5'};
    makeBTree(btF2,arr3,0,6);

    cout<<"is complete tree:"<<endl;
    cout<<" btT: "<<isComplete(btT)<<endl;
    cout<<"btF1: "<<isComplete(btF1)<<endl;
    cout<<"btF2: "<<isComplete(btF2)<<endl;
}
