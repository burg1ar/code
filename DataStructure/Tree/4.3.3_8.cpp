#include"forTest.h"
int doubleSonNodes(BiNode* bt){
    if(!bt) return 0;
    queue<BiNode*> que;
    que.push(bt);
    BiNode* tmp;
    int count=0;
    while(!que.empty()){
        tmp=que.front();
        if(tmp->lchild && tmp->rchild)
            count++;
        que.pop();
        if(tmp->lchild)
            que.push(tmp->lchild);
        if(tmp->rchild)
            que.push(tmp->rchild);
    }
    return count;
}
int doubleSonNodes2(BiNode* bt){
    if(!bt)
        return 0;
    else if(bt->lchild && bt->rchild)
        return doubleSonNodes2(bt->lchild)+doubleSonNodes2(bt->rchild)+1;
    else
        return doubleSonNodes2(bt->lchild)+doubleSonNodes2(bt->rchild);

}
int main(){
    BiNode* bt;
    char arr[]={'1','2','3','4','5','6','7','8','9'};
    build_tree(bt,arr,0,9);
    //expected output : 4
    cout<<" doubleSonNodes: "<<doubleSonNodes(bt)<<endl;
    cout<<"doubleSonNodes2: "<<doubleSonNodes2(bt)<<endl;
    return 0;
}
