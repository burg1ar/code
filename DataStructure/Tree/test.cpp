#include"forTest.h"
int main() {
    BiNode* bt;
    char arr[]= {'1','2','3','4','5'};
    complete_tree(bt,arr,0,5);
    preOrder(bt);
    cout<<endl;

    BiNode* bt2;
    char arr2[]= {'1','#','3','#','#','6','7'};
    build_tree(bt2,arr2,0,7);
    cout<<"display_by_level:"<<endl;
    display_by_level(bt2);

    cout<<"preOrder:"<<endl;
    preOrder(bt2);
    cout<<endl;

    cout<<"preOrder_non_recursive:"<<endl;
    preOrder_non_recursive(bt2);
    cout<<endl;

    cout<<"inOrder:"<<endl;
    inOrder(bt2);
    cout<<endl;

    cout<<"inOrder_non_recursive:"<<endl;
    inOrder_non_recursive(bt2);
    cout<<endl;

    cout<<"postOrder:"<<endl;
    postOrder(bt2);
    cout<<endl;

    cout<<"postOrder_non_recursive:"<<endl;
    postOrder_non_recursive(bt2);
    cout<<endl;

    cout<<"levelOrder:"<<endl;
    levelOrder(bt2);
    cout<<endl;
    return 0;
}

