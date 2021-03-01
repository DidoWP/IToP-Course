/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Daniel Dimitrov
* @idnumber 62384
* @task 2
* @compiler GCC
*
*/
#include<iostream>
#include<limits>
using namespace std;

long SafelyInputInteger(long lowerBound, long upperBound)
{
    long longNumber;

    while(true)
    {
        cout << "Enter number of days:"; cin >> longNumber;
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

int main()
{
    int days, yearsCounter = 0;
    days = SafelyInputInteger(0,1000000);

    if(days == 0){cout<<"There is no zero day"; return 0;}
    for(int year = 1; days > 0; year++)
    {
        if( year % 4 == 0)
        {
            if( year % 100 == 0 && year % 400 != 0)
            {
                days -= 365;
                yearsCounter++;
            }
            else
            {
                days -= 366;
                yearsCounter++;
            }
        }
        else
        {
            days -= 365;
            yearsCounter++;
        }
    }

    cout<<yearsCounter;

return 0;
}
