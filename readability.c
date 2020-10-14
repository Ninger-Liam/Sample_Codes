#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// int index(float l, float s, float w);

int main(void){
    string text = get_string("Text: ");
    int tLength = strlen(text);
    int sent = 0;
    int word = 0;
    int let = 0;
    
    if (isalnum(text[0]))
    {
        word = 1;
    }
    
    for (int i = 0; i < tLength; i++)
    {
        if (isalpha(text[i]))
        {
            let++;
        }
        if (i < tLength - 1 && isspace(text[i]) && isalnum(text[i + 1]))
        {
            word++;
        }
        if (i > 0 && (text[i] == '.' || text[i] == '!' || text[i] == '?' ) && isalnum(text[i - 1]))
        {
            sent++;
        }
    }
    
    int grade = 0.0588 * (100 * let / word) - 0.296 * (100 * sent / word) - 15.8;
    printf("Letter(s) %i\n", let);
    printf("Word(s) %i\n", word);
    printf("Sentence(s) %i\n", sent);
    if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

// int index(float l, float s, float w)
// {
//     int i = round(0.0588 * (100 * l / w) - 0.296 * (100 * s / w) - 15.8);
//     return i;
// }