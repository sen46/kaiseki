// 授業スライド19ページ
#include <stdio.h>
#include <vector>

void example1();

int main()
{
    example1();
    return (0);
}

void example1()
{
    std::vector<double> a(31);

    a[0] = 1;
    for (int i = 1; i <= 30; i++)
    {
        a[i] = a[i - 1] + 1 / (double)(i);
    }
    printf("%.14e\n", a[30]);
}
