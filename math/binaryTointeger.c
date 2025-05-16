#include <stdio.h>

int main(void)
{
    // 2進数の文字列を整数に変換
    const char *binaryStr = "1101"; // 2進数の文字列
    int decimalValue = 0; // 整数値

    // 2進数の文字列を整数に変換
    for (int i = 0; binaryStr[i] != '\0'; i++) {
        decimalValue = (decimalValue << 1) | (binaryStr[i] - '0');
    }

    // 結果を表示
    printf("Binary: %s\n", binaryStr);
    printf("Decimal: %d\n", decimalValue);

    return 0;   
}