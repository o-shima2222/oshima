/************************************************************
 * プログラム名: overflow
 * 説明       : overflow の例とその対策
 * パラメータ : なし
 * 戻り値     : なし
 * 
 * [変更履歴]
 * 2025.03.11 新規作成
 ************************************************************/

#define SHORT_MAX 32767
#define SHORT_MIN -32768

//オーバーフロー対策
#define LIMIT_RANGE(value, min, max) \
    if (*(value) < (min)) \
    { \
        printf("入力値(%d)が下限 %d にクリップされました。\n", *(value),(min)); \
        *(value) = (min); \
    } \
    else \
    { \
        *(value) = *(value); \
    } \
    if (*(value) > (max)) \
    { \
        printf("入力値(%d)が上限 %d にクリップされました。\n", *(value),(max)); \
        *(value) = (max); \
    } \
    else \
    { \
        *(value) = *(value); \
    } \

 #include <stdio.h>
 int main(void)
 {
    int x = 0;
    int y = 0;
    int amount = 0;

    printf("x を入力してください: ");
    scanf("%d",&x);
    

    printf("y を入力してください: ");
    scanf("%d",&y);

    amount = x + y;
    LIMIT_RANGE(&amount,SHORT_MIN,SHORT_MAX);

    printf("結果: %d\n", amount);

    return 0;
 }

