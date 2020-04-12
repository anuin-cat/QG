#include <iostream>
#include <string>
#include <cstdarg>
#include "LQueue.h"

using namespace std;

int inputInt(int, ...);

void exceptionOccur(string);

void print(LQueue*);

int main() {

    LQueue* queue = new LQueue();

    InitLQueue(queue);

    bool terminal = 0;

    int a = 0;

    while(!terminal) {

        system("cls");

        endl(cout << "Current queue(" << queue -> length << "):");
        
        print(queue);

        endl(cout << "Operation:\n<0, exit>\n<1, enqueue>\n<2, dequeue>\n<3, clear>\n<4, isEmpty>\n<5, getTop>");

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

            if(EnLQueue(queue, temp)) {



            } else {

                endl(cout << "The queue is full!");

                system("pause");

                delete temp;

            }

            break;

        case 2:

            if(GetHeadLQueue(queue, &temp)) {

                delete temp;

                DeLQueue(queue);

            } else {

                endl(cout << "The queue is empty!");

                system("pause");

            }

            break;
        
        case 3:

            TraverseLQueue(queue, [] (void* q){

                delete q;

            });

            ClearLQueue(queue);

            break;

        case 4:

            endl(cout << "Is Empty:" << (IsEmptyLQueue(queue) ? "YES" : "NO"));

            system("pause");

            break;

        case 5:

            if(GetHeadLQueue(queue, &temp)) {

                endl(cout << "Head:" << *temp);

            } else {

                endl(cout << "The queue is empty!");

            }

            system("pause");
            
            break;

        }

    }

    TraverseLQueue(queue, [] (void* q){

        delete q;

    });

    DestoryLQueue(queue);

    return 0;
}

void print(LQueue* queue) {

    TraverseLQueue(queue, [] (void* q){

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

    if (inputType == 1) {

        inputType = 1;

        va_start(ap, inputType);

        mini = va_arg(ap, int);

    }
    else if (inputType == 2) {

        inputType = 1;

        va_start(ap, inputType);

        maxi = va_arg(ap, int);

    }
    else if (inputType == 3) {

        inputType = 2;

        va_start(ap, inputType);

        mini = va_arg(ap, int);

        maxi = va_arg(ap, int);

    }

    while (1) {

        cin >> in;

        if (cin.fail() || inputType == 1 && in < mini || inputType == 2 && in > maxi || inputType == 3 && in > maxi || inputType == 3 && in < mini) {

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