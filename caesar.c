#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage <key>\n");
        return 1;
    }

    string plainText = get_string("plaintext: ");
    int k = atoi(argv[1]);
    int num;
    int ciph;

    printf("ciphertext: ");
    for(int i = 0, l = strlen(plainText); i < l; i++)
    {
        if (isalpha (plainText[i]))
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
    printf("\n");
}