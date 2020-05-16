#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("How many rows are there?\n");
    }
    while (height < 1 || height > 8);
    
    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j < height; j++)
        {
            if (i + j < height - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  ");
        for (int j = 0; j < height; j++)
        {
            if (j <= i)
            {
                printf("#");
            }
        }
        printf("\n");
    }
    
}