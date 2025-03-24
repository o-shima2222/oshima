#include <stdio.h>

int main(void)
{
    int x[10] = {1,2,3,4,5};
    int y = 0;

    y = *(x + 2);
    printf("y = %d\n",y);

    return 0;
    
}