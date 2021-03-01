/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Daniel Dimitrov
* @idnumber 62384
* @task 3
* @compiler GCC
*
*/
#include<iostream>
using namespace std;

int Convert16to10(char symbol)
{
    int num_10;
    switch(symbol)
    {
        case '0': num_10 = 0; break;
        case '1': num_10 = 1; break;
        case '2': num_10 = 2; break;
        case '3': num_10 = 3; break;
        case '4': num_10 = 4; break;
        case '5': num_10 = 5; break;
        case '6': num_10 = 6; break;
        case '7': num_10 = 7; break;
        case '8': num_10 = 8; break;
        case '9': num_10 = 9; break;
        case 'A': num_10 = 10; break;
        case 'B': num_10 = 11; break;
        case 'C': num_10 = 12; break;
        case 'D': num_10 = 13; break;
        case 'E': num_10 = 14; break;
        case 'F': num_10 = 15; break;
        default : cout<<"Wrong entry!"; break;
    }

    return num_10;
}

void Convert10to16(int result_10 )
{
    int a, b;
    char _a, _b;
    a = result_10 % 16;

    if( a < 0 )
    {
        switch(a)
        {
            case -1: _a = '1'; break;
            case -2: _a = '2'; break;
            case -3: _a = '3'; break;
            case -4: _a = '4'; break;
            case -5: _a = '5'; break;
            case -6: _a = '6'; break;
            case -7: _a = '7'; break;
            case -8: _a = '8'; break;
            case -9: _a = '9'; break;
            case -10: _a = 'A'; break;
            case -11: _a = 'B'; break;
            case -12: _a = 'C'; break;
            case -13: _a = 'D'; break;
            case -14: _a = 'E'; break;
            case -15: _a = 'F'; break;
        }
        cout<<"-"<<_a;
    }
    else
    {
        switch (a)
        {
            case 0: _a = '0'; break;
            case 1: _a = '1'; break;
            case 2: _a = '2'; break;
            case 3: _a = '3'; break;
            case 4: _a = '4'; break;
            case 5: _a = '5'; break;
            case 6: _a = '6'; break;
            case 7: _a = '7'; break;
            case 8: _a = '8'; break;
            case 9: _a = '9'; break;
            case 10: _a = 'A'; break;
            case 11: _a = 'B'; break;
            case 12: _a = 'C'; break;
            case 13: _a = 'D'; break;
            case 14: _a = 'E'; break;
            case 15: _a = 'F'; break;
        }
        if(result_10 > 15)
        {
            b = result_10 / 16 % 16;
            switch (b)
            {
                case 0: _b = '0'; break;
                case 1: _b = '1'; break;
                case 2: _b = '2'; break;
                case 3: _b = '3'; break;
                case 4: _b = '4'; break;
                case 5: _b = '5'; break;
                case 6: _b = '6'; break;
                case 7: _b = '7'; break;
                case 8: _b = '8'; break;
                case 9: _b = '9'; break;
                case 10: _b = 'A'; break;
                case 11: _b = 'B'; break;
                case 12: _b = 'C'; break;
                case 13: _b = 'D'; break;
                case 14: _b = 'E'; break;
                case 15: _b = 'F'; break;
            }
            cout<<_b<<_a;
        }
    else cout<<_a;
    }
}

int main ()
{
    char operation, number1_16, number2_16;
    cin>>operation>>number1_16>>number2_16;

    int number1_10, number2_10;
    number1_10 = Convert16to10(number1_16);
    number2_10 = Convert16to10(number2_16);

    int result_10, result_16;
    switch( operation )
    {
        case '+': result_10 = number1_10 + number2_10; break;
        case '-': result_10 = number1_10 - number2_10; break;
        case '*': result_10 = number1_10 * number2_10; break;
        case '/': result_10 = number1_10 / number2_10; break;
        case '%': result_10 = number1_10 % number2_10; break;
        default : cout<<"Wrong entry!"; break;
    }

    Convert10to16( result_10 );

return 0;
}
