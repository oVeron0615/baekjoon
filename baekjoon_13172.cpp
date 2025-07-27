#include <iostream>
#define mod 1000000007
using namespace std;

int gcd(int, int);
long long DaC(int, int);

int main()
{
	long long ans{ 0 };
	int M; cin >> M;
	for (int i{ 0 }; i < M; i++)
	{
		long long N, S; cin >> N >> S;

		int g;
		if (N > S) g = gcd(N, S);
		else g = gcd(S, N);

		N /= g, S /= g;

		ans += (S * DaC(N, mod - 2)) % mod;
		ans %= mod;
	}
	cout << ans;
}

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long DaC(int N, int r)
{
	if (r == 1) return N;

	long long v{ DaC(N, r / 2) };
	cout << v << endl;
	if (r % 2 == 0) return (v * v) % mod;
	else return ((v * v % mod) * N) % mod;
}