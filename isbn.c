#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
long isbn;
    
do
{
    isbn = get_long("ISBN:");
}
while (isbn < 0);
}
