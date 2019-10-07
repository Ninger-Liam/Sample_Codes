#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{   
    
    float dollars;
    
    do
    {
        dollars = get_float("change owed:\n");
    }
    while (dollars < 0);
    
    int cents = round(dollars * 100);
    
    int quarters = 0;
    int dimes = 0;   
    int nickels = 0;
    int pennies = 0;
    
    while (cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }
    
    while (cents < 25 && cents >= 10)
    {
        dimes++;
        cents = cents - 10;
    }
    
    while (cents < 10 && cents >= 5)
    {
        nickels++;
        cents = cents - 5;
    }
    
    while (cents < 5 && cents >= 1)
    {
        pennies++;
        cents = cents - 1;
    }
    
    printf("quarters = %i\n" , quarters);
    printf("dimes = %i\n" , dimes);
    printf("nickels = %i\n" , nickels);
    printf("pennies = %i\n" , pennies);
    printf("total coins = %i\n", quarters + dimes + nickels + pennies);
}
