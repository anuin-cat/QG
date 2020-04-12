#include "AQueue.h"

void InitAQueue(AQueue *Q) {

    if(!Q) return;

    Q -> front = 0;
    
    Q -> rear = 0;

    Q -> length = 0;

}

void DestoryAQueue(AQueue *Q) {

    if(!Q) return;

    Q -> front = Q -> rear = 0;

    Q -> length = 0;

}

Status IsFullAQueue(const AQueue *Q) {

    if(!Q) return FALSE;

    return Q -> length == MAXQUEUE ? TRUE : FALSE;

}

Status IsEmptyAQueue(const AQueue *Q) {

    if(!Q) return FALSE;

    return Q -> length == 0 ? TRUE : FALSE;

}

Status GetHeadAQueue(AQueue *Q, void *e) {

    if(!Q || IsEmptyAQueue(Q)) return FALSE;

    (*((void**)e)) = Q -> data[Q -> front + 1];

    return TRUE;

}

int LengthAQueue(AQueue *Q) {

    if(!Q) return -1;

    return Q -> length;

}

Status EnAQueue(AQueue *Q, void *data) {

    if(!Q || IsFullAQueue(Q)) return FALSE;

    Q -> rear++;

    Q -> rear %= MAXQUEUE;

    Q -> data[Q -> rear] = data;

    Q -> length++;

    return TRUE;

}

Status DeAQueue(AQueue *Q) {

    if(!Q || IsEmptyAQueue(Q)) return FALSE;

    Q -> front++;

    Q -> front %= MAXQUEUE;

    Q -> length--;

    return TRUE;

}

void ClearAQueue(AQueue *Q) {

    if(!Q) return;

    Q -> front = Q -> rear = 0;

    Q -> length = 0;

}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)) {

    if(!Q) return FALSE;

    for(int i = 0;i < Q -> length; i++) {

        foo(Q -> data[(Q -> front + i + 1) % MAXQUEUE]);

    }

    return TRUE;

}