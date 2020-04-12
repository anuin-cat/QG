#include <iostream>
#include <string>
#include <cstdarg>
#include "AQueue.h"


using namespace std;

int inputInt(int, ...);

void exceptionOccur(string);

void print(AQueue*);

int main() {

    AQueue* queue = new AQueue();

    InitAQueue(queue);

    bool terminal = 0;

    int a = 0;

    while(!terminal) {

        system("cls");

        endl(cout << "Current queue(" << LengthAQueue(queue) << "/" << MAXQUEUE <<"):");
        
        print(queue);

        endl(cout << "Operation:\n<0, exit>\n<1, enqueue>\n<2, dequeue>\n<3, clear>\n<4, isEmpty>\n<5, getTop>\n<6, isFull>");

        int opr = inputInt(3, 0, 6);

        int* temp, temp1;

        switch (opr)
        {
        case 0:

            terminal = 1;

            break;
        
        case 1:

            endl(cout << "Please input a integer(e.g 114514):");

            temp1 = inputInt(0);

            temp = new int(temp1);

            if(EnAQueue(queue, temp)) {



            } else {

                endl(cout << "The queue is full!");

                system("pause");

                delete temp;

            }

            break;

        case 2:

            if(GetHeadAQueue(queue, &temp)) {

                delete temp;

                DeAQueue(queue);

            } else {

                endl(cout << "The queue is empty!");

                system("pause");

            }

            break;
        
        case 3:

            TraverseAQueue(queue, [] (void* q){

                delete q;

            });

            ClearAQueue(queue);

            break;

        case 4:

            endl(cout << "Is Empty:" << (IsEmptyAQueue(queue) ? "YES" : "NO"));

            system("pause");

            break;

        case 5:

            if(GetHeadAQueue(queue, &temp)) {

                endl(cout << "Head:" << *temp);

            } else {

                endl(cout << "The queue is empty!");

            }

            system("pause");
            
            break;

        case 6:

            endl(cout << "Is Full:" << (IsFullAQueue(queue) ? "YES" : "NO"));

            system("pause");

            break;

        }

    }

    TraverseAQueue(queue, [] (void* q){

        delete q;

    });

    DestoryAQueue(queue);

    return 0;
}

void print(AQueue* queue) {

    TraverseAQueue(queue, [] (void* q){

        cout << (*(int*)q) << ' ';

    });

    endl(cout);

}

void exceptionOccur(string msg) {

    endl(cout << "Exception:" << msg);

    system("pause");

}

int inputInt(int inputType, ...) {

    int in;

    int mini, maxi;

    va_list ap;

    int count;

    if(inputType == 1) {

        inputType = 1;
        
        va_start(ap, inputType);

        mini = va_arg(ap, int);
        
    } else if(inputType == 2) {

        inputType = 1;

        va_start(ap, inputType);

        maxi = va_arg(ap, int);

    } else if(inputType == 3) {

        inputType = 2;

        va_start(ap, inputType);

        mini = va_arg(ap, int);

        maxi = va_arg(ap, int);

    }

    while(1) {

        cin >> in;

        if(cin.fail() || inputType == 1 && in < mini || inputType == 2 && in > maxi || inputType == 3 && in > maxi || inputType == 3 && in < mini ) {

            cin.clear();

            cin.sync();

            endl(cout << "Input error");

            endl(cout << "Please input again:");

            continue;

        }

        break;

    }

    va_end(ap);

    return in;
        
}