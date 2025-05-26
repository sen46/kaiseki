#include <cstdlib>
#include <cstdio>
#include <vector>
#include <time.h>
#include <cmath>

int main()
{
    srand(time(NULL));
    int     d = rand() % 80 + 20;
    double  sum = 0;
    double  sum2 = 0;

    std::vector<int> vec(d);
    for (int i = 0; i < d; i++)
    {
        vec[i] = rand() % 100;
    }

    for (int i = 0; i < d; i++)
    {
        sum += vec[i];
        vec[i] *= vec[i];
        sum2 += vec[i];
    }

    // 標準偏差 = 2乗の平均 - 平均の2乗
    sum = (sum / d) * (sum / d);
    sum2 /= d;

    printf("標準偏差は%lfです\n", sqrt(sum2 - sum));
}
