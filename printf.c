#include <stdio.h>

// 配列の宣言
static int h[4][44];
static int b[4][64];

// 関数プロトタイプ宣言
void func(int h[4][44], int b[4][64], int *r);

int main()
{
    int pt = 100; // ptの初期値
    int gold[4][64];   // 使用されていないが、宣言だけしておく
    int silver[4][44]; // 使用されていないが、宣言だけしておく

    // 関数呼び出し
    func(h, b, &pt);
    func(h, b, &pt);
    func(h, b, &pt);
    // h[0][64]の範囲外アクセスを修正
    printf("%d\n", h[0][43]);
    printf("%d\n", b[1][43]);
    printf("%d\n", b[2][6]);
    return 0;
}

// 関数定義
void func(int h[4][44], int b[4][64], int *r)
{
    static int AM_count = 0; // スタティック変数

    // 範囲内のループに修正
    for (int i = 0; i < 44; i++) // hは[4][44]なので44まで
    {
        h[AM_count][i] = *r; // ポインタ型のrをデリファレンス
    }
    if(AM_count == 1)
    {
        for(int j = 0; j < 64; j++)
        {
            b[AM_count][j] = 200;
        }
    }
    if(AM_count == 2)
    {
        for(int j = 0; j < 64; j++)
        {
            b[AM_count][j] = 999;
        }
    }
    // カウントをインクリメント
    AM_count++;

    // 範囲外アクセスを防ぐ
    if (AM_count >= 4) {
        AM_count = 0; // 最大値を超えたらリセット（オーバーフロー防止）
    }
}
