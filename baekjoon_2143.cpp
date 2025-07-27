#include <iostream>
#include <map>
using namespace std;

long long Asum[1001], Bsum[1001];
map<long long, long long> kv;

int main()
{
	int T; cin >> T;
	int n; cin >> n;
	for (int i{ 1 }; i <= n; i++)
	{
		int a; cin >> a;
		Asum[i] = Asum[i - 1] + a;
	}
	int m; cin >> m;
	for (int i{ 1 }; i <= m; i++)
	{
		int b; cin >> b;
		Bsum[i] = Bsum[i - 1] + b;
	}

	for (int i{ 1 }; i <= m; i++)
	{
		for (int j{ 0 }; j < i; j++)
		{
			long long k = Bsum[i] - Bsum[j];
			if (kv.find(k) == kv.end()) kv.insert({ k, 1 });
			else kv[k]++;
		}
	}

	long long sum{ 0 };
	for (int i{ 1 }; i <= n; i++)
	{
		for (int j{ 0 }; j < i; j++)
		{
			long long k = Asum[i] - Asum[j];
			if (kv.find(T - k) != kv.end()) sum += kv[T - k];
		}
	}
	cout << sum;
}