#include <stdio.h>

int main(void)
{
    //変数の宣言と同時に初期値として20という値を代入している
    int age = 20;
    //printf関数を使用して変数[age]の値を出力
    printf("age = %d\n",age);

    //main()関数終了時に[0]を返しプログラムが正常終了したことを明示的にOSに伝える
    return 0;

}