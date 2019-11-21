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

    string plain = get_string("plaintext: ");
    string key = argv [1];
    int n = strlen(key);
    int ii = 0;

    if (!isalpha(key))
    {
        return 1;
    }
    printf("ciphertext: ");
        for (int i = 0; i < strlen(plain); i++)
        {

            if (isalpha(plain[i]))
            {
                if (islower(key[ii % n]))
                {
                    key[ii % n] = key[ii % n] - 97;
                }
                else if (isupper(key[ii % n]))
                {
                    key[ii % n] = key[ii % n] - 65;
                }

                if (islower(plain[i]))
                {
                    plain[i] -= 97;
                    plain[i] += key[ii % n];
                    plain[i] = plain[i] % 26;
                    plain[i] += 97;
                    printf("%c", plain[i]);
                }
                else if(isupper(plain[i]))
                {
                    plain[i] -= 65;
                    plain[i] += key[ii % n];
                    plain[i] = plain[i] % 26;
                    plain[i] += 65;
                    printf("%c", plain[i]);
                }
                ii++;
            }
            else
            {
                printf("%c", plain[i]);
            }
        }
    printf("\n");
    return 0;
}

