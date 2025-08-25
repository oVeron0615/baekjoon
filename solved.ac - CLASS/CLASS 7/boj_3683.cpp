#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXV = 501;
int c, d, v;
pair<string, string> people[MAXV];

vector<int> graph[MAXV];
int match[MAXV];
bool vis[MAXV];

void init()
{
	for(int i=1; i<MAXV; i++) graph[i].clear();
	memset(match, 0, sizeof(match));
}

bool DFS(int u)
{
	vis[u] = true;
	for(int v : graph[u])
	{
		if(vis[match[v]]) continue;
		if(!match[v] || DFS(match[v]))
		{
			match[v] = u;
			return true;
		}
	}
	return false;
}

void solve()
{
	init();

	cin >> c >> d >> v;
	for(int i=1; i<=v; i++)
	{
		string s1, s2; cin >> s1 >> s2;
		people[i] = {s1, s2};
	}

	for(int i=1; i<=v; i++)
	{
		if((people[i].first)[0] == 'D') continue;
		for(int j=1; j<=v; j++)
		{
			if((people[j].first)[0] == 'C') continue;
			if(people[i].first == people[j].second || people[i].second == people[j].first)
				graph[i].push_back(j);
		}
	}

	int ans = v;
	for(int u=1; u<=v; u++)
	{
		memset(vis, false, sizeof(vis));
		if(DFS(u)) ans--;
	}
	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while(T--) solve();
}