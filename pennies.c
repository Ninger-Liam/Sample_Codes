#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

    int days;
    long PenniesStart;
    long PenniesEnd = 1;
    int day;
    
    do
    {
        days = get_int("how many days this month?:\n");
    }
    while (days < 28 || days > 31);
    
    do
    {
        PenniesStart = get_long_long("how many pennies are you starting with?:\n");
    }
    while (PenniesStart < 1);
    
    for(day = 0; day < days ; day++)
    {
        PenniesEnd = PenniesEnd * 2;
    }
    
    double penniestotal = (double)PenniesEnd / 100;
    
    printf("total number of pennies: $%.2f\n", penniestotal);
    
}
