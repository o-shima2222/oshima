/************************************************************
 * Name ◆matrix                                             *
 * Details ◆  二次元配列の利用　　　　　　　　　            *
 * Parameter ◆                                              *
 * Return ◆                                                 *
 *                                                           *
 * [変更履歴]                                                *
 * 2025/03/30 Y.Oshima 新規作成                              * 
 ************************************************************/ 
#include <stdio.h>

int main(void)
{
    int matrix[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d\n",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}