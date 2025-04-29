#include <iostream>
#include <vector>
using namespace std;

std::vector<bool> IsPrime;
void sieve(size_t max);

int number_of_divisors(int &n, int d);


int main()
{
	sieve(10000); // 10000までの素数配列を作成する関数
	int n = 24;
	int d_count = 1;
	for (int i = 1; i <= n; i++)
	{
		if (IsPrime[i] && n % i == 0)
		{
			d_count = d_count * (number_of_divisors(n, i) + 1);
		}
	}
	cout << d_count << endl;
}

void sieve(size_t max){
    if(max+1 > IsPrime.size()){     // resizeで要素数が減らないように
        IsPrime.resize(max+1,true); // IsPrimeに必要な要素数を確保
    } 
    IsPrime[0] = false; // 0は素数ではない
    IsPrime[1] = false; // 1は素数ではない

    for(size_t i=2; i*i<=max; ++i) // 0からsqrt(max)まで調べる
        if(IsPrime[i]) // iが素数ならば
            for(size_t j=2; i*j<=max; ++j) // (max以下の)iの倍数は
                IsPrime[i*j] = false;      // 素数ではない
}

int number_of_divisors(int &n, int d)
{
	int cnt = 0;
	while (n % d == 0)
	{
		n /= d;
		cnt++;
	}
	return (cnt);
}
