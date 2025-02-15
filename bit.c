/************************************************************
 * Name ◆Bit操作                                            *
 * Details ◆  ビット操作と条件分岐  　　　　　　　　　　　　　　　　 *
 * Parameter ◆                                              *
 * Return ◆                                                 *
 *                                                          *
 * [変更履歴]                                                *
 * 2025/02/16 Y.Oshima 新規作成                              * 
 ************************************************************/ 
#include <stdio.h>

int main(void)
{
    unsigned char x = 0x04;  // 00000100 (3ビット目がON)

    printf("Initial value: 0x%02X\n", x);

    // x の3ビット目がONなら、1ビット目をONにする
    if (x & 0x04)
    {
        x |= 0x01;  // 00000101 にする
        printf("Bit 0 set: 0x%02X\n", x);
    }

    // x の1ビット目がONなら、2ビット目を反転させる
    if (x & 0x01)
    {
        x ^= 0x02;  // 00000111 または 00000101 に変化
        printf("Bit 1 toggled: 0x%02X\n", x);
    }

    // x が偶数なら4ビット目をONにする
    if ((x & 0x01) == 0)
    {
        x |= 0x08;  // 00001101 など
        printf("Bit 3 set: 0x%02X\n", x);
    }

    // x が 0x0F になったら成功メッセージ
    if (x == 0x0F)
    {
        printf("All lower 4 bits are ON!\n");
    }

    return 0;
}
