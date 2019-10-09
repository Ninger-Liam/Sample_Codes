#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

    int days;
    long pennies;
    
    do
    {
        days = get_int("how many days this month?:\n");
    }
    while (days < 28 || days > 31);
    
    do
    {
        pennies = get_long_long("how many pennies are you starting with?:\n");
    }
    while (pennies < 1);
    
    for(int multiplier = 0; multiplier > days ; multiplier ++)
    {
        pow(2, pennies);
    }
    printf("total number of pennies: %li\n", pennies);
}
