#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

// ゲームボード
int board[BOARD_HEIGHT][BOARD_WIDTH] = {0};

// ブロックの形状 (I, O, T, Lなど)
int shapes[7][4] = {
    {1, 1, 1, 1},          // I形
    {1, 1, 1, 1},          // O形
    {0, 1, 1, 1},          // T形
    {1, 1, 0, 0},          // L形
    {0, 1, 1, 0},          // J形
    {1, 1, 0, 1},          // Z形
    {0, 1, 0, 1}           // S形
};

// ブロックの回転
void rotate(int shape[4]) {
    int temp[4];
    temp[0] = shape[2];
    temp[1] = shape[0];
    temp[2] = shape[3];
    temp[3] = shape[1];
    for (int i = 0; i < 4; i++) {
        shape[i] = temp[i];
    }
}

// 描画関数
void drawBoard() {
    clear();
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            if (board[y][x] == 0) {
                printw(" .");
            } else {
                printw(" #");
            }
        }
        printw("\n");
    }
    refresh();
}

int main() {
    // ncurses初期化
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    timeout(100);  // 100msごとに更新

    while (1) {
        drawBoard();

        // ブロックの落下
        // この部分でランダムなブロックを選択し、ボードに配置します
        // 簡略化のため、常に同じ形状を選んでいます
        for (int y = 0; y < BOARD_HEIGHT - 1; y++) {
            for (int x = 0; x < BOARD_WIDTH; x++) {
                if (shapes[0][x]) {  // 例えばI型ブロック
                    board[y+1][x] = 1;
                    board[y][x] = 0;
                }
            }
        }

        int ch = getch();  // キー入力待ち
        if (ch == 'q') break;  // qキーで終了
    }

    endwin();  // ncurses終了
    return 0;
}
