/************************************************************
 * プログラム名: tetris
 * 説明       : コンソールのシンプルなテトリス
 * パラメータ : なし
 * 戻り値     : なし
 * 
 * [変更履歴]
 * 2025.03.01 Y.Oshima 新規作成
 * 2025.03.02 Y.Oshima フィールドの表示を追加
 * 2025.03.04 Y.Oshima テトリミノの表示を追加
 ************************************************************/

 #include <stdio.h>
 #include <stdlib.h>
 
 #define FIELD_WIDTH (10)
 #define FIELD_HEIGHT (15)
 
 #define BLOCK_WIDTH_MAX (4)
 #define BLOCK_HEIGHT_MAX (4)

 enum{
    BLOCK_I,
    BLOCK_O,
    BLOCK_S,
    BLOCK_Z,
    BLOCK_J,
    BLOCK_L,
    BLOCK_T,
    BLOCK_MAX
 };

 typedef struct{
    int width,height;
    int pattern[BLOCK_HEIGHT_MAX][BLOCK_WIDTH_MAX];
 }BLOCK;
 BLOCK block[BLOCK_MAX] = {
    //BLOCK_I
    {
        4,4, //int width,height
        {
            {0,0,0,0}, //int pattern[BLOCK_HEIGHT_MAX][BLOCK_WIDTH_MAX];
            {1,1,1,1},
            {0,0,0,0},
            {0,0,0,0}
        }
    },
    //BLOCK_O
    {
        4,4, //int width,height
        {
           {0,0}, //int pattern[BLOCK_HEIGHT_MAX][BLOCK_WIDTH_MAX];
           {0,0}
        }
    },
    //BLOCK_S
    {
        3,3, //int width,height
        {
           {0,1,1}, //int pattern[BLOCK_HEIGHT_MAX][BLOCK_WIDTH_MAX];
           {1,1,0},
           {0,0,0}
        }
    },
    //BLOCK_Z
    {
        3,3, //int width,height
        {
           {1,1,0}, //int pattern[BLOCK_HEIGHT_MAX][BLOCK_WIDTH_MAX];
           {0,1,1},
           {0,0,0}
        }
    },
    //BLOCK_J
    {
        3,3, //int width,height
        {
           {1,0,0}, //int pattern[BLOCK_HEIGHT_MAX][BLOCK_WIDTH_MAX];
           {1,1,1},
           {0,0,0}
        }
    },
    //BLOCK_L
    {
        3,3, //int width,height
        {
           {0,0,1}, //int pattern[BLOCK_HEIGHT_MAX][BLOCK_WIDTH_MAX];
           {1,1,1},
           {0,0,0}
        }
    },
    //BLOCK_T
    {
        3,3, //int width,height
        {
           {0,1,0}, //int pattern[BLOCK_HEIGHT_MAX][BLOCK_WIDTH_MAX];
           {1,1,1},
           {0,0,0}
        }
    }
 };
 
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
 