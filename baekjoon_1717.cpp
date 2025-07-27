#include <iostream>
#include <cstring>
using namespace std;

int par[1000001];
int height[1000001];

int getPar(int a)
{
	if (par[a] == -1) return a;
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

	memset(par, -1, sizeof(par));

	int n, m; cin >> n >> m;
	for (int i{ 1 }; i <= m; i++)
	{
		bool cal;
		int p, q;
		cin >> cal >> p >> q;

		if (cal == 0) merge(p, q);
		else
		{
			p = getPar(p);
			q = getPar(q);
			if (p == q) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}