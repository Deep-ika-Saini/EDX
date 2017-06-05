#include <stdio.h>
#include<cs50.h>

int main(void)
{
    int min;
    do
    {
        printf("Minutes: ");
        min = get_int();
    }while(min<0);
    
    printf("Bottles: %d\n", min * 12);
}