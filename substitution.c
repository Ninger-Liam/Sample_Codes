#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define ARRAY_SIZE 26

bool validate(string key);

int main(int argc, string argv[])
{
    if (argc != 2) 
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    if (validate(key) == true) 
    {
        char alphaLow[ARRAY_SIZE] = {"abcdefghijklmnopqrstuvwxyz"};
        char alphaUp[ARRAY_SIZE] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        char ciphAlpha[ARRAY_SIZE];
        string plain = get_string("plaintext: ");
        for (int i = 0; i < ARRAY_SIZE; i++) 
        {
            for (int j = 0; j < ARRAY_SIZE; j++) 
            {
                if (isupper(argv[1][i])) 
                {
                    if (alphaUp[j] == argv[1][i]) 
                    {
                        ciphAlpha[i] = argv[1][i];
                        break;
                    }
                }
                else 
                {
                    if (alphaLow[j] == argv[1][i]) 
                    {
                        ciphAlpha[i] = argv[1][i];
                        break;
                    }
                }
            }
        }
        printf("ciphertext: ");
        for (int k = 0; k < strlen(plain); k++) 
        {
            for (int l = 0; l < ARRAY_SIZE; l++)
            {
                if (isalpha(plain[k])) 
                {
                    if (isupper(plain[k])) 
                    {
                        if (alphaUp[l] == plain[k]) 
                        {
                            plain[k] = toupper(ciphAlpha[l]);
                            break;
                        }
                    }
                    else if (islower(plain[k])) 
                    {
                        if (alphaLow[l] == plain[k]) 
                        {
                            plain[k] = tolower(ciphAlpha[l]);
                            break;
                        }
                    }
                }
            }
            printf("%c", plain[k]);
        }
        printf("\n");
    }
    else 
    {
        return 1;
    }
}

bool validate(string key)
{
    int matches = 0;
    if (strlen(key) == 26)
    {
        for (char c = 'a'; c <= 'z'; c++)
        {
            for (int i = 0; i < 26; i++)
            {
                if (tolower(key[i]) == c)
                {
                    matches++;
                    break;
                }
            }
        }
        if (matches == 26)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}