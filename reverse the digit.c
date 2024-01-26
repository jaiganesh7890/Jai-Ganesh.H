Write a C program to reverse the digits of a 32-bit signed integer. >
Expected Output:
Original integer:  123
Reverse integer :  321

#include <stdio.h>

int reverseInteger(int num)
{
    int reversedNum = 0;
    while (num != 0)
    {
        int remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        num /= 10;
    }
    return reversedNum;
}

int main()
{
    int num = 123;
    printf("Original integer: %d\n", num);
    int reversedNum = reverseInteger(num);
    printf("Reverse integer: %d\n", reversedNum);
    return 0;
}
