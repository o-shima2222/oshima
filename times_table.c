/************************************************************
 * Name ◆ Multiplication table                              *
 * Details ◆  演算の九九　　　　　　　　 　　　　　　　　　　　　　　*
 * Parameter ◆                                              *
 * Return ◆                                                 *
 *                                                          *
 * [変更履歴]                                                *
 * 2025/02/14 Y.Oshima 新規作成                              * 
 ************************************************************/ 
#include <stdio.h>

int main(void)
{
    for(int i = 1; i <  10; i++)
    {
        for(int j = 1; j < 10; j++)
        {
            printf("    %2d",i * j);
        }
        printf("\n");
    }
    return 0;
}