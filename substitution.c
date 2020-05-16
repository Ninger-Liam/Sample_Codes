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

  char alpha[ARRAY_SIZE] = {"abcdefghijklmnopqrstuvwxyz"};
  char ciphAlpha[ARRAY_SIZE];
  string plain = get_string("plaintext: ");
  // for (int i = 0; i < ARRAY_SIZE; i++) {
  //   for (int j = 0; j < ARRAY_SIZE; j++) {
  //     if (alpha[j] == argv[1][i] || toupper(alpha[j]) == argv[1][i]) {
  //       ciphAlpha[i] = argv[1][i];
  //       break;
  //     }
  //   }
  // }
    printf("ciphertext: ");
    for (int k = 0; k < strlen(plain); k++) {
      for (int l = 0; l < ARRAY_SIZE; l++){
        if (isalpha(plain[k])) {
          if (isupper(plain[k])) {
            if(toupper(alpha[l]) == plain[k]) {
              ciphAlpha[k] = toupper(argv[1][l]);
              break;
            }
          }
          else if (islower(plain[k])) {
            if(alpha[l] == plain[k]) {
              ciphAlpha[k] = tolower(argv[1][l]);
              break;
            }
          }
        }
      }
      if(isdigit(plain[k])){
        ciphAlpha[k] = plain[k];
      }
      printf("%c", ciphAlpha[k]);
    }
    printf("\n");
}