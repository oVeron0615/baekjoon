#include <iostream>
#include <deque>
using namespace std;

int N, M, K;
deque<pair<int, int>> st1, st2;
bool check1{}, check2{}, c1{}, c2{};

void f1(int, int, int);
void f2(int, int, int);

int main()
{
	cin >> N >> M >> K;

	f1(N, M, K);
	f2(N, M, K);

	if (st1.empty() || st2.empty() || c1 || c2 || st1.back().first != K || st2.back().first != M) cout << -1;
	else
	{
		int memo1{ 0 };
		while (!st1.empty())
		{
			auto[k, l] = st1.front();
			for (int j{ 1 }; j <= l; j++)
			{
				memo1 += k;
				for (int i{ memo1 }; i > memo1 - k; i--) cout << i << " ";
			}
			st1.pop_front();
		}
		cout << "\n";

		int memo2{ N + 1 };
		while (!st2.empty())
		{
			auto [k, l] = st2.front();
			for (int j{ 1 }; j <= l; j++)
			{
				memo2 -= k;
				for (int i{ memo2 }; i < memo2 + k; i++) cout << i << " ";
			}
			st2.pop_front();
		}
	}
}

void f1(int n, int m, int k)
{
	if (k == 1)
	{
		if (n != m) c1 = true;
		else st1.push_front({ 1, n });
		check1 = true;
		return;
	}

	int p{ n / k }, q{ n % k };
	while (true)
	{
		if (check1) return;

		if (p + q > m)
		{
			st1.push_front({ k, p });
			f1(n - p * k, m - p, k - 1);
		}
		else if (p + q < m)
		{
			p--;
			q += k;
			if (p == 0)
			{
				k--;
				p = n / k;
				q = n % k;
			}
		}
		else
		{
			st1.push_front({ k, p });
			st1.push_front({ 1, q });
			check1 = true;
			return;
		}
	}
}
void f2(int n, int m, int k)
{
	if (m == 1)
	{
		if (n != k) c2 = true;
		else st2.push_front({ 1, n });
		check2 = true;
		return;
	}

	int p{ n / m }, q{ n % m };
	while (true)
	{
		if (check2) return;

		if (p + q > k)
		{
			st2.push_front({ m, p });
			f2(n - p * m, m - 1, k - p);
		}
		else if (p + q < k)
		{
			p--;
			q += m;
			if (p == 0)
			{
				m--;
				p = n / m;
				q = n % m;
			}
		}
		else
		{
			st2.push_front({ m, p });
			st2.push_front({ 1, q });
			check2 = true;
			return;
		}
	}
}