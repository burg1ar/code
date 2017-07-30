#include<iostream>
#include"queue_2.h"
using namespace std;
int main(){
    Queue_with_size que1;
    init(que1);
    cout<<"isEmpty(que1): "<<isEmpty(que1)<<endl;
    for(int i=0;i<MAXSIZE;++i){
        enQueue(que1,MAXSIZE-i);
    }
    cout<<"after enQueue MAXSIZE times"<<endl;
    cout<<"que1.size: "<<que1.size<<endl;
    cout<<"isFull(que1): "<<isFull(que1)<<endl;
    int x=-1;deQueue(que1,x);
    cout<<"deQueue(que1): "<<x<<endl;
    cout<<"----------"<<endl;
    Queue_with_tag que2;
    init(que2);
    cout<<"isEmpty(que2): "<<isEmpty(que2)<<endl;
    for(int i=0;i<MAXSIZE;++i){
        enQueue(que2,MAXSIZE-i+5);
    }
    cout<<"after enQueue MAXSIZE times"<<endl;
    cout<<"isFull(que2): "<<isFull(que2)<<endl;
    deQueue(que2,x);
    cout<<"deQueue(que2): "<<x<<endl;
    return 0;
}
