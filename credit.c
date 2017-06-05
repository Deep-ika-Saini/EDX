#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long long cardno;
    do
    {
        printf("Number: ");
        cardno = get_long_long();
    }while(cardno <= 0);
    
    long long temp = cardno;
    int ans = temp % 10;
    while(temp > 0)
    {
        temp /= 10;
        int product = (temp % 10) * 2;
        
        if(product >= 10)
        {
            ans += product % 10;
            ans += product / 10;
        }
        else
            ans += product;
            
        temp /= 10;
        ans += temp % 10;
    }
    
    temp = cardno;
    int j;
    for(j = 0; temp > 100; j++)
    {
        temp = temp/10;
    }
    j += 2;
    
    if((temp == 34 || temp == 37) && j == 15 && ans % 10 == 0)
        printf("AMEX\n");
    else if((temp > 50 && temp < 56) && j == 16 && ans % 10 == 0)
        printf("MASTERCARD\n");
    else if((temp >= 40 && temp < 50) && (j == 13 || j == 16) && ans % 10 == 0)
        printf("VISA\n");
    else
        printf("INVALID\n");
        
    return 0;
}