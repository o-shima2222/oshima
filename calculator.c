/************************************************************
 * Name ◆Calculator                                            *
 * Details ◆  データを処理して計算や情報の管理を行う　　　　　　　　 *
 * Parameter ◆                                              *
 * Return ◆                                                 *
 *                                                          *
 * [変更履歴]                                                *
 * 2025/02/09 Y.Oshima 新規作成                              * 
 * 2025/02/16 Y.Oshima 変更
 ************************************************************/ 
#include <stdio.h>

int main(void)
{
     int choice;
     int x = 0;
     int y = 0;;
     int amount = 0;
     int mod = 0;

    printf("演算の種類を選んでください(1:加算 2:減算 3:乗算 4:除算)\n");
    scanf("%d",&choice);

    printf("2つの整数を入力してください\n");
    scanf("%d %d",&x,&y);

     switch(choice)
     {
        case 1:
        printf("加算を行います\n");
        amount = x + y;
        printf("%d",amount);
        break;

        case 2:
        printf("減算を行います\n");
        amount = x - y;
        printf("%d",amount);
        break;

        case 3:
        printf("乗算を行います\n");
        amount = x * y;
        printf("%d",amount);
        break;

        case 4:
        if(y == 0)
        {
            printf("除算は0で割ることができません\n");
        }
        else
        {
        printf("除算を行います\n");
        amount = x / y;
        mod = x % y;
        printf("%d余り%d",amount,mod);
        }
        break;

        default:
        printf("無効な選択ですです\n");
        break;

     }

     return 0;
   }