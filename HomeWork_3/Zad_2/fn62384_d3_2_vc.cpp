/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Daniel Dimitrov Dimitrov
* @idnumber 62384
* @task 2
* @compiler VC
*
*/
#include<iostream>
#include <algorithm>

using namespace std;

void ReverseNumber(char*);
char* BiggerNumber(char*, char*);
void RemuveMinus(char*);
char* SumLongNumbers(char*, char*);
char* SubLongNumbers(char*, char*);
char* MultiplyLongNumbers(char*, char*);
int StrSize(char*);

char digits[] = "0123456789";
int const MAX_NUM_LENGTH = 100;
char buffer[MAX_NUM_LENGTH + 2];

int main()
{
    char longNumber_1[MAX_NUM_LENGTH + 2] = { '\0' }; // i am adding 2 places one for determinate zero
    char longNumber_2[MAX_NUM_LENGTH + 2] = { '\0' }; // and one for '-' sign
    char operation;

    cin.get(operation); cin.get();
    cin.getline(longNumber_1, MAX_NUM_LENGTH);
    cin.getline(longNumber_2, MAX_NUM_LENGTH);

    int num_1_size = StrSize(longNumber_1);
    int num_2_size = StrSize(longNumber_2);


    if (operation == '+')
    {
        if (longNumber_1[0] != '-')
        {
            if (longNumber_2[0] != '-')
            {
                cout << SumLongNumbers(longNumber_1, longNumber_2);
            }
            else
            {
                RemuveMinus(longNumber_2);
                if (BiggerNumber(longNumber_1, longNumber_2) == longNumber_1)
                    cout << SubLongNumbers(longNumber_1, longNumber_2);

                else cout << "-" << SubLongNumbers(longNumber_2, longNumber_1);
            }
        }
        else
        {
            if (longNumber_2[0] != '-')
            {
                RemuveMinus(longNumber_1);
                if (BiggerNumber(longNumber_1, longNumber_2) == longNumber_1)
                    cout << "-" << SubLongNumbers(longNumber_1, longNumber_2);

                else cout << SubLongNumbers(longNumber_2, longNumber_1);
            }
        }
    }
    else if (operation == '-')
    {
        if (longNumber_1[0] != '-')
        {
            if (longNumber_2[0] != '-')
            {
                if (BiggerNumber(longNumber_1, longNumber_2) == longNumber_1)
                    cout << SubLongNumbers(longNumber_1, longNumber_2);

                else cout << "-" << SubLongNumbers(longNumber_2, longNumber_1);
            }
            else
            {
                RemuveMinus(longNumber_2);
                cout << SumLongNumbers(longNumber_1, longNumber_2);
            }
        }
        else
        {
            if (longNumber_2[0] != '-')
            {
                RemuveMinus(longNumber_1);
                if (BiggerNumber(longNumber_1, longNumber_2) == longNumber_1)
                    cout << "-" << SumLongNumbers(longNumber_1, longNumber_2);

                else cout << SubLongNumbers(longNumber_2, longNumber_1);
            }
            else
            {
                RemuveMinus(longNumber_1);
                RemuveMinus(longNumber_2);
                if (BiggerNumber(longNumber_1, longNumber_2) == longNumber_1)
                    cout << "-" << SubLongNumbers(longNumber_1, longNumber_2);

                else cout << SubLongNumbers(longNumber_2, longNumber_1);
            }
        }
    }
    else if (operation == '*')
    {
        if (longNumber_1[0] != '-' && longNumber_2[0] != '-')
            cout << MultiplyLongNumbers(longNumber_1, longNumber_2);

        else if (longNumber_1[0] == '-' && longNumber_2[0] == '-')
        {
            RemuveMinus(longNumber_1);
            RemuveMinus(longNumber_2);
            cout << MultiplyLongNumbers(longNumber_1, longNumber_2);
        }
        else if (longNumber_1[0] == '-' && longNumber_2[0] != '-')
        {
            RemuveMinus(longNumber_1);
            cout << "-" << MultiplyLongNumbers(longNumber_1, longNumber_2);
        }
        else if (longNumber_1[0] != '-' && longNumber_2[0] == '-')
        {
            RemuveMinus(longNumber_2);
            cout << "-" << MultiplyLongNumbers(longNumber_1, longNumber_2);
        }
    }
    else cout << "Wrong input!";

    return 0;
}

