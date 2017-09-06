/* given the NLR sequence and the LNR sequence
 * reconstruct the corresponding binary tree
 */
#include"forTest.h"
BiNode* reconstruct(elemType NLR[],int low,int high,elemType LNR[],int start,int end){
    if(low>high || start>end) return nullptr;
    BiNode* root=(BiNode*)malloc(sizeof(BiNode));
    root->val=NLR[low];
    int mid;
    for(mid=start;LNR[mid]!=root->val;mid++);
    int leftLen=mid-start;
    int rightLen=end-mid;
    root->lchild=reconstruct(NLR,low+1,low+leftLen,LNR,start,start+leftLen-1);
    root->rchild=reconstruct(NLR,high-rightLen+1,high,LNR,end-rightLen+1,end);
    return root;
}
int main(){
    elemType NLR[]={'1','2','4','5','3'};
    elemType LNR[]={'4','2','5','1','3'};
    BiNode* bt=reconstruct(NLR,0,4,LNR,0,4);
    display_by_level(bt);
    return 0;
}
