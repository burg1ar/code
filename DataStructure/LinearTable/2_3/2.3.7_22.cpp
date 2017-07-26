#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct LNode{
    char letter;
    struct LNode* next;
}LNode;
LNode* createList(LNode* &L,char arr[],int n){
    L=(LNode*)malloc(sizeof(LNode));
    L->next=NULL;

    LNode* p=L;
    LNode* tmp=NULL;
    for(int i=0;i<n;i++){
        tmp=(LNode*)malloc(sizeof(LNode));
        tmp->letter=arr[i];
        tmp->next=NULL;

        p->next=tmp;
        p=tmp;
    }
    return L;
}
void display(LNode* L){ //L is the head node
    cout<<"[head]->";
    L=L->next;
    while(L){
        cout<<"["<<L->letter<<"]->";
        L=L->next;
    }
    cout<<"NULL"<<endl;
}
void printList(LNode* L){   //L is not the head node
    while(L){
        cout<<"["<<L->letter<<"]->";
        L=L->next;
    }
    cout<<"NULL"<<endl;
}
int getLen(LNode* L){
    int len=0;
    while(L->next){
        ++len;
        L=L->next;
    }
    return len;
}
//假定str1的长度大于2
LNode* find_addr(LNode* str1,LNode* str2){
    int m=getLen(str1);
    int n=getLen(str2);
    for(int i=0;i<=m-n;++i){ //依尾对齐
        str1=str1->next;
    }
    str2=str2->next;
//    cout<<str1->letter<<" "<<str2->letter<<endl;
    while(str1 && str1!=str2){
        str1=str1->next;
        str2=str2->next;
    }
    return str1;
}
int main(){
    char arr1[]={'l','o','a','d','i','n','g'};
    char arr2[]={'b','e'};
    LNode* str1=NULL;
    LNode* str2=NULL;
    str1=createList(str1,arr1,7);
    str2=createList(str2,arr2,2);
    LNode* p=str1;
    while(p->letter!='i'){
        p=p->next;
    }
    str2->next->next->next=p;
    display(str1);
    display(str2);

    LNode* r=find_addr(str1,str2);
    printList(r);
}

