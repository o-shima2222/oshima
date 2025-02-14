#include <stdio.h>

int main(void)
{
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
        printf("You have selected 1\n");
        break;
        
        case 2:
        printf("You have selected 2\n");
        break;

        case 3:
        printf("You have selected 3\n");
        break;

        default:
        break;
    }

    return 0;
}