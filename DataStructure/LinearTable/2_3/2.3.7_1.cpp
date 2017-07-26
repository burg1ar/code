#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct LNode{
    int val;
    struct LNode* next;
}LNode;
LNode* createList(LNode* &L,int arr[],int n){
    LNode* r=NULL;
    LNode* tmp=NULL;
    L=(LNode*)malloc(sizeof(LNode));
    L->val=arr[0];
    L->next=NULL;
    r=L;
    for(int i=1;i<n;++i){
        tmp=(LNode*)malloc(sizeof(LNode));
        tmp->val=arr[i];
        tmp->next=NULL;

        r->next=tmp;
        r=tmp;
    }
    return L;
}
void display(LNode* L){
    while(L){
        cout<<"["<<L->val<<"]->";
        L=L->next;
    }
    cout<<"NULL"<<endl;
}
void del_x(LNode* &L,int x){
    LNode* p=NULL;
    if(L==NULL){
        return;
    }
    if(L->val==x){
        p=L;
        L=L->next; //will keep the list integrated
        free(p);
        del_x(L,x);
    }else{
        del_x(L->next,x);
    }
}
int main(){
    LNode* L=NULL;
    int arr[]={1,2,3,4,2,5,6,2,2,7};
    L=createList(L,arr,10);
    display(L);
    del_x(L,2);
    display(L);
    return 0;
}
