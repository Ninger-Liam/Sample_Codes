#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //make sure user inputs right amount of values
    if (argc != 4)
    {
        printf("Usage <first value> <operation symbol> <second value>\n");
        return 1;
    }
    //conert chars into floats
    float firstNum = atof(argv[1]);
    float secNum = atof(argv[3]);
    float total;
    //check if it's addition
    if (argv[2][0] == '+')
    {
        total = firstNum + secNum;
        printf("%f\n", total);
    }
    //check if it's subtraction
    else if (argv[2][0] == '-')
    {
        total = firstNum - secNum;
        printf("%f\n", total);
    }
    //check if it's multiplication
    else if (argv[2][0] == 'x')
    {
        total = firstNum * secNum;
        printf("%f\n", total);
    }
    //check if it's division
    else if (argv[2][0] == '/')
    {
        total = firstNum / secNum;
        printf("%f\n", total);
    }
    //check if user wants to find the remainder of a division problem
    else if (argv[2][0] == '%')
    {
        int rem = firstNum / secNum;
        total = firstNum - (secNum * rem);
        printf("%f\n", total);
    }
    //stop program if opperation is invalid
    else if (argv[2][0] != '+' || argv[2][0] != '-' || argv[2][0] != 'x' || argv[2][0] != '/' || argv[2][0] != '%')
    {
        printf("Invalid operation\n");
        return 1;
    }
}