#include <stdio.h>

int main(void)
{
    int k;
    int h[10] = {1,2,3,4,5,6,7,8,9,10};
    int u;

    typedef struct{
        int x;
    }structure;

    structure s;
    s.x = 3;
    u = h[s.x];
    printf("u = %d\n",u);

    return 0;

}