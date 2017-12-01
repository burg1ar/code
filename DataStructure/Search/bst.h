#ifndef _BST_H
typedef int ElemType;
struct BSTNode;
typedef struct BSTNode *BST;
typedef struct BSTNode *Position;

BST MakeEmpty(BST T);
Position Find(BST T,ElemType X);
Position FindMin(BST T);
Position FindMax(BST T);
BST Insert(BST &T,ElemType X);
BST Delete(BST &T,ElemType X);

#endif
