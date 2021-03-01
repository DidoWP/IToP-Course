/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Daniel Dimitrov
* @idnumber 62384
* @task 6
* @compiler GCC
*
*/
#include<iostream>
#include<cmath>
#include<limits>
using namespace std;

double SafelyInputInteger(double lowerBound, double upperBound)
{
    double longNumber;

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

int main ()
{
    double x, y;  //coordinates of the point
    double z;     // distance from (0,0) to our point

    x = SafelyInputInteger(-100, 100);
    y = SafelyInputInteger(-100, 100);

    z = sqrt( x*x + y*y );

    if( x < 1 && y < 1 && x > -1 && y > -1 ) cout<<"Black";
    else if ( x==1 && y<=1 && y>=-1 || x==-1 && y<=1 && y>=-1 || y==-1 && x<=1 && x>=-1 || y==1 && x<=1 && x>=-1 ) cout<<"Undefined";
    else if ( z < 2 ) cout<<"White";
    else if ( z == 2 ) cout<<"Undefined";
    else if ( z < 3 ) cout<<"Black";
    else if ( z == 3 ) cout<<"Undefined";
    else cout<<"Outside";

return 0;
}
