#include <iostream>
#include <cstdlib>
#include "../head/linkedList.h"
#include "linkedList.cpp"

using namespace std;


void print(LinkedList*);

Status updateLoopList(LNode*, LNode*);

int main() {


    LinkedList* linkedList = new LinkedList();

    InitList(linkedList);

    endl(cout << "Please input value and -1 for the tail(e.g 114 514 -1):");

    int in;

    bool flag = 1;

    while(true) {

        LNode* temp = *linkedList, *temp2;

        cin >> in;

        if(cin.fail()) {

            cin.clear();

            cin.sync();

            endl(cout << "Type error");

            continue;

        }

        if(in == -1) break;

        while(temp -> next) temp = temp -> next;

        temp2 = new LNode();

        temp2 -> data = in;

        InsertList(temp, temp2);

    }

    while(flag) {

        system("cls");

        endl(cout << "Current linkedList:");

        print(linkedList);

        endl(cout << "Operation:\n<0, exit>\n<1, insert>\n<2, search>\n<3, deleteNode>\n<4, midNode>\n<5, isLoopList>\n<6, reverseList>\n<7. reverseEvenOddList>");

        int opr, t1, t2;

        LNode* temp, *temp2, *head;

        cin >> opr;

        if(cin.fail() || opr > 7 || opr < 0) {

            cin.clear();

            cin.sync();

            endl(cout << "No such operation");

            getchar();

            continue;

        }

        switch(opr) {

            case 0:

                flag = 0;

                continue;

                break;
            
            case 1:

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

                while(temp -> next && t1--) temp = temp -> next;

                if(t1 > 0) {
                    
                    endl(cout << "Index not exist!");

                    getchar();

                    getchar();

                } else {

                    temp2 = new LNode();

                    temp2 -> data = t2;

                    InsertList(temp, temp2);

                }

                break;

            case 2:

                endl(cout << "Please input the value you want to search (e.g 0):");

                cin >> t1;

                if(cin.fail()) {

                    cin.clear();

                    cin.sync();

                    endl(cout << "Type Error");

                    getchar();

                    continue;

                }

                endl(cout << t1 <<" is exist: " << (SearchList(*linkedList, t1)?"Yes":"No"));

                getchar();

                getchar();

                break;


            case 3:

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

                    DeleteList(temp, &t2);

                    endl(cout << t2 << " has been deleted!");

                }

                getchar();

                getchar();

                break;

            
            case 4:

                temp2 = FindMidNode(linkedList);

                endl(cout << "MidNode: " << (temp2?temp2 -> data:-1));

                getchar();

                getchar();

                break;

            case 5:

                endl(cout << "isLoopList: " << (IsLoopList(*linkedList)?"Yes":"No"));

                getchar();

                getchar();

                break;

            case 6:

                ReverseList(linkedList);

                break;

             case 7:


                ReverseEvenList(linkedList);



                break;


        }

    }

    DestroyList(linkedList);

    return 0;
}


void print(LinkedList* ll) {

    TraverseList(*ll, [] (ElemType e) {

        cout << e << "->";

    });

    endl(cout << '^');

}