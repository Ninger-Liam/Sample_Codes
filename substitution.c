// #include <stdio.h>
// #include <cs50.h>
// #include <string.h>
// #include <ctype.h>

// #define ARRAY_SIZE 26

// int main(int argc, string argv[]){
//   if (argc != 2) {
//     printf("Usage: ./substitution key\n");
//     return 1;
//   }
//   for (int n = 0; n < strlen(argv[1]); n++) {
//     if (!isalpha(argv[1][n])) {
//       printf("Usage: ./substitution key\n");
//       return 1;
//     }
    
//   }
//   if (strlen(argv[1]) != 26) {
//     printf("Must have 26 characters\n");
//     return 1;
//   }

//   char alphaLow[ARRAY_SIZE] = {"abcdefghijklmnopqrstuvwxyz"};
//   char alphaUp[ARRAY_SIZE] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
//   char ciphAlpha[ARRAY_SIZE];
//   string plain = get_string("plaintext: ");
//   for (int i = 0; i < ARRAY_SIZE; i++) {
//     for (int j = 0; j < ARRAY_SIZE; j++) {
//       if (isupper(argv[1][i])) {
//         if (alphaUp[j] == argv[1][i]) {
//           ciphAlpha[i] = argv[1][i];
//           break;
//         }
//       }
//       else {
//         if(alphaLow[j] == argv[1][i]) {
//           ciphAlpha[i] = argv[1][i];
//           break;
//         }
//       }
//     }
//   }
//     printf("ciphertext: ");
//     for (int k = 0; k < strlen(plain); k++) {
//       for (int l = 0; l < ARRAY_SIZE; l++){
//         if (isalpha(plain[k])) {
//           if (isupper(plain[k])) {
//             if(alphaUp[l] == plain[k]) {
//               plain[k] = toupper(ciphAlpha[l]);
//               break;
//             }
//           }
//           else if (islower(plain[k])) {
//             if(alphaLow[l] == plain[k]) {
//               plain[k] = tolower(ciphAlpha[l]);
//               break;
//             }
//           }
//         }
//       }
//       printf("%c", plain[k]);
//     }
//     printf("\n");
// }
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool validate(string key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string key = argv[1];
        if (validate(key) == true)
        {
            string plaintext = get_string("plaintext: ");
            int charcount = strlen(plaintext);
            char ciphertext[charcount];
            string abc = "abcdefghijklmnopqrstuvwxyz";
            for (int i = 0; i < charcount; i++)
            {
                if (isupper(plaintext[i]) != 0)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        if(abc[j] == tolower(plaintext[i]))
                        {
                            ciphertext[i] = toupper(key[j]);
                            break;
                        }
                    }
                }
                else if (islower(plaintext[i]) != 0)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        if(abc[j] == plaintext[i])
                        {
                            ciphertext[i] = tolower(key[j]);
                            break;
                        }
                    }
                }
                else
                {
                    ciphertext[i] = plaintext[i];
                }
            }
            printf("ciphertext: %s\n", ciphertext);
            return 0;
        }
        else
        {
            printf("Please make sure your key is a permutation of all 26 characters - not more, not less.\n");
            return 1;
        }
    }
    else
    {
        printf("Input error. Please provide a single key.\n");
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
                if(tolower(key[i]) == c)
                {
                    matches++;
                    break;
                }
            }
        }
        if(matches == 26)
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