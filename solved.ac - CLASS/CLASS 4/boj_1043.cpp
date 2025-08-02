#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M;
const int MAXN = 51;
bool knowTruth[MAXN];
int par[MAXN], height[MAXN];

int Find(int x)
{
	if(par[x] == -1) return x;
	return par[x] = Find(par[x]);
}

void Union(int a, int b)
{
	a = Find(a), b = Find(b);
	if(a == b) return;

	if(height[a] < height[b]) swap(a, b);
	par[b] = a;
	if(height[a] == height[b]) height[a]++;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	int t; cin >> t;
	while(t--)
	{
		int num; cin >> num;
		knowTruth[num] = true;
	}

	fill(&par[0], &par[0] + MAXN, -1);
	vector<vector<int>> partys;
	while(M--)
	{
		int p; cin >> p;
		vector<int> party(p);
		for(int i=0; i<p; i++) 
		{
			cin >> party[i];
			if(i > 0) Union(party[i], party[i-1]);
		}
		partys.push_back(party);
	}

	for(int i=1; i<=N; i++)
	{
		if(knowTruth[i]) knowTruth[Find(i)] = true;
	}

	int ans = 0;
	for(vector<int> party : partys)
	{
		bool check = true;
		for(int p : party)
		{
			if(knowTruth[Find(p)]) check = false;
		}
		if(check) ans++;
	}
	cout << ans;
}

/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M;
const int MAXN = 51;
vector<int> knowTruth;
vector<int> graph[MAXN];
bool vis[MAXN];

void DFS(int u)
{
	vis[u] = true;
	for(int v : graph[u])
	{
		if(vis[v]) continue;
		DFS(v);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	int t; cin >> t;
	while(t--)
	{
		int num; cin >> num;
		knowTruth.push_back(num);
	}

	vector<vector<int>> partys;
	while(M--)
	{
		int p; cin >> p;
		vector<int> party(p);
		for(int i=0; i<p; i++)
		{
			cin >> party[i];
			if(i > 0)
			{
				graph[party[i]].push_back(party[i-1]);
				graph[party[i-1]].push_back(party[i]);
			}
		}
		partys.push_back(party);
	}

	for(int u : knowTruth)
	{
		if(vis[u]) continue;
		DFS(u);
	}

	int ans = 0;
	for(vector<int> party : partys)
	{
		bool check = true;
		for(int p : party)
		{
			if(vis[p]) check = false;
		}
		if(check) ans++;
	}
	cout << ans;
}
*/