void ReverseNumber(char* LongNum)
{
    int length = StrSize(LongNum);

    for (int i = 0; i < length / 2; i++)
        swap(LongNum[i], LongNum[length - i - 1]);
}
char* BiggerNumber(char* LongNum1, char* LongNum2)
{
    int num1Size = StrSize(LongNum1), num2Size = StrSize(LongNum2);

    if (num1Size > num2Size) return LongNum1;
    if (num1Size < num2Size) return LongNum2;
    if (num1Size == num2Size)
    {
        for (int i = 0; i < num1Size; i++)
        {
            if (LongNum1[i] > LongNum2[i]) return LongNum1;
            if (LongNum2[i] > LongNum1[i]) return LongNum2;
        }
    }
}
void RemuveMinus(char* LongNum)
{
    int numSize = StrSize(LongNum);

    for (int i = 0; i < numSize - 1; i++)
    {
        LongNum[i] = LongNum[i + 1];
    }
    LongNum[numSize - 1] = '\0';
}
char* SumLongNumbers(char* LongNum1, char* LongNum2)
{
    int NumSize1, NumSize2, DigitsSize;
    int addend1, addend2, Sum;
    int overflow = 0;

    NumSize1 = StrSize(LongNum1);
    NumSize2 = StrSize(LongNum2);
    DigitsSize = StrSize(digits);

    ReverseNumber(LongNum1);
    ReverseNumber(LongNum2);

    int longerSize = max(NumSize1, NumSize2);

    for (int i = 0; i < longerSize; i++)
    {
        for (int j = 0; j < DigitsSize; j++)
        {
            if (LongNum1[i] == digits[j]) addend1 = j;
            if (LongNum2[i] == digits[j]) addend2 = j;
        }
        Sum = addend1 + addend2 + overflow;

        if (Sum <= 9) {
            buffer[i] = char(Sum + '0');
            overflow = 0;
        }
        else {
            buffer[i] = char(Sum - 10 + '0');
            overflow = 1;
        }
        addend1 = 0;
        addend2 = 0;

        if (overflow == 1 && i == longerSize - 1)
            buffer[i + 1] = '1';
    }

    ReverseNumber(buffer);

    return buffer;
}
char* SubLongNumbers(char* LongNum1, char* LongNum2)
{
    int NumSize1, NumSize2, DigitsSize;
    int addend1, addend2, Sum;
    int overflow = 0;

    NumSize1 = StrSize(LongNum1);
    NumSize2 = StrSize(LongNum2);
    DigitsSize = StrSize(digits);

    ReverseNumber(LongNum1);
    ReverseNumber(LongNum2);

    int longerSize = max(NumSize1, NumSize2);

    for (int i = 0; i < longerSize; i++)
    {
        for (int j = 0; j < DigitsSize; j++)
        {
            if (LongNum1[i] == digits[j]) addend1 = j;
            if (LongNum2[i] == digits[j]) addend2 = j;
        }
        Sum = addend1 - addend2 - overflow;

        if (Sum >= 0) {
            buffer[i] = char(Sum + '0');
            overflow = 0;
        }
        else {
            buffer[i] = char(10 + Sum + '0');
            overflow = 1;
        }
        addend1 = 0;
        addend2 = 0;

        if (overflow == 1 && i == longerSize - 1)
            buffer[i + 1] = '1';
    }
    int bufferSize = StrSize(buffer);
    while (buffer[bufferSize - 1] == '0')
    {
        buffer[bufferSize - 1] = '\0';
        bufferSize--;
    }
    ReverseNumber(buffer);

    return buffer;
}
char* MultiplyLongNumbers(char* LongNum1, char* LongNum2)
{
    ReverseNumber(LongNum1);
    ReverseNumber(LongNum2);
    int num1_size = StrSize(LongNum1);
    int num2_size = StrSize(LongNum2);

    int ans_size = num1_size + num2_size;
    
    int* ans = new int[ans_size];
    for (int i = 0; i < ans_size; i++)
    {
        ans[i] = 0;
    }


    for (int i = 0; i < num1_size; i++)
    {
        for (int j = 0; j < num2_size; j++)
        {
            int p = (int)(LongNum1[i]) - '0';
            int q = (int)(LongNum2[j]) - '0';

            ans[i + j] += p * q;
            ans[i + j + 1] = ans[i + j + 1] + ans[i + j] / 10;
            ans[i + j] %= 10;
        }
    }

    for (int i = 0; i < ans_size; ++i)
        buffer[i] = ans[i] + '0';

    int bufferSize = StrSize(buffer);

    while (buffer[bufferSize - 1] == '0')
    {
        buffer[bufferSize - 1] = '\0';
        bufferSize--;
    }
    ReverseNumber(buffer);
    delete[] ans;

    return buffer;
}
int StrSize(char* str)
{
    int counter = 0;
    while (*str != '\0')
    {
        counter++;
        str++;
    }
    return counter;
}