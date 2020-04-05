#include "SqStack.h"


Status initStack(SqStack *s,int sizes) {

    if(!s || sizes <= 0) return ERROR;

    s -> size = sizes;

    s -> top = -1;

    s -> elem = new ElemType[sizes];

    return SUCCESS;
}
Status isEmptyStack(SqStack *s) {

    if(!s) return ERROR;

    return s -> top == -1 ? SUCCESS : ERROR;
}
Status getTopStack(SqStack *s,ElemType *e) {

    if(!s || isEmptyStack(s)) return ERROR;

    *e = *(s -> elem + s -> top);

    return SUCCESS;

}
Status clearStack(SqStack *s) {

    if(!s) return ERROR;

    s -> top = -1;

    return SUCCESS;
}
Status destroyStack(SqStack *s) {

    if(!s) return ERROR;

    delete[] s -> elem;

    delete s;

    return SUCCESS;
}
Status stackLength(SqStack *s,int *length) {

    if(!s) return ERROR;

    *length = s -> top + 1;

    return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data) {

    if(!s || s -> top >= s -> size - 1) return ERROR;

    *(s -> elem + ++s -> top) = data;

    return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data) {

    if(!s || s -> top < 0) return ERROR;

    *data = *(s -> elem + s -> top--);

    return SUCCESS;
}

