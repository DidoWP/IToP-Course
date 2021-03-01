/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Daniel Dimitrov Dimitrov
* @idnumber 62384
* @task 2
* @compiler GCC
*
*/
#include<iostream>

using namespace std;

int Str_size(char *str);
void Conversion_function ( int M, int L, char str[]);
bool IsStrCorrect (char str[]);

int main()
{
    int M, L;
    char str[100];

    cout << "Enter string: "; cin.getline(str, 100);

    cout << "Enter M: "; cin >> M;
    while( M < 0 || M > 20)
    {
        cout << endl << "Wrong input, enter M: ";
        cin >> M;
    }

    cout << "Enter L: "; cin >> L;
    while( L < 0 || L > Str_size(str))
    {
        cout << endl << "Wrong input, enter L: ";
        cin >> L;
    }


    if ( IsStrCorrect(str) )
    {
        Conversion_function(M,L,str);
        for(int i=0;i<Str_size(str);i++)cout<<str[i];
    }
    else
    {
        cout << str;
    }


return 0;
}
void Conversion_function ( int M, int L, char *str)
{
    int sizeStr = Str_size(str);

    for(int i=0; i < sizeStr; i++)
    {
        str[i] += M;
    }

    for (int i = sizeStr - L - 1; i >= 0; i--)
    {
        for (int j = 0; j < L; j++)
        {
            swap(str[i+j], str[i+j+1]);
        }
    }
}
bool IsStrCorrect (char str[])
{
    for( int i=0; i < Str_size(str); i++)
    {
        if( str[i] < 32 || str[i] > 126 ) return false;
    }
    return true;
}
int Str_size(char *str)
{
    int counter = 0;

    while( *str != '\0' )
    {
        counter++;
        str++;
    }
    return counter;
}
