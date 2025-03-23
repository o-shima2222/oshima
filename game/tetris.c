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
 * 2025.03.16 Y.Oshima テトリミノの移動を追加
 * 2025.03.21 Y.Oshima テトリミノとフィールドの衝突判定を追加
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
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define FIELD_WIDTH (10)
#define FIELD_HEIGHT (20)

#define BLOCK_WIDTH_MAX (4)
#define BLOCK_HEIGHT_MAX (4)

#define FPS (0.5)
#define INTERVAL (100000*1.5)

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

bool MinocheckCollision()
{
    for(int y = 0; y < mino.block.height; y++)
   {
       for(int x = 0; x < mino.block.width;x++)
       {
            if(mino.block.pattern[y][x])
            {
                if((mino.y + y < 0) || (mino.y + y >= FIELD_HEIGHT) || (mino.x + x < 0) || (mino.x + x >= FIELD_WIDTH))
                {
                    return true;
                }
                if(field[mino.y + y][mino.x + x])
                {
                    return true;
                }
            }
            
       }
       
   }
   return false;
}

//ステージ作成
void DrawScreen()
{
   system("clear");
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
   
    // フィールド部分
    for(int y = 0; y < FIELD_HEIGHT; y++)
    {
        printf("□"); // 左の枠

        for(int x = 0; x < FIELD_WIDTH; x++)
        {
            printf("%s",screen[y][x] ? "■" : " ");
        }

        printf("□\r\n"); // 右の枠と改行
    }

    // 下の枠
    for(int x = 0; x < FIELD_WIDTH + 2; x++)
    {
        printf("□");
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
    
    clock_t lastClock = clock();
    while(1)
    {
        clock_t nowClock = clock();
        if(nowClock >= lastClock + INTERVAL)
        {
            lastClock = nowClock;
            MINO lastMino = mino;
            mino.y++;
            if(MinocheckCollision())
            {
                mino = lastMino;
                for(int y = 0; y < mino.block.height; y++)
                {
                    for(int x = 0; x < mino.block.width;x++)
                    {
                        if(mino.block.pattern[y][x])
                        {
                            field[mino.y + y][mino.x + x] |= 1;
                        }
                    }

                }
                for(int y = 0; y < FIELD_HEIGHT;y++)
                {
                    bool completed = true;
                    for(int x = 0; x < FIELD_WIDTH;x++)
                    {
                        if(field[y][x] == 0)
                        {
                            completed = false;
                            break;
                        }
                    }
                

                        if(completed)
                        {
                        for(int x = 0; x < FIELD_WIDTH;x++)
                        {
                            {
                                field[y][x] = 0;
                            }
                        }   
                        for(int y2 =y; y2 >= 1;y2--)
                            {
                                for(int x = 0; x < FIELD_WIDTH;x++)
                                {
                                    field[y2][x] = field[y2 - 1][x];
                                    field[y2 - 1][x] = 0;
                                }
                            }
                        }
                    
                }
                initMino();
            }

            DrawScreen();
        }
        if(kbhit())
        {
            MINO lastMino = mino;
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

               default:
               {
                MINO newMino = mino;
                for(int y = 0; y < mino.block.height; y++)
                {
                    for(int x = 0; x < mino.block.width;x++)
                    {
                        newMino.block.pattern[mino.block.width - 1 - x][y] = mino.block.pattern[y][x];
                    }
                    
                }
                mino = newMino;
               break;
               }
            }

           if(MinocheckCollision())
           {
                mino = lastMino;
           }
           
           DrawScreen();
        
        }
    }
    
    return 0;
}