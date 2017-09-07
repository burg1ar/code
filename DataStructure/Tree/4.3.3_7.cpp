#include"forTest.h"
bool isComplete(BiNode* bt){
    if(!bt) return true; //empty binary tree is complete(full)
    queue<BiNode*> que;
    BiNode* tmp;
    que.push(bt);
    while(!que.empty()){
        tmp=que.front();
        que.pop();
        if(tmp){
            que.push(tmp->lchild);
            que.push(tmp->rchild);
        }else{
            while(!que.empty()){
                if(que.front())
                    return false;
                que.pop();
            }
        }
    }
    return true;
}
int main(){
    BiNode* btT; //T means true
    char arr1[]={'1','2','3','4','5'};
    build_tree(btT,arr1,0,5);

    BiNode* btF1; //F meas false
    char arr2[]={'1','2','3','#','#','4','5'};
    build_tree(btF1,arr2,0,7);

    BiNode* btF2;
    char arr3[]={'1','2','3','4','#','5'};
    build_tree(btF2,arr3,0,6);

    cout<<"is complete tree:"<<endl;
    cout<<" btT: "<<isComplete(btT)<<endl;
    cout<<"btF1: "<<isComplete(btF1)<<endl;
    cout<<"btF2: "<<isComplete(btF2)<<endl;

    return 0;
}
