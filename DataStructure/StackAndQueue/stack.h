#define MAXSIZE 50
typedef struct{
    int data[MAXSIZE];
    int top;
}SqStack;
void init(SqStack &stack){
    stack.top=-1;
}
bool isEmpty(SqStack stack){
    return stack.top==-1? true:false;
}
bool push(SqStack &stack,int x){
    if(stack.top==MAXSIZE-1) return false;
    stack.data[++stack.top]=x;
    return true;
}
bool pop(SqStack &stack,int &x){
    if(stack.top==-1) return false;
    x=stack.data[stack.top--];
    return true;
}
bool getTop(SqStack stack,int &x){
    if(stack.top==-1) return false;
    x=stack.data[stack.top];
    return true;
}
