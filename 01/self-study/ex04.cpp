// 問1-4
// 関数を作成しなさいという問題なので、main関数は不要のためコメントアウト
// コンパイルする時はメイン関数のコメントアウトを消去すること
#include <stdio.h>
#include <string>

// 問題を解く関数
void solve(int n);
// 文字列を反転する関数
void my_reverse(std::string &s);

/*
int main()
{
    int n;
    n = 10; // nに好きな整数を代入させる.
    solve(n);

    return (0);
}
*/

void solve(int n)
{
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
