#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

    int days;
    long penniesStart;
    long penniesEnd = 0;
    int day;
    
    do
    {
        days = get_int("how many days this month?:\n");
    }
    while (days < 28 || days > 31);
    
    do
    {
        penniesStart = get_long_long("how many pennies are you starting with?:\n");
    }
    while (penniesStart < 1);
    
    for(day = 0; day < days ; day++)
    {
        penniesEnd += penniesStart * pow(2, day);
    }
    
    double penniesTotal = (double)penniesEnd / 100;
    
    printf("$%.2f\n", penniesTotal);
    
}
