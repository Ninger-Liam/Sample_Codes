// Greets a user by their name

#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    //if statment to make sure that the user inputs the right amount of data
    if (argc != 2)
    {
        printf("Usage: ./hello <name>\n");
        return 1;
    }
    
    printf("Hello, %s!\n", argv[1]);
}
