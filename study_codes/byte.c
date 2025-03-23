#include <stdio.h>

int main(void)
{
    //整数型のサイズを調べる為にsizeof演算子を使用
    printf("%dバイト\n",(int)sizeof(long));

    //main()関数に[0]を返し、OSに正常終了したことを伝える
    return 0;
}