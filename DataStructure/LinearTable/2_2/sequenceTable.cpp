#define ElemType int
//static sequence
#define MAX 50
typedef struct{
    ElemType data[MAX];
    int length;
}SqList;
//dynamic sequence
typedef struct{
    ElemType* data;
    int size,length;
}SeqList;
//insertion
bool listInsert(SqList &L,int i,ElemType e){

}
