#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100'001;
int N, M;
vector<int> graph[MAXN];

int in[MAXN], out[MAXN];
int DFS_num = 0;

ll segTree[MAXN * 4];

void DFS(int u)
{
	in[u] = ++DFS_num;
	for(int v : graph[u]) DFS(v);
	out[u] = DFS_num;
}

void update(int node, int s, int e, int l, int r, ll val)
{
	if(r < s || e < l) return;
	if(l <= s && e <= r)
	{
		segTree[node] += val;
		return; 
	}

	update(node*2, s, (s+e)/2, l, r, val);
	update(node*2+1, (s+e)/2+1, e, l, r, val);
}

ll getVal(int node, int s, int e, int idx)
{
	if(idx < s || e < idx) return 0;
	if(s == e) return segTree[node];

	return getVal(node*2, s, (s+e)/2, idx) + getVal(node*2+1, (s+e)/2+1, e, idx) + segTree[node];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	for(int v=1; v<=N; v++)
	{
		int u; cin >> u;
		if(u == -1) continue;
		graph[u].push_back(v);
	}

	DFS(1);

	while(M--)
	{
		int o; cin >> o;
		if(o == 1)
		{
			int i, w; cin >> i >> w;
			update(1, 1, N, in[i], out[i], w);
		}
		else
		{
			int i; cin >> i;
			cout << getVal(1, 1, N, in[i]) << "\n";
		}
	}
}