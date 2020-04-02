#include "../head/duLinkedList.h"


using namespace std;

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {

    if(!L) return ERROR;

    *L = new DuLNode();

    (*L) -> prior = (*L) -> next = nullptr;

    (*L) -> data = -1;

    return SUCCESS;

}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {

    DuLNode* temp1 = *L, * temp2 = nullptr;

    DuLNode* head = (*L) -> next;

    while(temp1) {

        temp2 = temp1;

        temp1 = temp1 -> next;

        if(temp1 == head) return;

        delete temp2;

    }

}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {

    if(q == nullptr || p == nullptr) return ERROR;

    DuLNode* pr = p -> prior;

    q -> prior = pr;

    p -> prior = q;

    q -> next = p;

    if(pr) pr -> next = q;

    return SUCCESS;

}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {

    if(!q || !p) return ERROR;

    DuLNode* next = p -> next;

    p -> next = q;

    q -> next = next;

    q -> prior = p;

    if(next) next -> prior = q;

}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {

    if(!p || !p -> next) return ERROR;

    DuLNode* next = p -> next, * next1 = next -> next;

    *e = next -> data;

    p -> next = next1;

    if(next1) next -> prior = p;

    delete next;

    return SUCCESS;

}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {

    if(!L) return;

    DuLNode* head = L -> next;

    L = L -> next;

    while(L) {

        visit(L -> data);

        L = L -> next;

        if(L == head) return;

    }


}
