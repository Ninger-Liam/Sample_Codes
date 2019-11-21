#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>


int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere <keyword>\n");
        return 1;
    }

    string plain = get_string("plaintext: ");
    string key = argv [1];
    int n = strlen(key);
    // int ii = 0;

    for (int j = 0, p = strlen(key); j < p; j++)
    {
        if (!isalpha(key[j]))
        {
            printf("Usage: ./vigenere <keyword>\n");
            return 1;
        }
    }

    printf("ciphertext: ");
        for (int i = 0, ii = 0, l = strlen(plain); i < l; i++)
        {

            if (isalpha(plain[i]))
            {
                // if (islower(key[ii % n]))
                // {
                //     key[ii % n] = key[ii % n] - 97;
                // }
                // else if (isupper(key[ii % n]))
                // {
                //     key[ii % n] = key[ii % n] - 65;
                // }

                if (islower(plain[i]))
                {
                    // plain[i] -= 97;
                    // plain[i] += key[ii % n];
                    // plain[i] = plain[i] % 26;
                    // plain[i] += 97;
                    printf("%c", (plain[i] - 'a' + toupper(key[ii]) - 'A') % 26 + 'a');
                }
                else if(isupper(plain[i]))
                {
                    // plain[i] -= 65;
                    // plain[i] += key[ii % n];
                    // plain[i] = plain[i] % 26;
                    // plain[i] += 65;
                    printf("%c", (plain[i] - 'A' + toupper(key[ii])- 'A') % 26 + 'A');
                }
                ii = (ii + 1) % n;
            }
            else
            {
                printf("%c", plain[i]);
            }
        }
    printf("\n");
    return 0;
}

