#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define ARRAY_SIZE 26

int main(int argc, string argv[]){
  if (argc != 2) {
    printf("Usage: ./substitution key\n");
    return 1;
  }
  for (int n = 0; n < strlen(argv[1]); n++) {
    if (!isalpha(argv[1][n])) {
      printf("Usage: ./substitution key\n");
      return 1;
    }
    
  }
  if (strlen(argv[1]) != 26) {
    printf("Must have 26 characters\n");
    return 1;
  }

  char alphaLow[ARRAY_SIZE] = {"abcdefghijklmnopqrstuvwxyz"};
  char alphaUp[ARRAY_SIZE] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  char ciphAlpha[ARRAY_SIZE];
  string plain = get_string("plaintext: ");
  for (int i = 0; i < ARRAY_SIZE; i++) {
    for (int j = 0; j < ARRAY_SIZE; j++) {
      if (isupper(argv[1][i])) {
        if (alphaUp[j] == argv[1][i]) {
          ciphAlpha[i] = argv[1][i];
          break;
        }
      }
      else {
        if(alphaLow[j] == argv[1][i]) {
          ciphAlpha[i] = argv[1][i];
          break;
        }
      }
      }
    }
    printf("ciphertext: ");
    for (int k = 0; k < strlen(plain); k++) {
      for (int l = 0; l < ARRAY_SIZE; l++){
        if (isalpha(plain[k])) {
          if (isupper(plain[k])) {
            if(alphaUp[l] == plain[k]) {
              plain[k] = toupper(ciphAlpha[l]);
              // printf("%c", plain[k]);
              break;
            }
          }
          else if (islower(plain[k])) {
            if(alphaLow[l] == plain[k]) {
              plain[k] = tolower(ciphAlpha[l]);
              // printf("%c", plain[k]);
              break;
            }
          }
        }
      }
      printf("%c", plain[k]);
    }
    printf("\n");
}