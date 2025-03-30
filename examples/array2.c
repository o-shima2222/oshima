#include <stdio.h>

int main(void) {
    int a = 10;
    int b = 20;

    // ポインタ変数を宣言して、bのアドレスを格納
    int *p = &b;

    // ポインタを使って値を参照
    printf("Address of b: %p\n", (void *)p); // bのアドレスを表示
    printf("Value of b through pointer: %d\n", *p); // ポインタを使ってbの値を表示

    // ポインタを使ってbの値を変更
    *p = 30;
    printf("Updated value of b: %d\n", b); // bの値が更新されていることを確認

    return 0;
}