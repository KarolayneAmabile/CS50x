#include <stdio.h>

int sizeOf (long long int number);
long long int checkSum(long long int number, int size);

int main(void)
{
    long long int number = 0;
    int size = 0;
    //printf("Number: ");
    //scanf("%li", &number);

    number = 4003600000000014;
    size = sizeOf(number);
    if (size != 15 || size != 16 || size != 13)
    {
        printf("INVALID\n");
        return 1;
    }
}

int sizeOf (long long int number)
{
    int size = 0;
    while (number > 0)
    {
        number = number / 10;
        size++;
    }
    return size;
}

long long int checkSum(long long int number, int size)
{
    long long int temp[size] = number;
}


