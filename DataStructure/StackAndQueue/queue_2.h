/*to avoid "fake overflow" of queue
 * we still use cyclic queue
 * but try two more strategies as following
 */
#define MAXSIZE 5
typedef struct{
    int data[MAXSIZE];
    int front,rear;
    int size; //queue empty:size=0;full:size=MAXSIZE
}Queue_with_size;
void init(Queue_with_size &que){
    que.front=que.rear=0;
    que.size=0;
}
bool isEmpty(Queue_with_size que){
    return que.size==0?true:false;
}
bool isFull(Queue_with_size que){
    return que.size==MAXSIZE?true:false;
}
bool enQueue(Queue_with_size &que,int x){
    if(isFull(que)) return false;
    que.data[que.rear]=x;
    que.rear=(que.rear+1)%MAXSIZE;
    ++(que.size);
    return true;
}
bool deQueue(Queue_with_size &que,int &x){
    if(isEmpty(que)) return false;
    x=que.data[que.front];
    que.front=(que.front+1)%MAXSIZE;
    --(que.size);
    return true;
}
typedef struct{
    int data[MAXSIZE];
    int front,rear;
    int tag; //differ two cases when que.front==que.rear
}Queue_with_tag;
void init(Queue_with_tag &que){
    que.front=que.rear=0;
    que.tag=0;
}
bool isEmpty(Queue_with_tag que){
    return que.front==que.rear && que.tag==0?true:false;
}
bool isFull(Queue_with_tag que){
    return que.front==que.rear && que.tag==1?true:false;
}
bool enQueue(Queue_with_tag &que,int x){
    if(isFull(que)) return false;
    que.data[que.rear]=x;
    que.rear=(que.rear+1)%MAXSIZE;
    que.tag=1;
    return true;
}
bool deQueue(Queue_with_tag &que,int &x){
    if(isEmpty(que)) return false;
    x=que.data[que.front];
    que.front=(que.front+1)%MAXSIZE;
    que.tag=0;
    return true;
}
