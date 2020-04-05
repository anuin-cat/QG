#include <cstdio>
#include <iostream>
#include "SqStack.h"
#include "SqStack.cpp"
#include <cstring>
#include <cmath>
#define isNum(x) ((x) <= '9' && (x) >= '0')

using namespace std;

void exceptionOccur(string);

void RPN(int* num, char* opr, char* syn, int* len);

int RPN2RES(int* num, char* opr, int len);


int main() {

    char input[10003]; //Save the string inputed

    int num[10003]; //Save the numbers(or Integers, precisely) of the RPN

    char opr[10003]; //Save the operators of the RPN

    int len = 0; //The length of the RPN

    int res; //The result calculated from the RPN

    while(1)  {

        endl(cout << "Please input a expression (e.g 1 + 1 ):");

        cin.getline(input, 10002);

        try {

            RPN(num, opr, input, &len);

        }catch (const char* msg) {

            exceptionOccur(msg);

            continue;

        }

        cout << "RPN:";

        for(int i = 0;i < len;i++) {

            if(opr[i] == '!') {

                cout << num[i] << ' ';

            } else {

                cout << opr[i] << ' ';

            }

        }

        endl(cout);

        try {

            res = RPN2RES(num, opr, len);

        }catch (const char* msg) {

            exceptionOccur(msg);

            continue;

        }

        
        endl(cout << "Result: " << res);

    }

    return 0;

}

void exceptionOccur(string msg) {

    endl(cout << "Exception: " << msg);

}

void RPN(int* num, char* opr, char* syn, int* len) {

    int syn_index = 0;// index of the String;

    int index = 0;//index of opr and num

    SqStack* stack = new SqStack();//a stack

    initStack(stack, 10003);

    char tempChar;//tempChar to save pop stack or topstack

    int carry = 0;//carry of the number
        
    bool num_is = 0;//if the last char we are reading is number

    bool num_Minus = 0;//if a minus before the number

    char pre = -1;//Last vaild char(excepts space) read

    bool pre_space = 0;//Last char is space or not;

    while(1) {

        char cur = syn[syn_index];

        if(num_is && pre_space && isNum(cur)) {

            throw "Format wrong!";

        }

        if(isNum(cur)) { //When it's a number

            num_is = 1;

            carry *= 10;

            carry += cur - '0';

        } else if(cur == '+' || cur == '-' || cur == '*' || cur == '/' || cur == '(' || cur == ')'){ //Not meet a nul or space, i.e vaild symbols


            if(num_is) { //When last char loaded is number

                num_is = 0;

                num[index] = carry * (num_Minus?-1:1);

                num_Minus = 0;

                opr[index++] = '!';

                carry = 0;

            } else if(pre != ')' && cur == '-') { //When meet a puffix minus

                if(pre == '(' || pre == -1) {

                    num[index] = 0;

                    opr[index++] = '!';
                    
                } 

            } else if(pre != ')' && cur == '+') { //When meet a puffix plus

                if(pre == '(' || pre == -1) {

                    num[index] = 0;

                    opr[index++] = '!';
                    
                }

            }

            if(cur == '(') { //Left bracket
            
                pushStack(stack, cur);

            } else if(cur == ')') { //Right bracket

                while(1) {

                    if(!popStack(stack, &tempChar)) {

                        throw "Brackets not matched!";

                        //Exception occured

                    }

                    if(tempChar == '(') {

                        break;

                    } else {

                        num[index] = 0;

                        opr[index++] = tempChar;

                    }

                }

            } else if(cur == '*'|| cur == '/') {

                if(pre == '/' || pre == '*') {

                    throw "Invaild Syntax!";

                }

                while(1) {

                    getTopStack(stack, &tempChar);

                    if(isEmptyStack(stack) || tempChar != '*' && tempChar != '/') break;

                    if(tempChar == '(') {

                        break;
                        
                    } else {

                        num[index] = 0;

                        popStack(stack, &tempChar);

                        opr[index++] = tempChar;

                    }

                }

                pushStack(stack, cur);

            } else if(cur == '+'|| cur == '-') {

                    if(pre == '+' || pre == '-') {

                        throw "Invaild Syntax!";

                    }

                    while(1) {

                    if(isEmptyStack(stack)) break;

                    getTopStack(stack, &tempChar);

                    if(tempChar == '(') {

                        break;
                        
                    } else {

                        num[index] = 0;

                        popStack(stack, &tempChar);

                        opr[index++] = tempChar;

                    }

                }

                pushStack(stack, cur);
                
            }

        } else if(!cur) { // When meet a nul

            if(num_is) {

                num_is = 0;

                num[index] = carry * (num_Minus?-1:1);

                opr[index++] = '!';

                carry = 0;

            }

            while(1) { //Pop all the stuff from stack

                    if(isEmptyStack(stack)) break;

                    popStack(stack, &tempChar);

                    if(tempChar == '(') {

                        throw "Brackets not matched!";

                        break;
                        
                    } else {

                        num[index] = 0;

                        opr[index++] = tempChar;

                    }

            }

            break;

        } else if(cur != ' '){ //Unknown char in the string

            throw "Invaild symbol!";

        } 

        syn_index++;

        if(cur != ' ') pre = cur;

        pre_space = cur == ' ';

    }

    *len = index;

    delete stack;

}

//Calculate the RPN

int RPN2RES(int* num, char* opr, int len) {

        int RPN_res[10003];

        int RPN_index = -1;

        for(int i = 0;i < len;i++) {

            switch (opr[i])
            {
            case '!': //Integer
                RPN_res[++RPN_index] = num[i];
                break;
            
            case '+': //Plus
                RPN_res[RPN_index - 1] += RPN_res[RPN_index];
                RPN_index--;
                break;

            case '-': //Minus
                RPN_res[RPN_index - 1] -= RPN_res[RPN_index];
                RPN_index--;
                break;

            case '*': //Mutiply
                RPN_res[RPN_index - 1] *= RPN_res[RPN_index];
                RPN_index--;
                break;

            case '/': //Divide

                if(RPN_res[RPN_index] == 0) {

                    throw "Division cannot be ZERO!";

                }

                RPN_res[RPN_index - 1] /= RPN_res[RPN_index];
                RPN_index--;
                break;

            }

        }

        return RPN_res[0];

}
