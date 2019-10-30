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
    long isbnTwo = isbn;
    //declare the variable for each digit
    int x = 0;
    //declare the variable to keep track of the sum
    int y = x;
    //isbn algorithm 
    for(int digit = 10; digit > 0; digit--)
    {
        //find the value of the last digit
        x = isbn % 10;
        //multiply it by how far the digit is into the number 
        x = x * digit;
        //shift the isbn by one place value
        isbn = isbn / 10;
        //keep track of the sum of all of the digits
        y = x + y;
        printf("%i\n", x);
        printf("  %i\n", y);
    }
    //divide the total by 11
    y = y % 11;
    printf("%i\n", y);
    //print yes or no depending on whether the ISBN is valid 
    
    if(isbn % 10 == y)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    
}
