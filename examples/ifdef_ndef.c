#include <stdio.h>

#define DEBUG_MODE 5 

int main(void)
{
    int x = 0;

    #ifdef DEBUG_MODE
    printf("DEBUG_MODE is defined\n");
    #endif

    #ifndef DEBUG_MODE
    pritnf("DEBUG_MODE is not defined\n");
    #endif

    #if (DEBUG_MODE == 1)
    x = 1;
    #elif (DEBUG_MODE == 2)
    x = 2;
    #elif (DEBUG_MODE == 3)
    x = 3;
    #else
    x = 9;
    #endif

    printf("x = %d\n",x);

    return 0;
}