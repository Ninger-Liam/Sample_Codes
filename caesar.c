#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//make the user input arguments in the command line
int main(int argc, string argv[])
{
    //make sure the user did it right
    if (argc != 2)
    {
        printf("Usage <key>\n");
        return 1;
    }
    if (isalpha(argv[1]))
    {
        printf("Usage <key>\n");
        return 1;
    }
    //ask the user for the phrase to encrypt
    string plainText = get_string("plaintext: ");
    //change the argument to an int and declare variables
    int k = atoi(argv[1]);
    int num;
    int ciph;

    printf("ciphertext: ");
    //encryptor code
    for (int i = 0, l = strlen(plainText); i < l; i++)
    {
        //check if the character is alphabetical
        if (isalpha(plainText[i]))
        {
            if (isupper (plainText[i]))
            {
              num = plainText[i] - 65;
              num += k;
              ciph = num % 26;
              ciph += 65;
              printf("%c", (char)ciph);
            }
            else if (islower (plainText[i]))
            {
              num = plainText[i] - 97;
              num += k;
              ciph = num % 26;
              ciph += 97;
              printf("%c", (char)ciph);
            }
        }
        else
        {
            printf("%c", plainText[i]);
        }
    }
    //new line
    printf("\n");
}