/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Daniel Dimitrov
* @idnumber 62384
* @task 5
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
    double a, b, c, x1, x2; // a, b, c coefficients before x
    a = SafelyInputInteger(-1000, 1000);
    b = SafelyInputInteger(-1000, 1000);
    c = SafelyInputInteger(-1000, 1000);

    double D = b*b - 4*a*c;
    if( a == 0 && b == 0 && c == 0 ) cout << "Every x is solution";
    else if ( a == 0 && b == 0 && c != 0 ) cout << "There is no solution";
    else if( a == 0 )
    {
        if( b > 0 && c < 0 ) { x1 = (c / b)*(-1); cout << sqrt(x1) << " " << "-" << sqrt(x1);}
        else if ( b < 0 && c > 0 ) { x1 = (c / b)*(-1); cout << sqrt(x1) << " " << "-" << sqrt(x1);}
        else cout << "No solution";
    }
    else if( D < 0 ) cout << "There only unreal roods";
    else if( D == 0 )
    {
        x1 = (-b) / (2 * a);
        if( x1 < 0 ) cout << "There only unreal roods";
        else cout << sqrt(x1) << " " << "-" << sqrt(x1);
    }
    else
    {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        if( x1 < 0 && x2 < 0 ) cout << "There only unreal roods";
        else if ( x1 < 0 ) cout << sqrt(x2) << " " << "-" << sqrt(x2) << " " << "and 2 unreal rood";
        else if ( x2 < 0 ) cout << sqrt(x1) << " " << "-" << sqrt(x1) << " " << "and 2 unreal rood";
        else cout << sqrt(x1) << " " << "-" << sqrt(x1) << " " << sqrt(x2) << " " << "-" << sqrt(x2);
    }

return 0;
}
