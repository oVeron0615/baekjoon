#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int D(int n) { return n * 2 % 10000; }
int S(int n) { return n == 0 ? 9999 : n - 1; }
int L(int n) { return n % 1000 * 10 + n / 1000; }
int R(int n) { return n % 10 * 1000 + n / 10; }

void solve()
{
	int A, B; cin >> A >> B;
	bool vis[10000] = {};
	string order[10000];

	queue<int> qu;
	qu.push(A); vis[A] = true; order[A] = "";
	while(!qu.empty())
	{
		int u = qu.front(); qu.pop();
		if(u == B)
		{
			cout << order[u] << "\n";
			return;
		}

		int v;
		v = D(u); if(!vis[v]) qu.push(v), vis[v] = true, order[v] = order[u] + "D";
		v = S(u); if(!vis[v]) qu.push(v), vis[v] = true, order[v] = order[u] + "S";
		v = L(u); if(!vis[v]) qu.push(v), vis[v] = true, order[v] = order[u] + "L";
		v = R(u); if(!vis[v]) qu.push(v), vis[v] = true, order[v] = order[u] + "R";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while(T--) solve();
}