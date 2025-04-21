#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <vector>
#include <time.h>

int main()
{
    srand(time(NULL));
    int d = rand() % 80 + 20;

    std::vector<int> vec(d);
    for (int i = 0; i < d; i++)
    {
        vec[i] = rand() % 100;
    }

    std::cout << "before" << std::endl;
    for (int i = 0; i < d; i++)
    {
        std::cout << vec[i] << (i == d - 1 ? '\n' : ' ');
    }

    // バブルソートを使用
    for (int i = d - 1; i >= 0; i--)
    {
        for (int j = 0; j < i ; j++)
        {
            if (vec[j] < vec[j + 1])
            {
                // vec[j] と vec[j+1]をswqpしてるだけ
                vec[j] ^= vec[j + 1];
                vec[j + 1] ^= vec[j];
                vec[j] ^= vec[j + 1];
            }
        }
    }

    std::cout << "after" << std::endl;
    for (int i = 0; i < d; i++)
    {
        std::cout << vec[i] << (i == d - 1 ? '\n' : ' ');
    }
    return (0);
}
