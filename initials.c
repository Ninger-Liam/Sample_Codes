#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = get_string("");
    
    if (name != NULL)
    {
        printf("%c", toupper(name[0]));
        
        for (int i = 0, l = strlen(name); i < l; i++)
        {
            if (name[i] == ' ')
            {
                printf("%c", toupper(name[i + 1]));
            }
           
        }
        printf("\n");
    }
}
