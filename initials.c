#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    //get the users name
    string name = get_string("");
    //make sure that there are mo errors in the string
    if (name != NULL)
    {
        //print the first initial and make it uppercase so the loop doesn't skip over it 
        printf("%c", toupper(name[0]));
        //checks how long the name is and keeps track of how many times it needs to loop
        for (int i = 0, l = strlen(name); i < l; i++)
        {
            //prints the next character after space and makes sure it's uppercase, printing only the initials
            if (name[i] == ' ')
            {
                printf("%c", toupper(name[i + 1]));
            }
           
        }
        //make a new line for neatness
        printf("\n");
    }
}
