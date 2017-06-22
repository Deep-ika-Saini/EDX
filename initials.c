#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void get_initials(string name);

int main(void)
{
    string name = get_string();
    get_initials(name);
}

void get_initials(string name)
{
    if(name[0] != ' ')
        printf("%c",toupper(name[0]));
    for(int i = 1, l = strlen(name) ; i < l ; i++)
    {
        if(name[i-1] == ' ' && isalpha(name[i]))
            printf("%c",toupper(name[i]));
    }
    printf("\n");
}