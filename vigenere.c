#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //Reject if command line arguments are more than 1
    if(argc != 2)
    {
        printf("2 arguments allowed!\n");
        return 1;
    }
    
    //Reject if key isn't alphabetic
    int l_key = strlen(argv[1]);
    for(int i = 0; i < l_key; i++)
    {
        if(!isalpha(argv[1][i]))
        {
            printf("Key should be alphabetic!\n");
            return 1;
        }
    }
    
    printf("plaintext: ");
    string plaintext = get_string();
        
    for(int i = 0, ctr = 0, l_text = strlen(plaintext); i < l_text; i++)
    {
        //If the plaintext's ith character is an alphabet then enter
        if(isalpha(plaintext[i]))
        {
            //If the plaintext's ith character is an uppercase then enter
            if(isupper(plaintext[i]))
            {
                //'plaintext[i] - 65' coverts to alphabetic code
                //toupper(argv[1][ctr++]) preserves the case while transforming 
                int temp = plaintext[i] + toupper(argv[1][ctr++]) - 65;
                
                //this function helps to wrapsaround if 'Z' is exceeded
                if(temp > 90)
                    temp = temp - 26;
                plaintext[i] = (char) temp;
            }
            
            //If the plaintext's ith character is an lowercase then enter
            if(islower(plaintext[i]))
            {
                //'plaintext[i] - 97' coverts to alphabetic code
                //tolower(argv[1][ctr++]) preserves the case while transforming
                int temp = plaintext[i] + tolower(argv[1][ctr++]) - 97;
                
                //this function helps to wrapsaround if 'z' is exceeded
                if(temp > 122)                  
                    temp = temp - 26;
                plaintext[i] = (char) temp;
            }   
            
            //This helps to wraparound the key
            if(ctr >= l_key)
                ctr = 0;
        }
    }
    
    printf("ciphertext:%s\n", plaintext);
    return 0;
}