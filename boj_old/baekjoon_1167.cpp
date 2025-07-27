#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;
vector<pii> node[100001];
bool vis[100001];
int x;
long long len{ 0 };

void f(int, long long);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int V; cin >> V;
	for (int i{ 0 }; i < V; i++)
	{
		int a; cin >> a;
		while (true)
		{
			int b; cin >> b;
			if (b == -1) break;
			int l; cin >> l;
			node[a].push_back({ b, l });
		}
	}

	f(1, 0);

	memset(vis, false, sizeof(vis));
	len = 0;
	f(x, 0);
	cout << len;
}

void f(int n, long long sum)
{
	vis[n] = true;
	
	for (int i{ 0 }; i < node[n].size(); i++)
	{
		int next = node[n][i].first, l = node[n][i].second;
		if(!vis[next]) f(next, sum + l);
	}

	if (len < sum)
	{
		len = sum;
		x = n;
	}
}