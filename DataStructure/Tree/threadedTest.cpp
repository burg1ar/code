#include"threadedBT.h"
int main(){
    ThreadedBT Thrt;
    ElemType arr[]={'A','B','C','D','E','#','F','G'};
    makeEmptyThreadTree(Thrt,arr,0,8);
    inOrderTraverse(Thrt);
    cout<<endl;
    createInOrderThread(Thrt);
    inOrderThreadTraverse(Thrt);
    inOrderThreadTraverse2(Thrt);
    return 0;
}
