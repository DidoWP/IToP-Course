/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Daniel Dimitrov
* @idnumber 62384
* @task 4
* @compiler GCC
*
*/
#include<iostream>
#include<stdlib.h>
#include<limits>
using namespace std;

long SafelyInputInteger(long lowerBound, long upperBound)
{
    long longNumber;

    while(true)
    {
        cout << "Enter number of seconds:"; cin >> longNumber;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if(( longNumber >= lowerBound) && (longNumber <= upperBound)) break;
    }
return longNumber;
}

int main ()
{
    int seconds;
    seconds = SafelyInputInteger(1, 65535);

    while( seconds != 0)
    {
        cout<<seconds;
        seconds--;
        for(int i = 0; i < 100000000; i++)
        {
            int Sum = Sum * i;
        }
        system("cls");
    }
}
