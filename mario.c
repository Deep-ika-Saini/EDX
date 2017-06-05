#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    
    do
    {
        printf("Height: ");
        height = get_int();
    }while(height<0 || height>23);
    
    for(int i = 0; i < height; i++)
    {
        for(int j = height - i - 1; j > 0; j--)
        {
            printf(" ");
        }
        
        for(int k = i; k >= 0; k--)
        {
            printf("#");
        }
        
        printf("  ");
        
        for(int l = i; l >= 0; l--)
        {
            printf("#");
        }
        
        printf("\n");
    }
}