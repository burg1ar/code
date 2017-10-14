#include"forTest.h"
int height(BiNode* bt){
    if(!bt) return 0;
    int lheight=height(bt->lchild);
    int rheight=height(bt->rchild);
    return lheight>rheight?lheight+1:rheight+1; //+1:plus root
}
int height_non_recursive(BiNode* bt){
    if(!bt) return 0;
    queue<BiNode*> que;
    BiNode* tmp;
    int curr_level=0;
    int curr_level_num=1;
    int next_level_num=0;
    que.push(bt);
    while(!que.empty()){
        tmp=que.front();
        que.pop();
        curr_level_num--;
        if(tmp->lchild){
            que.push(tmp->lchild);
            next_level_num++;
        }
        if(tmp->rchild){
            que.push(tmp->rchild);
            next_level_num++;
        }
        if(curr_level_num==0){
            curr_level++;
            curr_level_num=next_level_num;
            next_level_num=0;
        }
    }
    return curr_level;
}
int main() {
    BiNode* bt;
    char arr[]= {'1','#','3','#','#','6','7'};
    build_tree(bt,arr,0,7);
    cout<<"height: "<<height(bt)<<endl;
    cout<<"height_non_recursive: "<<height_non_recursive(bt)<<endl;
    return 0;
}

