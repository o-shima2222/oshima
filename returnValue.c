#include <stdio.h>
int incVal(int *pt);

int main(void)
{
    int x = 10;
    int compare = 0;

    compare = incVal(&x);
    if(compare >= 10)
    {
        printf("x = %d\n",x);
    }
    else
    {
        x = 99;
        printf("xの値を調整しました\n");
        printf("x = %d\n",x);
    }
}

int incVal(int *pt)
{   
    int returnVal;
    returnVal = ++(*pt);
    return returnVal;
}