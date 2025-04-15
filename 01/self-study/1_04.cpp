// 問1-4
#include <iostream>

// 問題を解く関数
void solve();
// 文字列を反転する関数
void my_reverse(std::string &s);

int main()
{
    solve();

    return (0);
}

void solve()
{
    // 変数の宣言や初期化
    int n;
    std::cin >> n;

    std::string ans = "";

    // 2進数に変換
    while (n > 0)
    {
        char c = n % 2 + '0';
        ans = ans + c;
        n /= 2;
    }
    
    my_reverse(ans);

    printf("%s\n", &ans[0]);
}

void my_reverse(std::string &ans)
{
    int l = 0;
    int r = ans.size() - 1;

    while (l < r)
    {
        char temp;
        temp = ans[l];
        ans[l] = ans[r];
        ans[r] = temp;
        l++;
        r--;
    }
}
