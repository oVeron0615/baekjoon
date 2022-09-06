#include <iostream>
using namespace std;

int par[201];
int height[201];

int getPar(int a)
{
	if (par[a] == 0) return a;
	else return getPar(par[a]);
}

void merge(int a, int b)
{
	a = getPar(a);
	b = getPar(b);

	if (a == b) return;
	if (height[a] > height[b]) par[b] = a;
	else
	{
		par[a] = b;
		if(height[a] == height[b]) height[b]++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M; cin >> N >> M;
	for (int i{ 1 }; i <= N; i++)
	{
		for (int j{ 1 }; j <= N; j++)
		{
			bool cal; cin >> cal;
			if (cal) merge(i, j);
		}
	}
	
	int city; cin >> city;
	int p{ getPar(city) };
	bool check{ true };
	for (int i{ 2 }; i <= M; i++)
	{
		int city; cin >> city;
		int q{ getPar(city) };
		if (p != q)
		{
			check = false;
			break;
		}
	}
	if (check) cout << "YES";
	else cout << "NO";
}