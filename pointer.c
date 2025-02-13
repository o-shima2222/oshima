#include <stdio.h>
void changeValue(int *pt);

int main(void)
{
    int x = 0;
    changeValue(&x);
    printf("x = %d\n",x);

    return 0;
}

void changeValue(int *pt)
{
    const int AMOUT = 30;
    *pt += AMOUT;
}