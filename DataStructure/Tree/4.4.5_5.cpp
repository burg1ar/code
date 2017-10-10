#define int ElemType
typedef struct Node{
    ElemType data;
    Node *firstChild,*nextSibling;
}*Tree;
int leaves(Tree tr){
    if(tr==nullptr)
        return 0;
    if(tr->firstChild==nullptr)
        return 1+leaves(tr->nextSibling);
    else
        return leaves(tr->firstChild)+leaves(tr->nextSibling);
}
