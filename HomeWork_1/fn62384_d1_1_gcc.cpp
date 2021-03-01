/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Daniel Dimitrov
* @idnumber 62384
* @task 1
* @compiler GCC
*
*/
#include<iostream>
#include <limits>

using namespace std;

long SafelyInputInteger(long lowerBound, long upperBound)
{
    long longNumber;

    while(true)
    {
        cout << "Input a number:"; cin >> longNumber;
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

int LengthOfNumber(int number)
{
    int numberLength = 0;

    while ( number != 0 )
    {
        number /= 10;
        numberLength++;
    }
    return numberLength;
}

int main ()
{
    long long number;
    int numberLength;
    bool breakPoint = false;

    number = SafelyInputInteger(-2147483648, 2147483647);

    numberLength = LengthOfNumber(number);

    for(int i = 0; i < numberLength; i++ )
    {
        int lastDigit = number % 10;
        int _number = number;
        int _numberLength = numberLength;

        while( _numberLength != 0)
        {
            int j = _number/10%10;
            if( lastDigit == j )
            {
                cout<<"Yes";
                breakPoint = true;
                break;
            }

            _number /= 10;
            _numberLength--;
        }
        if ( breakPoint == true ) break;

        number /= 10;
    }

    if ( breakPoint == false ) cout<<"No";

return 0;
}

