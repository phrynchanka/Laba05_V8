/*Вариант 8. Напечатать без повторения слова текста, у которых первая и последняя буквы совпадают*/
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int FindLen( char str[] );
bool CheckOfRepeat( int FirstIndex, int LastIndex, char str[] );
void TypeWord( int FirstIndex, int LastIndex, char str[] );
int main()
{
    const int StringLength = 500;
    char str[StringLength];
    int FirstIndex = 0, LastIndex, i = 0;
    cout << " Enter the string: "<< endl;
    gets( str );
    int lenstr = FindLen( str );
    cout << "Output repeating words:" << endl;
    while( i < lenstr )
    {
        if( str[i] == ' ' && str[i + 1] != ' ')
        {
            FirstIndex = i + 1;
        }
        if( str[i] != ' ' && ( str[i + 1] == ' ' || str[i + 1] == '\0' ) && str[i] == str[FirstIndex] && !CheckOfRepeat( FirstIndex, i, str ) )
        {
            TypeWord( FirstIndex, i, str );
            FirstIndex = i ;
        }
        ++ i;
    }
    return 0;
}
int FindLen( char str[] )
{
    int k = 0;
    while( str[k] != '\0' )
    {
        ++ k ;
    }
    return k;
}
bool CheckOfRepeat( int FirstIndex, int LastIndex, char str[] )
{
    int indexOfFirstSymbol = 0;
    for( int i = 0; i < FirstIndex; ++i )
    {
        if(str[i] == ' ')
        {

            int j = 0;
            while( j <= LastIndex - FirstIndex && str[indexOfFirstSymbol + j] == str[FirstIndex + j])
            {
                ++ j;
            }
            if(j == LastIndex - FirstIndex + 1)
            {
                return true;
            }
            else
            {
                indexOfFirstSymbol = i + 1;
            }
        }
    }
    return false;
}
void TypeWord( int FirstIndex, int LastIndex, char str[] )
{
    cout << " ";
    for( int i = FirstIndex; i < LastIndex + 1; ++i )
    {
        cout << str[i];
    }
}

