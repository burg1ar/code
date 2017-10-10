#include<iostream>
#include<cstdlib>
#define elemType int
using namespace std;
typedef struct BSTNode{
    elemType val;
    BSTNode* lchild;
    BSTNode* rchild;
}BSTNode,*BST;
BSTNode* search(BST tr,elemType key);//non-recursive search
BSTNode* find(BST tr,elemType key);//recursive search
BSTNode* findMin(BST tr);
BSTNode* findMax(BST tr);
bool insert(BST &tr,elemType key);
bool del(BST &tr,elemType key);//implementation is unfinished
void createBST(BST &tr,elemType arr[],int n);
