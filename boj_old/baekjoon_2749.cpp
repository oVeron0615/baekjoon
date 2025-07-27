#include <iostream>
#include <map>
#define mod 1000000
using namespace std;

map<long long, long long> m;
long long f(long long);

int main()
{
	long long n; cin >> n;

	cout << f(n);
}

long long f(long long n)
{
	if (m.find(n) != m.end()) return m.at(n);
	if (n == 0) return 0;
	if (n == 1 || n == 2) return 1;

	if (n % 2 == 0)
	{
		long long f1 = f(n / 2) % mod;
		long long f2 = f(n / 2 - 1) % mod;
		long long v = ((f1 * f1 % mod) + (2 * f1 * f2 % mod)) % mod;
		m.insert({ n, v }); return v;
	}
	else
	{
		long long f1 = f(n / 2) % mod;
		long long f2 = f(n / 2 - 1) % mod;
		long long v = ((f1 * f1 * 2 % mod) + (2 * f1 * f2 % mod) + (f2 * f2 % mod)) % mod;
		m.insert({ n, v }); return v;
	}
}