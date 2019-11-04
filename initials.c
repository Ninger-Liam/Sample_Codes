#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = get_string("");
    
    if (name != NULL)
    {
        for (int i = 0, l = strlen(name); i < l; i++)
        {
            if (islower(name[i]))
            {
                printf("%c", toupper(name[i]));
            }
            else
            {
                printf("%c", name[i]);
            }
        }
        printf("\n");
    }
}
