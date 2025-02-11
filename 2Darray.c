#include <stdio.h>
/************************************************************
 * Name ◆2Darray                                            *
 * Details ◆  二次元配列を利用して値を代入する　　　　　　　　　　　 *
 * Parameter ◆                                              *
 * Return ◆                                                 *
 *                                                          *
 * [変更履歴]                                                *
 * 2025/02/11 Y.Oshima 新規作成                              * 
 ************************************************************/ 
int main(void)
{
    int x;
    int y;

    int apple[10][10] = {0};
    int grape[10][10] = {0};

    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y < 10; y++)
        {
            apple[x][y] = 10;
            grape[x][y] = 40;
            if( y == 9)
            {
                apple[x][y] = 20;
                grape[x][y] = 50;
            }
            printf("apple[%d][%d] = %d  grape[%d][%d] = %d\n",x,y,apple[x][y],x,y,grape[x][y]);
        }
        printf("\n");
    }
    return 0;
}