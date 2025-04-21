// 問1-1〜問1-3
#include <stdio.h>
#include <vector>
#include <time.h>
#include <cstdlib>

int main()
{
    srand(time(NULL));

    // 変数の宣言や初期化
    int d = rand() % 81 + 20; // 20~100のランダムの値をdに代入
    int sum = 0;
    double ave = 0;

    // 大きさがdの配列を宣言
    std::vector<int> arr(d);     

    // 配列の値をrandomで初期化
    for (int i = 0; i < d; i++)
    {
        arr[i] = rand() % 100;
    }

    // 配列の和を求める
    for (int i = 0; i < d; i++)
    {
        sum += arr[i];
    }

    // 平均を求める
    ave = (double)sum / (double)d; // sum, dをdouble型に変換してから割り算を行う

    // 出力
    printf("合計は%dです。平均は%lfです。\n", sum, ave);
}
