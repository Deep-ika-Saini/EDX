#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
 
    string salt = "50";
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    
    for(int i = 0; i < 52; i++)
    {
        char key[5];
        key[0] = alphabet[i];
        key[1] = '\0';
        if(strcmp(argv[1],crypt(key, salt))==0)
        {
            printf("%s\n",key);
            return 0;
        }
        
        for(int j = 0; j < 52; j++)
        {
            key[1] = alphabet[j];
            key[2] = '\0';
            if(strcmp(argv[1],crypt(key, salt))==0)
            {
                printf("%s\n",key);
                return 0;
            }
    
            for(int k = 0; k < 52; k++)
            {
                key[2] = alphabet[k];
                key[3] = '\0';
                if(strcmp(argv[1],crypt(key, salt))==0)
                {
                    printf("%s\n",key);
                    return 0;
                }
            
                for(int l = 0; l < 52; l++)
                {
                    key[3] = alphabet[l];
                    key[4] = '\0';
                    if(strcmp(argv[1],crypt(key, salt))==0)
                    {
                        printf("%s\n",key);
                        return 0;
                    }
                }
            }
        }
    }
}