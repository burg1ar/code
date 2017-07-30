/*this queue is a cyclic queue
 * to avoid "fake overflow"
 * we sacrifice a cell which will not store any data
 * to differ two cases "empty" and "full"
 */
#include<cstdlib>
#define MAXSIZE 50
typedef struct{
    int data[MAXSIZE];
    int front,rear;    //rear points to the next cell of the current element
}SqQueue;
void init(SqQueue &que){
    que.front=que.rear=0;
}
bool isEmpty(SqQueue que){
    return que.front==que.rear?true:false;
}
bool isFull(SqQueue que){
    return (que.rear+1)%MAXSIZE==que.front?true:false;
}
bool enQueue(SqQueue &que,int x){
    if(isFull(que)) return false;
    que.data[que.rear]=x;
    que.rear=(que.rear+1)%MAXSIZE;
    return true;
}
bool deQueue(SqQueue &que,int &x){
    if(isEmpty(que)) return false;
    x=que.data[que.front];
    que.front=(que.front+1)%MAXSIZE;
    return true;
}
int getSize(SqQueue que){
    //get the number of all elements
    return (que.rear-que.front+MAXSIZE)%MAXSIZE;
}
//using linked list
//hardly get fulled
typedef struct LinkNode{
    int data;
    LinkNode* next;
}LinkNode;
typedef struct{
    LinkNode *front,*rear;
}LinkQueue;
void init(LinkQueue &que){
    que.front=que.rear=(LinkNode*)malloc(sizeof(LinkNode));
    que.front->next=NULL;
}
bool isEmpty(LinkQueue que){
    return que.front==que.rear?true:false;
}
void enQueue(LinkQueue &que,int x){
    LinkNode* tmp=(LinkNode*)malloc(sizeof(LinkNode));
    tmp->data=x;
    tmp->next=NULL;
    que.rear->next=tmp;
    que.rear=tmp;
}
bool deQueue(LinkQueue &que,int &x){
    if(isEmpty(que)) return false;
    LinkNode* tmp=que.front->next;
    x=tmp->data;
    que.front->next=tmp->next;
    //if rear is the only node except the head node
    if(que.rear==tmp) que.rear=que.front;
    free(tmp);
    return true;
}














