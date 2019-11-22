#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

long checkVisa(string visa);
long checkAmEx(string amex);
long checkMstrCrd(string mstrCrd);
long checkCardType(string cn);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./credit <credit card number>");
    }

    long creditNum = atol(argv[1]);
    int ct = checkCardType(argv[1]);
    if (ct == 2)
    {
        int v = checkVisa(argv[1]);
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
        int a = checkAmEx(argv[1]);
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
        int mc = checkMstrCrd(argv[1]);
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

long checkCardType(string cn)
{
    //Visa
    if (cn[0] == '4')
    {
        return 2;
    }
    //AmEx
    else if (cn[0] == '3')
    {
        if (cn[1] == '4' || cn[1] == '7')
        {
            return 3;
        }
        else
        {
            return 1;
        }
    }
    //MasterCard
    else if (cn[0] == '5')
    {
        if (cn[1] == '1' || cn[1] == '2' || cn[1] == '3' || cn[1] == '4' || cn[1] == '5')
        {
            return 4;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
}

long checkVisa(string visa)
{    int l = strlen(visa);

    if (l != 13 && l != 16)
    {
        //card is invalid
        return 1;
    }

    long cn = atol(visa);
    int xx = 0;
    int yy = xx;
    xx = cn % 10;
    yy += xx;
    cn /= 10;
    int x = 0;
    int z = 0;
    int y = x + z;

    if (l == 13)
    {
        for (int i = 0; i < 6; i++)
        {
            z = 0;
            x = cn % 10;
            x *= 2;
            if (x > 10)
            {
                z = x % 10;
                x /= 10;
            }
            y = x + y + z;
            cn /= 10;
            xx = cn % 10;
            yy += xx;
            cn/= 10;
        }
    }
    else if (l == 16)
    {
        for (int i = 0; i < 8; i++)
        {
            z = 0;
            x = cn % 10;
            x *= 2;
            if (x > 10)
            {
                z = x % 10;
                x /= 10;
            }
            y = x + y + z;
            cn /= 10;
            xx = cn % 10;
            yy += xx;
            cn/= 10;
        }
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

long checkAmEx(string amex)
{    int l = strlen(amex);

    if (l != 15)
    {
        //card is invalid
        return 1;
    }

    long cn = atol(amex);
    int xx = 0;
    int yy = xx;
    xx = cn % 10;
    yy += xx;
    cn /= 10;
    int x = 0;
    int z = 0;
    int y = x + z;

    for (int i = 0; i < 7; i++)
    {
        z = 0;
        x = cn % 10;
        x *= 2;
        if (x > 10)
        {
            z = x % 10;
            x /= 10;
        }
        y = x + y + z;
        cn /= 10;
        xx = cn % 10;
        yy += xx;
        cn/= 10;
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

long checkMstrCrd(string mstrCrd)
{    int l = strlen(mstrCrd);

    if (l != 16)
    {
        //card is invalid
        return 1;
    }

    long cn = atol(mstrCrd);
    int xx = 0;
    int yy = xx;
    xx = cn % 10;
    yy += xx;
    cn /= 10;
    int x = 0;
    int z = 0;
    int y = x + z;

    for (int i = 0; i < 8; i++)
    {
        z = 0;
        x = cn % 10;
        x *= 2;
        if (x > 10)
        {
            z = x % 10;
            x /= 10;
        }
        y = x + y + z;
        cn /= 10;
        xx = cn % 10;
        yy += xx;
        cn/= 10;
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