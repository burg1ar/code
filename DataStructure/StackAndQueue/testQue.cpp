#include<iostream>
#include"queue.h"
using namespace std;
int main(){
    LinkQueue que;
    init(que);
    enQueue(que,66);
    cout<<"isEmpty: "<<isEmpty(que)<<endl;
    cout<<que.rear->data<<endl;
    int y;
    deQueue(que,y);
    cout<<y<<endl;
    cout<<"isEmpty: "<<isEmpty(que)<<endl;
    return 0;
}
