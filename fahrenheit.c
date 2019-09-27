#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for C
    float C = get_float("C: ");
    
    float F = ((C * 9) / 5) + 32;
    
    printf("%.1F\n", F);
}
