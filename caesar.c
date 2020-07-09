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
// #include <cs50.h>
// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// int main(int argc, string argv[])
// {
//     if (argc != 2)
//     {
//         return 1;
//     }
//     string key = argv[1];
//     int number = strlen(key);

//     for (int letter = 0; letter < strlen(key); letter++)
//     {
//         if (isalpha(key[letter]))
//         {
//             return 1;
//         }
//     }
//     string phrase = get_string("plaintext: ");
//     printf("ciphertext: ");
//     for (int letter = 0; letter < strlen(phrase); letter++)
//     {
//         if (isalpha(phrase[letter]))
//         {
//             // if (isupper(key[letter % number]))
//             // {
//             //     key[letter % number] = key[letter % number] - 65;
//             // }
//             // if (islower(key[letter % number]))
//             // {
//             //     key[letter % number] = key[letter % number] - 97;
//             // }
//             if (isupper(phrase[letter]))
//             {
//                 phrase[letter] = phrase[letter] - 65;
//                 phrase[letter] = key[letter % number] + phrase[letter];
//                 phrase[letter] = phrase[letter] % 26;
//                 phrase[letter] = phrase[letter] + 65;
//                 printf("%c", phrase[letter]);
//             }
//             if (islower(phrase[letter]))
//             {
//                 phrase[letter] = phrase[letter] - 97;
//                 phrase[letter] = key[letter % number] + phrase[letter];
//                 phrase[letter] = phrase[letter] % 26;
//                 phrase[letter] = phrase[letter] + 97;
//                 printf("%c", phrase[letter]);
//             }
//         }
//         else
//         {
//             printf("%c", phrase[letter]);
//         }
//     }
//     printf("\n");
// }