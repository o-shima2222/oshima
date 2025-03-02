/************************************************************
 * プログラム名: tetris
 * 説明       : コンソールのシンプルなテトリス
 * パラメータ : なし
 * 戻り値     : なし
 * 
 * [変更履歴]
 * 2025.03.01 Y.Oshima 新規作成
 * 2025.03.02 Y.Oshima フィールドの表示を追加
 ************************************************************/

 #include <stdio.h>
 #include <stdlib.h>
 
 #define FIELD_WIDTH (10)
 #define FIELD_HEIGHT (15)
 
 //ステージ作成
 void DrawScreen()
 {
     // フィールド部分
     for(int y = 0; y < FIELD_HEIGHT; y++)
     {
         printf("□"); // 左の枠
 
         for(int x = 0; x < FIELD_WIDTH; x++)
         {
             printf(" "); // フィールドの空白
         }
 
         printf("□\n"); // 右の枠と改行
     }
 
     // 下の枠
     for(int x = 0; x < FIELD_WIDTH + 2; x++)
     {
         printf("□");
     }
     printf("\n");
 }
 
 int main(void)
 {
     DrawScreen();
     getchar();
     return 0;
 }
 