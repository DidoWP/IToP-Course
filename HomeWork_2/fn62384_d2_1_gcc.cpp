/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Daniel Dimitrov Dimitrov
* @idnumber 62384
* @task 1
* @compiler GCC
*
*/
#include<iostream>
using namespace std;

const int MAX_LENGTH = 5; // Max length is 3 + one position for the determinant 0

int RowNumber(char str[MAX_LENGTH]);
int Str_size(char str[MAX_LENGTH]);

int main ()
{
    char str[MAX_LENGTH];
    int i = 0;
    cout << "//If the input includes only capitals but the chars are more than 3 the answer will be based on the first 3.\n" ;
    do {
        cin.get(str[i]);
        if( (str[i] < 'A' || str[i] > 'Z') && str[i] != '\n') { cout << "Wrong input!"; return 0;}
        i++;
        str[i] = '\0';
    }
    while ( str[i-1] != '\n' && str[i-1] != ' ' && i < MAX_LENGTH - 1);
    str[i-1] = '\0';

    cout << RowNumber(str);

return 0;
}

int RowNumber(char str[MAX_LENGTH])
{
    const int alphabet_ = 26;
    int _size = Str_size(str);
    switch( _size )
    {
        case 1: return (str[0]-'A'+1); break;
        case 2: return ((str[0]-'A'+1)*alphabet_+(str[1]-'A'+1)); break;
        case 3: return (((str[0]-'A'+1)*alphabet_*alphabet_)+(str[1]-'A'+1)*alphabet_+(str[2]-'A'+1)); break;
    }
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
