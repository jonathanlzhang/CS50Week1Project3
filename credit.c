#include <cs50.h>
#include <stdio.h>

bool lungAlgo(long number);
int addDigits(int number);
int main(void)
{
    long number = get_long("credit card number?\n");
    int numerator = number/10000000000;
    int digits = 12;
    if (!(number > 9999999999999999 || number < 1000000000000))
    {
        while (numerator > 100)
        {
            numerator = numerator / 10;
            digits++;
        }
        //printf("%i\n", digits);

        string cardType = "";
        if (numerator / 10 == 4 && (digits == 13 || digits == 16))
        {
            cardType = "Visa";
        }
        else if ((numerator == 34 || numerator == 37) && digits == 15)
        {
            cardType = "Amex";
        }
        else if ((numerator > 50 && numerator < 56) && digits == 16)
        {
            cardType = "Mastercard";
        }
        else
        {
            printf("credit card invalid\n");
            return 0;
        }

        if (lungAlgo(number) == true)
        {
            printf("%s\n", cardType);
        }
        else
        {
            printf("credit card invalid\n");
        }
    }
    else
    {
        printf("credit card invalid\n");
    }
}

bool lungAlgo(long number)
{
    int sum1 = 0;
    int sum2 = 0;
    while (true)
    {
        sum1 = sum1 + (number % 10);
        //printf("%i\n", sum1);
        number = number / 10;
        if (!(number > 0))
        {
            break;
        }
        sum2 = sum2 + addDigits(number % 10);
        //printf("%i\n", sum2);
        number = number / 10;
        if (!(number > 0))
        {
            break;
        }
    }
    int lungSum = sum1 + sum2;
    //printf("%i\n%i\n%i\n", sum1, sum2, lungSum);
    if (lungSum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int addDigits(int number)
{
    int sum = 0;
    number = number * 2;
    while (number > 0)
    {
        sum = sum + number % 10;
        number = number / 10;
    }
    return sum;
}
