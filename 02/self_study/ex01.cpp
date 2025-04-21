#include <cstdlib>
#include <iostream>
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

    std::cout << "要素数は" << d << "である\n";
    for (int i = 0; i < d; i++)
    {
        std::cout << vec[i] << (i == d - 1 ? '\n' : ' ');
    }
}
