#include <stdio.h>

// 構造体の定義
typedef struct {
    int x;
    int y;
    int z;
} X;

typedef struct {
    int a;
    int b;
    int c;
} Y;

// 関数プロトタイプ（型名をXとYに）
int function(X *pstx, const Y *psty);

// main関数
int main(void)
{
    X px = {0}; // 初期化
    X *py = &px;
    Y po = {0}; // 初期化

    // テスト用に po.a に値を設定
    po.a = 42;

    // 関数呼び出し
    function(py, &po);

    // 結果確認
    printf("px.x = %d\n", px.x);

    return 0;
}

// 関数実装
int function(X *pstx, const Y *psty)
{
    // pstx->x に psty->a を代入
    pstx->x = psty->a;

    return 0;
}
