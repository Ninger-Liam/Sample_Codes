#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //declare variables height, row, and bricks
    int height;
    int row;
    int bricks;

    //make sure user inputs positive values 1-8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //set a counter for each row that's being printed
    for (row = 0; row < height; row++)
    {
        //left pyramid's counter for how many bricks need to be printed
        for (bricks = 0; bricks < height; bricks++)
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
        //the space in between the two hal pyramids
        printf("  ");

        //the right pyramids counter for how many bricks ned to be printed
        for (bricks = 0; bricks < row + 1; bricks++)
        {
            printf("#");
        }
        printf("\n");
    }


}