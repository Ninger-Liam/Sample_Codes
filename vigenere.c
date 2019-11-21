#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere <keyword>");
        return 1;
    }

    string key = argv [1];
    for (int i = 0; i < strlen(key); i++)
    {
        printf("%c", key[i]);
    }
}

