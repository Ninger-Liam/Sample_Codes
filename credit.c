#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
bool checkNumeric(string cn);
int checkCardType(string cn);
int checkLength(string cn);
int checkSum(string cn);

int main(void)
{
    string creditNum;
    do
    {
        creditNum = get_string("Enter Your Credit Card Number:");
    }
    while (checkNumeric(creditNum) == false);


    int ct = checkCardType(creditNum);

    if (ct == 2)
    {
        int v = checkSum(creditNum);
        if (v == 10)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (ct == 3)
    {
        int a = checkSum(creditNum);
        if (a == 10)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (ct == 4)
    {
        int mc = checkSum(creditNum);
        if (mc == 10)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (ct == 1)
    {
        printf("INVALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

bool checkNumeric(string cn)
{
    int l = strlen(cn);
    if (l == 0)
    {
        return false;
    }

    for (int i = 0; i < l; i++)
    {
        if (!isdigit(cn[i]))
        {
            return false;
        }
    }
    return true;
}

int checkCardType(string cn)
{
    int l = strlen(cn);
    if (cn[0] == '4') //Visa
    {
        if (l == 13 || l == 16)
        {
            return 2;
        }
    }
    else if (cn[0] == '3') //AmEx
    {
        if (cn[1] == '4' || cn[1] == '7')
        {
            if (l == 15)
            {
                return 3;
            }
        }
    }
    else if (cn[0] == '5') //MasterCard
    {
        if (cn[1] == '1' || cn[1] == '2' || cn[1] == '3' || cn[1] == '4' || cn[1] == '5')
        {
            if (l == 16)
            {
                return 4;
            }
        }
    }
    return 1;
}

int checkSum(string cn)
{
    int l = strlen(cn);
    long ccn = atol(cn);
    int xx = 0;
    int yy = xx;
    xx = ccn % 10;
    yy += xx;
    ccn /= 10;
    int x = 0;
    int z = 0;
    int y = x + z;

    for (int i = 0, j = (l / 2); i < j; i++)
    {
        z = 0;
        x = ccn % 10;
        x *= 2;
        if (x > 9)
        {
            z = x % 10;
            x /= 10;
        }
        y = x + y + z;
        ccn /= 10;
        xx = ccn % 10;
        yy += xx;
        ccn /= 10;
    }
    y += yy;

    if (y % 10 == 0)
    {
        return 10;
    }
    else
    {
        return 0;
    }
}