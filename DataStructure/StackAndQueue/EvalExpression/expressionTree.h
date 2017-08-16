#include"eval.h"
#include<queue>
typedef struct TNode{
    char val;
    TNode* lchild;
    TNode* rchild;
}TNode;
//use postfix(reverse polish) expression to create expressionTree
//expr:postfix expression
TNode* expressionTree(string expr){
    stack<TNode*> stk;
    TNode *mid,*left,*right;
    for(auto it=expr.begin();it!=expr.end();++it){
        if(isDigit(*it)){
            mid=new TNode{*it,NULL,NULL};
            stk.push(mid);
        }else if(isOperator(*it)){
            right=stk.top();stk.pop();
            left=stk.top();stk.pop();
            mid=new TNode{*it,left,right};
            stk.push(mid);
        }else{
            cout<<"wrong expression"<<endl;
            return NULL; //ERROR
        }
    }
    return stk.top();
}
void printTree(TNode* tr){
    //level traversal
    queue<TNode*> que;
    if(tr){
        int curr_level=1;
        int curr_level_num=1;
        int next_level_num=0;

        que.push(tr);
        while(!que.empty()){
            tr=que.front();
            que.pop();
            cout<<tr->val;
            --curr_level_num;
            if(tr->lchild){
                que.push(tr->lchild);
                ++next_level_num;
            }
            if(tr->rchild){
                que.push(tr->rchild);
                ++next_level_num;
            }
            if(curr_level_num==0){
                cout<<endl;
                ++curr_level;
                curr_level_num=next_level_num;
                next_level_num=0;
            }
        }
    }
}
void getPostfix(TNode* tr,string &output){
    if(tr){
        getPostfix(tr->lchild,output);
        getPostfix(tr->rchild,output);
        output.push_back(tr->val);
    }
}
//get infix expression from an expression tree recursively
string getInfix(TNode* tr){
    string t1,t2;
    if(tr->lchild)
        t1=getInfix(tr->lchild);
    if(tr->rchild)
        t2=getInfix(tr->rchild);
    if(tr->lchild==NULL && tr->rchild==NULL){
        stringstream ss;
        ss<<tr->val;
        return ss.str();
    }else{
        return "("+t1+tr->val+t2+")";
    }
}
string postfix_to_infix(string expr){
    stack<string> stk;
    string str1,str2;
    for(auto it=expr.begin();it!=expr.end();++it){
        if(isDigit(*it)){
            stringstream ss;
            ss<<*it;
            stk.push(ss.str());
        }else if(isOperator(*it)){
            str1=stk.top();stk.pop();
            str2=stk.top();stk.pop();
            stk.push("("+str2+(*it)+str1+")");
        }else{
            return "wrong expression";
        }
    }
    if(stk.empty()) return "ERROR";
    return stk.top();
}
//encapsulate with as few parentheses as possible
string postfix_to_infix_v2(string expr){

}
