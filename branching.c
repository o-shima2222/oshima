#include <stdio.h>

int main()
{
    int x = 10;
    int y = 20;

    if (x > 5) 
    {
        printf("xは5より大きい\n");
    } else {
        printf("xは5以下\n");
    }
    

    if (x > y) 
    {
        printf("xはyより大きい\n");
    } else {
        printf("xはy以下\n");
    }

    return 0;
    
}