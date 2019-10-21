#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

    int height;
    int row;
    int bricks;
    
    do
    {
        height = get_int("height:");
    }
    while (height < 1 || height > 8);
    
    for(row = 0; row < height; row++)
    {
        for(bricks = 0; bricks < height; bricks++)
        {
            if (bricks + row < height - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
          printf("\n");
    }
    
}
