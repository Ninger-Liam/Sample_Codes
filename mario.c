#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

    int height;
    int row;
    int bricks;
    int dots = height - row;
    do
    {
        height = get_int("height:");
    }
    while (height < 1 || height > 8);
    
    for(row = 0; row < height; row++)
    {
        for(bricks = 0; bricks < row + 1; bricks++)
        {
            
            printf("#");

        }
          printf("\n");
    }
    
}

    
