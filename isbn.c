#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //declare the isbn variable
    long isbn;
    
    //make sure the user inputs a positive integer
    do
    {
        isbn = get_long("ISBN:");
    }
    while (isbn < 0);
    
    //declare each digit as a variable
    int frist;
    int second;
    int third;
    int fourth;
    int fifth;
    int sixth;
    int seventh;
    int eighth;
    int ninth;
    int tenth;
    int x = 0;
    int y = x;
    //find the value of each digit
    for(int digit = 10; digit > 0; digit--)
    {
        x = isbn % 10;
        x = x * digit;
        isbn = isbn / 10;
        y = x + y;
        printf("%i\n", x);
        printf("  %i\n", y);
    }
    y = y / 11;
    printf("%i\n", y);
    if(y % 10 == 0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    
    //multiply each digit by which number digit it is
    
    //print yes or no depending on whether the ISBN is valid
    
    
    
}
