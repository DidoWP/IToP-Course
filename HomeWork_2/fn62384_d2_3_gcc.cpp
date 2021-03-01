/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Daniel Dimitrov Dimitrov
* @idnumber 62384
* @task 3
* @compiler GCC
*
*/
#include<iostream>
using namespace std;

void Copy_smaller_string_in_larger(char arr1[], char arr2[]);
int Str_size(char *arr);
int main ()
{
    char arr1[100];
    char arr2[100];

    cin.getline(arr1,101);
    cin.getline(arr2,101);

    Copy_smaller_string_in_larger(arr1, arr2);
    if( Str_size(arr1) > Str_size(arr2) )
        cout << arr1;
    else cout << arr2;


return 0;
}
void Copy_smaller_string_in_larger(char arr1[], char arr2[])
{
    int size1 = Str_size(arr1);
    int size2 = Str_size(arr2);
    int size11 = size1;
    int size22 = size2;
    char escapeSymbols[] = "abtrn";

    for(int i=0; i < size1; i++)    //checking if there are any escape symbols in arr1
    {
        if(arr1[i] == '\\')
        {
            for(int j=0; j<5; j++)  //5 is the length of the escapeSymbols array
            {
                if( arr1[i+1] == escapeSymbols[j]) size11--;
            }
        }
    }
    for(int i=0; i < size2; i++)    //checking if there are any escape symbols in arr2
    {
        if(arr2[i] == '\\')
        {
            for(int j=0; j<5; j++)  //5 is the length of the escapeSymbols array
            {
                if( arr2[i+1] == escapeSymbols[j]) size22--;
            }
        }
    }
    if ( size11 <= size22 )
    {
        for(int i = 0; i < size22; i+=size11)
        {
            for(int j = 0; j < size11; j++)
            {
                arr2[j+i] = arr1[j];

            }
        }
        if( Str_size(arr2) > size22 )
        {
            for(int i = Str_size(arr2); i >= size22; i--)
                arr2[i] = '\0';
        }
    }
    else
    {
        for(int i = 0; i < size11; i+=size22)
        {
            for(int j = 0; j < size22; j++)
            {
                arr1[j+i] = arr2[j];
            }
        }
        if( Str_size(arr1) > size11 )
        {
            for(int i = Str_size(arr1); i >= size11; i--)
                arr1[i] = '\0';
        }
    }
}
int Str_size(char *arr)
{
    int counter = 0;
    while( *arr != '\0')
    {
        counter++;
        arr++;
    }
return counter;
}
