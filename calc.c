#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 4)
    {
        printf("Usage <first value> <operation symbol> <second value>\n");
        return 1;
    }

    float firstNum = atof(argv[1]);
    float secNum = atoi(argv[3]);
    float total;

    if (argv[2][0] == '+')
    {
        total = firstNum + secNum;
        printf("%f", total);
    }
    else if (argv[2][0] == '-')
    {
        total = firstNum - secNum;
        printf("%f", total);
    }
    else if (argv[2][0] == 'x')
    {
        total = firstNUm * secNum;
        printf("%f", total);
    }
    else if (argv[2][0] == '/')
    {
        total = firstNum / secNum
        printf("%f", total);
    }
    else if (argv[2][0] == '%')
    {
        int rem = firstNum / secNum;
        total = firstNum - (secNum * total);
        printf("%f", total);
    }
}