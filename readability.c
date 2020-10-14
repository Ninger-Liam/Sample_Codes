#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float index(float l, float s, float w);

int main(void){
    string text = get_string("Text: ");
    int tLength = strlen(text);
    int sent = 0;
    int word = 1;
    int let = 0;
    
    for (int i = 0; i < tLength; i++)
    {
        if (isalpha(text[i]))
        {
            let++;
        }
        else if (isspace(text[i]) && isalpha(text[i + 1]))
        {
            word++;
        }
        else if (i > 0 && (text[i] == '.' || text[i] == '!' || text[i] == '?' ) && isalnum(text[i - 1]))
        {
            sent++;
        }
    }
    
    int grade = index(let, sent, word);
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

float index(float l, float s, float w)
{
    float i = round(0.0588 * (100 * l / (float) w) - 0.296 * (100 * s / (float) w) - 15.8);
    return i;
}