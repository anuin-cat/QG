#include "../head/LinkStack.h"

Status initLStack(LinkStack *s) {

    if(!s) return ERROR;

    s -> top = nullptr;

    s -> count = 0;

    return SUCCESS;

}

Status isEmptyLStack(LinkStack *s) {

    if(!s) return ERROR;

    return s -> count <= 0 ? SUCCESS : ERROR;

}

Status getTopLStack(LinkStack *s,ElemType *e) {

    if(!s || isEmptyLStack(s)) return ERROR;

    if(e) *e = s -> top -> data;

    return SUCCESS;

}

Status clearLStack(LinkStack *s) {

    if(!s) return ERROR;

    while(popLStack(s, nullptr));

    return SUCCESS;

}

Status destroyLStack(LinkStack *s) {

    if(!s) return ERROR;

    while(popLStack(s, nullptr));

    //delete s; the address of [s] may be not from the heap

    return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length) {

    if(!s) return ERROR;

    if(length) *length = s -> count;

    return SUCCESS;

}

Status pushLStack(LinkStack *s,ElemType data) {

    if(!s) return ERROR;

    StackNode* node = new StackNode();

    node -> data = data;

    node -> next = s -> top;

    s -> top = node;

    s -> count++;

    return SUCCESS;

}

Status popLStack(LinkStack *s,ElemType *data) {

    if(!s || isEmptyLStack(s)) return ERROR;

    StackNode* temp = s -> top;

    s -> top = s -> top -> next;

    s -> count--;

    delete temp;

    return SUCCESS;

}