#include <iostream>
using namespace std;

long long DaC(int r, int n, int mod);
int square(int r, int n, int mod);

int main()
{
	int a, r, n, mod;

	cin >> a >> r >> n >> mod;

	cout << DaC(r, n, mod) * a % mod;
}

long long DaC(int r, int n, int mod)
{
	if (n == 1) return 1 % mod;

	if (n % 2 == 0)
	{
		int mid = n / 2;

		return ((1 + square(r, mid, mod)) % mod) * DaC(r, mid, mod) % mod;
	}
	else
	{
		n -= 1;
		int mid = n / 2;
		
		return (((1 + square(r, mid, mod)) % mod) * (DaC(r, mid, mod) * r % mod) + 1) % mod;
	}
}

int square(int r, int n, int mod)
{
	if (n == 1) return r % mod;

	long long value = square(r, n / 2, mod);

	if (n % 2 == 0) return value * value % mod;
	else return (((value * value) % mod) * (r % mod)) % mod;
}