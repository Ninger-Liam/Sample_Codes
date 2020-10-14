#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int index(float l, float s, int w);

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
        else if (i > 0 && (text[i] == '.' || text[i] == '!' || text[i] == '?'))
        {
            sent++;
        }
    }
    
    int grade = index(let, sent, word);
    printf("Letter(s) %i\n", let);
    printf("Word(s) %i\n", word);
    printf("Sentence(s) %i\n", sent);
    if (grade >= 1 && grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else if (grade >= 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}

int index(float l, float s, int w)
{
    int i = round(0.0588 * (100 * l / w) - 0.296 * (100 * s / w) - 15.8);
    return i;
}