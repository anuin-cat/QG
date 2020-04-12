#include "LQueue.h"

void InitLQueue(LQueue *Q) {

    if(!Q) return;

    Q -> rear = Q -> front = new Node();

    Q -> front -> data = Q -> front -> next = nullptr;

    Q -> length = 0;

}

void DestoryLQueue(LQueue *Q) {

    if(!Q) return;

    while(Q -> front -> next) {

        Node *temp = Q -> front -> next;

        delete Q -> front;

        Q -> front = temp;

    }

    delete Q -> front;

}

Status IsEmptyLQueue(const LQueue *Q) {

    if(!Q) return FALSE;

    return Q -> length == 0 ? TRUE : FALSE;

}

Status GetHeadLQueue(LQueue *Q, void *e) {

    if(!Q || IsEmptyLQueue(Q) || !e) return FALSE;

    (*(void**)e) = Q -> front -> next -> data;

    return TRUE;

}

int LengthLQueue(LQueue *Q) {

    if(!Q) return -1;

    return Q -> length;
}

Status EnLQueue(LQueue *Q, void *data) {

    if(!Q || !data) return FALSE;

    Node *temp = new Node();

    temp -> data = data;

    temp -> next = nullptr;

    Q -> rear -> next = temp;

    Q -> rear = temp;

    Q -> length++;

    return TRUE;
}

Status DeLQueue(LQueue *Q) {

    if(!Q || IsEmptyLQueue(Q)) return FALSE;

    Node *temp = Q -> front;

    Q -> front = Q -> front -> next;

    Q -> front -> data = nullptr;

    Q -> length--;

    delete temp;

    return TRUE;

}

void ClearLQueue(LQueue *Q) {

    if(!Q) return;

    while(Q -> front -> next) {

        Node *temp = Q -> front -> next;

        delete Q -> front;

        Q -> front = temp;

        Q -> front -> data = nullptr;

    }

    Q -> length = 0;

    Q -> rear = Q -> front;

}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)) {

    if(!Q) return FALSE;

    node *temp = Q -> front -> next;

    for(int i = 0; i < Q -> length; i++) {

        foo(temp -> data);

        temp = temp -> next;

    }

    return TRUE;

}
