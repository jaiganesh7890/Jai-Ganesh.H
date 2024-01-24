//16.Write a C program to check if a given string is valid or not.
//The string contains the characters '(', ')', '{', '}', '[' and ']'.
//The string is valid if the open brackets must be closed with the same type of bracket and in the correct order.
//Expected Output: false

#include <stdio.h>
#include <stdbool.h>

bool isValidString(char* str)
{

}

int main()
{
    char str[] = "({[]})";

    if (isValidString(str))
    {
        printf("The string is valid.\n");
    } else
    {
        printf("The string is not valid.\n");
    }

    return 0;
}
