/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Daniel Dimitrov Dimitrov
* @idnumber 62384
* @task 4
* @compiler GCC
*
*/
#include<iostream>
using namespace std;

void FindMinWords(char* str);
int Str_size(char *str);

int main ()
{
    char str[100];
    cin.getline(str,101);
    FindMinWords(str);
return 0;
}

void FindMinWords(char* str)
{
	int len=0;
	int counter=0;
	int minLen=INT_MAX;
	bool check=true;

	for(int i=0;i<Str_size(str);i++)
	{
		if (str[i]==' ' || str[i]=='\t' || str[i]=='\n')continue;
		check=true;
		len=0;
		do
		{
			len++;
			if(!( (str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z') || str[i]=='-' || str[i]=='_'))check=false;
			i++;
		} while (str[i]!=' ' && str[i]!='\n' && str[i]!='\t' && str[i]!='\0' );

		if (check==true)
		{
			if(len<minLen)
            {
                minLen=len;
                counter=1;
            }
			else if(len==minLen)counter++;
		}
	}
	cout<<counter<<endl;
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
