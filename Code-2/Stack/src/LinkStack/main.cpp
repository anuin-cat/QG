#include <iostream>
#include <string>
#include <cstdarg>
#include "../head/LinkStack.h"
#include "LinkStack.cpp"

using namespace std;

int inputInt(int, ...);

void exceptionOccur(string);

void print(LinkStack*);

int main() {

    LinkStack* stack = new LinkStack();

    initLStack(stack);

    bool terminal = 0;

    int length = 0, opr, tempValue;

    while(!terminal) {

        system("cls");

        LStackLength(stack, &length);

        endl(cout << "Current stack (" << length << "):");
        
        print(stack);

        endl(cout << "Operation:\n<0, exit>\n<1, push>\n<2, pop>\n<3, clear>\n<4, isEmpty>\n<5, getTop>");

        opr = inputInt(3, 0, 5);

        switch (opr)
        {
        case 0:

            terminal = 1;

            break;
        
        case 1:

            endl(cout << "Please input a value(e.g 114):");

            tempValue = inputInt(0);

            if(!pushLStack(stack, tempValue)) {

                exceptionOccur("The stack is full!"); // the point that is never reach

            }

            break;
            
        case 2:

            if(!popLStack(stack, &tempValue)) {

                exceptionOccur("The stack is empty!");

            } else {

                endl(cout << "The value popped is:" << tempValue);

                getchar();

                getchar();

            }

            break;

        case 3:

            clearLStack(stack);

            endl(cout << "The stack is clear!");

            getchar();

            getchar();

            break;

        case 4:

            endl(cout << "The stack is empty: " << (isEmptyLStack(stack) ? "Yes" : "No"));

            getchar();

            getchar();

            break;

        case 5:

            if(!getTopLStack(stack, &tempValue)) {

                exceptionOccur("The stack is empty!");

            } else {

                endl(cout << "The top value is:" << tempValue);

                getchar();

                getchar();

            }

            break;

        }

    }

    destroyLStack(stack);

    delete stack;

    return 0;

}

void print(LinkStack* stack) {

    StackNode* temp = stack -> top;

    ElemType* array = new ElemType[stack -> count];

    int index = 0;

    while(temp) {

        array[index++] = temp -> data;

        temp = temp -> next;

    }

    while(index--) {

        cout << array[index];
        
        if(index) cout << " <- ";

    }

    endl(cout);

    delete[] array;

}

void exceptionOccur(string msg) {

    endl(cout << "Exception:" << msg);

    getchar();

    getchar();

}

int inputInt(int inputType, ...) {

    int in;

    int mini, maxi;

    va_list ap;

    if(inputType == 1) {
        
        va_start(ap, 1);

        mini = va_arg(ap, int);
        
    } else if(inputType == 2) {

        va_start(ap, 1);

        maxi = va_arg(ap, int);

    } else if(inputType == 3) {

        va_start(ap, 2);

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