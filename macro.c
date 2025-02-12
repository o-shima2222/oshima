#include <stdio.h>

#define macroA(status_a) (*(status_a) = *(status_a) + 20);

int main(void)
{
    int status_b = 40;
    int status_c = 50;
    int status_d = 60;

    macroA(&status_b);
    macroA(&status_c);
    macroA(&status_d);

    printf("%d\n",status_b);
    printf("%d\n",status_c);
    printf("%d\n",status_d);

    return 0;
}