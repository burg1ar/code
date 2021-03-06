#include<iostream>
#include<queue>
using namespace std;
typedef struct BiNode{
    int weight;
    BiNode* left;
    BiNode* right;
}BiNode;
int wpl(BiNode* bt){
    //based on level traversal
    if(bt==nullptr) return -1;
    queue<BiNode*> que;
    int wpl=0;
    BiNode* tmp;
    que.push(bt);
    int curr_level=0;
    int curr_level_num=1;
    int next_level_num=0;
    while(!que.empty()){
        tmp=que.front();
        que.pop();
        curr_level_num--;
        if(tmp->left){
            que.push(tmp->left);
            next_level_num++;
        }
        if(tmp->right){
            que.push(tmp->right);
            next_level_num++;
        }
        if(!tmp->left && !tmp->right){
            wpl+=tmp->weight*curr_level;
        }
        if(curr_level_num==0){
            curr_level++;
            curr_level_num=next_level_num;
            next_level_num=0;
        }
    }
    return wpl;
}
int wpl_preOrder(BiNode* bt,int depth){
    //based on pre order traversal (recursively)
    static int wpl=0;
    if(bt->left==nullptr && bt->right==nullptr){
        wpl+=depth*bt->weight;
    }
    if(bt->left)
        wpl_preOrder(bt->left,depth+1);
    if(bt->right)
        wpl_preOrder(bt->right,depth+1);
    return wpl;
}
int wpl_2(BiNode* bt){
    wpl_preOrder(bt,0);
}
void build_tree(BiNode* &bt,int arr[],int index,int len) {
    //-1 represents nullptr
    if(index>=len || arr[index]==-1) return;
    bt=(BiNode*)malloc(sizeof(BiNode));
    bt->weight=arr[index];
    bt->left=bt->right=nullptr;
    build_tree(bt->left,arr,2*index+1,len);
    build_tree(bt->right,arr,2*index+2,len);
}
int main(){
    BiNode* bt;
    int arr[]={18,7,11,-1,-1,5,6,-1,-1,-1,-1,-1,-1,2,4};
    build_tree(bt,arr,0,15);
    cout<<"WPL is: "<<wpl(bt)<<endl;
    cout<<"WPL is: (recursively) "<<wpl_2(bt)<<endl;
    BiNode* bt2;
    int arr2[]={18,16,2,4,12,-1,-1,-1,-1,7,5,-1,-1,-1,-1};
    build_tree(bt2,arr2,0,15);
    cout<<"WPL2 is: "<<wpl(bt2)<<endl;
    //wpl_2 can only be used once,cause "wpl" is static(line 44)
    //it will accumulate when second call happens
    //cout<<"WPL2 is: (recursively) "<<wpl_2(bt2)<<endl;
    return 0;
}
