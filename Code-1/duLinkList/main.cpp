#include <iostream>
#include "../head/duLinkedList.h"
#include "duLinkedList.cpp"

using namespace std;

void print(DuLinkedList*);

int main() {


    DuLinkedList* linkedList = new DuLinkedList();

    InitList_DuL(linkedList);

    endl(cout << "Please input value and -1 for the tail(e.g 114 514 -1):");


    // Init the linked list

    int in;

    bool flag = 1;

    while(true) {

        DuLNode* temp = *linkedList, *temp2;

        cin >> in;

        if(cin.fail()) {

            cin.clear();

            cin.sync();

            endl(cout << "Type error");

            continue;

        }

        if(in == -1) break;

        while(temp -> next) temp = temp -> next;

        temp2 = new DuLNode();

        temp2 -> data = in;

        InsertAfterList_DuL(temp, temp2);

    }




    while(flag) {

        system("cls");

        endl(cout << "Current linkedList:");

        print(linkedList);

        endl(cout << "Operation:\n<0, exit>\n<1, insertBefore>\n<2, insertAfter>\n<3, deleteNode>");

        int opr, t1, t2;

        DuLNode* temp, *temp2;

        cin >> opr;

        if(cin.fail() || opr > 3 || opr < 0) {

            cin.clear();

            cin.sync();

            endl(cout << "No such operation");

            getchar();

            continue;

        }

        switch(opr) {

            case 0: // Exit the system

                flag = 0;

                continue;

                break;
            
            case 1: //Insert before

                endl(cout << "Please input index and value (e.g 0 114514):");

                cin >> t1 >> t2;
                
                if(cin.fail() || t1 < 0) {

                    cin.clear();

                    cin.sync();

                    endl(cout << "Type Error");

                    getchar();

                    continue;

                }

                temp = *linkedList;

                t1++;

                while(temp -> next && t1--) temp = temp -> next;

                if(t1 > 0) {
                    
                    endl(cout << "Index not exist!");

                    getchar();

                    getchar();

                } else {

                    temp2 = new DuLNode();

                    temp2 -> data = t2;

                    InsertBeforeList_DuL(temp, temp2);

                }

                break;

            case 2: //Insert after

                endl(cout << "Please input index and value (you can also input index -1 for head node)\n (e.g 0 114514):");

                cin >> t1 >> t2;
                
                if(cin.fail() || in > -1) {

                    cin.clear();

                    cin.sync();

                    endl(cout << "Type Error");

                    getchar();

                    continue;

                }

                temp = *linkedList;

                t1++;

                while(temp -> next && t1--) temp = temp -> next;

                if(t1 > 0) {
                    
                    endl(cout << "Index not exist!");

                    getchar();

                    getchar();

                } else {

                    temp2 = new DuLNode();

                    temp2 -> data = t2;

                    InsertAfterList_DuL(temp, temp2);

                }

                break;


            case 3: // Delete 

                endl(cout << "Please input index (e.g 0):");

                cin >> t1;

                if(cin.fail() || t1 < 0) {

                    cin.clear();

                    cin.sync();

                    endl(cout << "Type Error");

                    getchar();

                    continue;

                }
                
                temp = *linkedList;

                while(temp -> next && t1--) temp = temp -> next;

                if(t1 >= 0) {
                    
                    endl(cout << "Index not exist!");

                } else {

                    DeleteList_DuL(temp, &t2);

                    endl(cout << t2 << " has been deleted!");

                }

                getchar();

                getchar();

                break;

        }

    }

    DestroyList_DuL(linkedList);

    delete linkedList;

    return 0;
}


void print(DuLinkedList* ll) {

    TraverseList_DuL(*ll, [] (ElemType e) {

        cout << e << "->";

    });

    endl(cout << '^');

}