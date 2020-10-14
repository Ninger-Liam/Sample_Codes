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
            word++;
            sent++;
        }
    }
    
    int grade = index(let, sent, word);
    printf("Letter(s) %i\n", let);
    printf("Word(s) %i\n", word);
    printf("Sentence(s) %i\n", sent);
    if (grade >= 1)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Before Grade 1\n");
    }
}

int index(float l, float s, int w)
{
    // l = l * 100;
    // l = l / w;
    // l = l * 0.0588;
    // s = s * 100;
    // s = s / w;
    // s = s * 0.296;
    // int i = round((l - s) - 15.8);
    return i;
}