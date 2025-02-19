/************************************************************
 * プログラム名: Calculator
 * 説明       : データを処理して計算や情報の管理を行う
 * パラメータ : なし
 * 戻り値     : なし
 * 
 * [変更履歴]
 * 2025/02/09 Y.Oshima 新規作成
 * 2025/02/16 Y.Oshima 変更: 機能追加
 * 2025/02/17 Y.Oshima 変更: 機能追加
 * 2025/02/18 Y.Oshima 変更: 機能追加
 ************************************************************/
#include <stdio.h>
#include <string.h>
#include <math.h>

#define REMAIN_MAX 10

int main(void)
{
     int choice;
     int x = 0;
     int y = 0;;
     int amount = 0;
     int mod = 0;
     char trigger[10] = "";
     int remain[10] = {0};
     int i = 0;

     do
     { 
    printf("演算の種類を選んでください(1:加算 2:減算 3:乗算 4:除算)\n");
    scanf("%d",&choice);

    printf("2つの整数を入力してください\n");
    scanf("%d %d",&x,&y);
        
      switch(choice)
     {
        case 1:
        printf("加算を行います\n");
        amount = x + y;
        printf("%d\n",amount);
        break;

        case 2:
        printf("減算を行います\n");
        amount = x - y;
        printf("%d\n",amount);
        break;

        case 3:
        printf("乗算を行います\n");
        amount = x * y;
        printf("%d\n",amount);
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
        printf("%d 余り %d\n",amount,mod);
        }
        break;

        case 5:
        printf("累乗計算を行います\n");
        amount = pow(x,y);
        printf("%d\n",amount);
        break;

        default:
        printf("無効な選択です\n");
        break;

     }
     if(i < REMAIN_MAX)
     {
         remain[i] = amount;
         printf("計算結果を保存しました: %d\n", remain[i]);
         i++;
     }
       else
       {
          printf("履歴最大容量に達しました。新しい履歴を保斬できません\n");
       }
     
       printf("---- 計算履歴 ----\n");
        for (int j = 0; j < i; j++)
        {
            printf("[%d] %d\n", j + 1, remain[j]);
        }
        printf("------------------\n");

     printf("終了する場合は「qt」と入力してください\n");
     scanf("%s",trigger);
    }while(strcmp(trigger,"qt") != 0);
    
     return 0;
  }
  