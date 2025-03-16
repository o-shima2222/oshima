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
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h> 
#include <termios.h>
#include <fcntl.h>

#define FIELD_WIDTH (10)
#define FIELD_HEIGHT (20)
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

typedef struct {
   int x,y;
   BLOCK block;
}MINO;

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
       2,2, //int width,height
       {
          {1,1}, //int pattern[BLOCK_HEIGHT_MAX][BLOCK_WIDTH_MAX];
          {1,1}
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

int field[FIELD_HEIGHT][FIELD_WIDTH];
int screen[FIELD_HEIGHT][FIELD_WIDTH];
MINO mino;

//ステージ作成
void DrawScreen()
{
   memcpy(screen,field,sizeof(field));

   for(int y = 0; y < mino.block.height; y++)
   {
       for(int x = 0; x < mino.block.width;x++)
       {
           if(mino.block.pattern[y][x])
           {
               screen[mino.y+y][mino.x+x] |= 1;
           }
       }
   }

   clear(); 
   
    // フィールド部分
    for(int y = 0; y < FIELD_HEIGHT; y++)
    {
        printf("▢"); // 左の枠

        for(int x = 0; x < FIELD_WIDTH; x++)
        {
            printf("%s",screen[y][x] ? "▢" : " ");
        }

        printf("▢\r\n"); // 右の枠と改行
    }

    // 下の枠
    for(int x = 0; x < FIELD_WIDTH + 2; x++)
    {
        printf("▢");
    }
    printf("\r\n");
    refresh();  // ncurses の画面更新
}

void initMino()
{
   mino.block = block[rand() % BLOCK_MAX];
   mino.x = (FIELD_WIDTH - mino.block.width) / 2;
   mino.y = 0;
}

void init(){
   memset(field,0,sizeof field );
   initMino();
   DrawScreen();
}

int kbhit(void)
{
	struct termios oldt, newt;
	int ch;
	int oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if (ch != EOF) {
		ungetc(ch, stdin);
		return 1;
	}

	return 0;
}

int main(void)
{
    srand((unsigned int)time(NULL));
    init();
    
    
    while(1)
    {
        
        if(kbhit())
        {
            switch(getchar())
           {

               case 'w':
               break;

               case 's':
               mino.y++;
               break;

               case 'a':
               mino.x--;
               break;

               case 'd':
               mino.x++;
               break;

           }
           DrawScreen();
        
        }
    }
    
    return 0;
}