#include <cstdlib>
#include <cstdio>
#include <vector>
#include <time.h>
#include <climits>

int main()
{
    srand(time(NULL));
    int d = rand() % 80 + 20;

    std::vector<int> vec(d);
    for (int i = 0; i < d; i++)
    {
        vec[i] = rand() % 100;
    }

    int mn = INT_MAX;
    int mx = INT_MIN;

    // cout << "INT_MAX = " << INT_MAX << ", INT_MIN = " << INT_MIN << endl;
    for (int i = 0; i < d; i++)
    {
        mn = std::min(mn, vec[i]);
        mx = std::max(mx, vec[i]);
    }

    // printf("最小値 = %d, 最大値 = %d\n", mn, mx);
    printf("最大値と最小値の差 = %d\n", mx - mn);
    return (0);
}
