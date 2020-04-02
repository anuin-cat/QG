#include "../head/linkedList.h"

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */

using namespace std;

Status InitList(LinkedList *L) {

    if(!L) return ERROR; //A null pointer exception occured

    *L = new LNode();

    if(!*L) return ERROR; //Cannot be distributed from the heap memory

    (*L) -> data = -1; //specific value for the head node

    (*L) -> next = nullptr;

    return SUCCESS;

}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {

    LNode* temp1 = *L, * temp2 = nullptr;

    LNode* head = (*L) -> next;

    while(temp1) {

        temp2 = temp1;

        temp1 = temp1 -> next;

        if(temp1 == head) return; //For the circular linked list's exit

        delete temp2;

    }

}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {

    if(!q || !p) return ERROR; //So clear

    LNode* next = p -> next;

    p -> next = q;

    q -> next = next;

}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {

    if(!p || !p -> next) return ERROR;

    LNode* next = p -> next, * next1 = next -> next;

    *e = next -> data;

    p -> next = next1;

    delete next;

    return SUCCESS;

}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {

    if(!L) return;

    LNode* head = L -> next;

    L = L -> next;

    while(L) {

        visit(L -> data);

        L = L -> next;

        if(L == head) return;

    }

}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {

    if(!L) return ERROR;

    LNode* head = L = L -> next;

    while(L) {

        if(L -> data == e) return SUCCESS;

        L = L -> next;

        if(L == head) return ERROR;

    }

    return ERROR;

}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {

    if(!L|| !*L) return ERROR;

    if(!(*L) -> next) return SUCCESS;

    LNode* temp = (*L) -> next, *temp1 = nullptr, *temp2 = temp -> next;

    while(temp) {

        temp -> next = temp1;

        temp1 = temp;

        //To reverse the two neighbor nodes' pointer [next]

        temp = temp2;

        if(temp2) temp2 = temp2 -> next;
        
    }

    (*L) -> next = temp1; //Joint the new node with the head node

    return SUCCESS;

}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {

    if(!L) return ERROR;

    LNode* ptr1 = L, *ptr2 = L;

    while(true) {

        if(!ptr2 -> next || !ptr2 -> next -> next) return ERROR; //Touching the tail means no loop
        
        if(ptr1 == ptr2 -> next || ptr1 == ptr2 -> next -> next) return SUCCESS; //Meeting means loop

        ptr2 = ptr2 -> next -> next;

        ptr1 = ptr1 -> next;

    }

}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {

    if(!L || !*L) return nullptr;

    LNode* head = (*L) -> next, *temp1 = nullptr, *temp2 = nullptr;

    temp2 = (*L) -> next;

    while(temp2) {

        temp1 = temp2 -> next;

        if(temp1 == head || !temp1) return nullptr; 

        swap(temp2 -> data, temp1 -> data); //Swaping the data easier than swaping two container

        temp2 = temp1 -> next;

        if(temp2 == head) return nullptr;

    }
    

    return nullptr;

}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {

    if(!L || !*L) return nullptr;

    LNode* ptr1 = *L, *ptr2 = *L, *head = (*L) -> next;

    if(!ptr1 -> next) return nullptr;

    while(true) {

        ptr2 = ptr2 -> next -> next;

        ptr1 = ptr1 -> next;

        if(!ptr2 || !ptr2 -> next || 
        ptr2 == head || ptr2 -> next == head) return ptr1; //when meet the tail

    }

    return nullptr;

}

