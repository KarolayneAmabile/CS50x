#include <stdio.h>
#include <stdbool.h>

int getSize(long long int number);
int get_Digits(long long number, bool isSecond);
int multiplyByTwo(int digit);
bool isValidNum(long long int number);
int getCard (long long int number, int size);

int main(void)
{
    long long int number = 0;
    printf("Number: ");
    scanf("%lli", &number);
    int size = (getSize(number));
    if (!(size == 13 || size == 15 || size == 16)) 
    {
        printf("INVALID\n");
        return 1;
    }
    if (isValidNum(number) == false)
    {
        printf("INVALID\n");
        return 2;
    }
    getCard(number, size);
    return 0;
}

int getSize(long long int number)
{
    int size = 0;
    do 
    {
        number = number / 10;
        size++;
    } 
    while (number > 0);
    return size;
}

int get_Digits(long long number, bool isSecond)
{
    int sum = 0;
    bool multiplySecondDigit = isSecond;
    while (number > 0)
    {
        if (isSecond == false)
        {
            int last_digit = number % 10;
            if (multiplySecondDigit == true)
            {
                sum += multiplyByTwo(last_digit);
            }
            else
            {
                sum += last_digit;
            }
        }
        number = number / 10;
        isSecond = !isSecond;
    }
    return sum;
}

int multiplyByTwo(int digit)
{
    digit *= 2;
    if (digit > 10)
    {
        int n1 = 0, n2 = 0;
        n1 = digit / 10;
        n2 = digit % 10;
        digit = n1 + n2;
    }
    return digit;
}

bool isValidNum (long long int number)
{
    bool valid = false;
    int sum = get_Digits(number, true) + get_Digits(number, false);
    if (sum % 10 == 0)
    {
        valid = true;
    }
    return valid;
}

int getCard (long long int number, int size)
{
    if (size == 15)
    {
        number /= 10000000000000;
        if (number == 34 || number == 37)
        {
            printf("AMEX\n");
            return 0;  
        }
    } 
    if (size == 16) 
    {
        number /= 100000000000000;
        if (number == 51 || number == 52 || number == 53 || number == 54 || number == 55)
        {
            printf("MASTERCARD\n");
            return 0; 
        }
    }
    if (size == 13 || size == 16) 
    {
        while (number > 10)
        {
            number /= 10;
        } 
        if (number == 4)
        {
            printf("VISA\n");
            return 0;
        }        
    }
    printf("INVALID\n");
    return 0;
}
