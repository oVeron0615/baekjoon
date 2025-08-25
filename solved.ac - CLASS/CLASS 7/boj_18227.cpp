#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 200'001;
vector<int> graph[MAXN];
ll depth[MAXN];
int N, C;

int in[MAXN], out[MAXN];
int DFS_cnt = 0;

ll segTree[MAXN * 4];

void update(int node, int s, int e, int idx)
{
	if(idx < s || e < idx) return;
	if(s == e) 
	{
		segTree[node]++;
		return;
	}

	update(node*2, s, (s+e)/2, idx);
	update(node*2+1, (s+e)/2+1, e, idx);
	segTree[node] = segTree[node*2] + segTree[node*2+1];
}

ll getVal(int node, int s, int e, int l, int r)
{
	if(r < s || e < l) return 0;
	if(l <= s && e <= r) return segTree[node];

	return getVal(node*2, s, (s+e)/2, l, r) + getVal(node*2+1, (s+e)/2+1, e, l, r);
}

void DFS(int u, int p, int d)
{
	depth[u] = d;
	in[u] = ++DFS_cnt;
	for(int v : graph[u])
	{
		if(v == p) continue;
		DFS(v, u, d+1);
	}
	out[u] = DFS_cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> C;
	for(int i=1; i<N; i++)
	{
		int x, y; cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	DFS(C, 0, 1);

	int Q; cin >> Q;
	while(Q--)
	{
		int o, A; cin >> o >> A;
		if(o == 1) update(1, 1, N, in[A]);
		else cout << getVal(1, 1, N, in[A], out[A]) * depth[A] << "\n";
	}
}