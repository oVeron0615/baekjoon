#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100'001;
int N, M;
vector<pii> graph[MAXN];
pii edge[MAXN];

int segTree[MAXN * 4];

int root = 1;
int subSize[MAXN];
int chain_head[MAXN], chain_par[MAXN], chain_lv[MAXN];
int HLD_num[MAXN], HLD_cnt = 0;

void update(int node, int s, int e, int idx, int val)
{
	if(idx < s || e < idx) return;
	if(s == e) 
	{
		segTree[node] = val;
		return;
	}

	update(node*2, s, (s+e)/2, idx, val);
	update(node*2+1, (s+e)/2+1, e, idx, val);
	segTree[node] = max(segTree[node*2], segTree[node*2+1]);
}

int getVal(int node, int s, int e, int l, int r)
{
	if(e < l || r < s) return 0;
	if(l <= s && e <= r) return segTree[node];

	return max(getVal(node*2, s, (s+e)/2, l, r), getVal(node*2+1, (s+e)/2+1, e, l, r));
}

void getSize(int u, int p)
{
	subSize[u] = 1;
	for(int i=0; i<graph[u].size(); i++)
	{
		auto [d, v] = graph[u][i];
		if(v == p) continue;

		getSize(v, u);
		subSize[u] += subSize[v];

		//0번째 인덱스가 부모이거나 서브트리 크기가 현재 노드보다 작으면 바꾼다.
		auto [fd, fv] = graph[u][0];
		if(fv == p || subSize[fv] < subSize[v]) swap(graph[u][0], graph[u][i]);
	}
}

void HLD(int u, int p)
{
	HLD_num[u] = ++HLD_cnt;
	for(int i=0; i<graph[u].size(); i++)
	{
		auto [d, v] = graph[u][i];
		if(v == p) continue;

		if(i == 0) //같은 체인에 포함된다면 head, par, lv 모두 같다.
		{
			chain_head[v] = chain_head[u];
			chain_par[v] = chain_par[u];
			chain_lv[v] = chain_lv[u];
		}
		else //새로운 체인이 생성된다면 
		{
			chain_head[v] = v; //head는 자기 자신이 된다.
			chain_par[v] = u; //체인의 부모는 자신의 부모가 된다.
			chain_lv[v] = chain_lv[u] + 1; //level도 1 증가한다.
		}

		HLD(v, u);
		update(1, 1, N, HLD_num[v], d); //d 접근의 편의성을 위해 미리 업데이트
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=1; i<N; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		graph[u].push_back({w, v});
		graph[v].push_back({w, u});
		edge[i] = {u, v};
	}

	getSize(root, 0);

	chain_head[root] = root;
	chain_par[root] = 0;
	chain_lv[root] = 1;
	HLD(root, 0);

	cin >> M;
	while(M--)
	{
		int o; cin >> o;
		if(o == 1)
		{
			int i, c; cin >> i >> c;
			auto [u, v] = edge[i];
			if(HLD_num[u] > HLD_num[v]) swap(u, v);
			
			update(1, 1, N, HLD_num[v], c);
		}
		else //LCA의 구현을 보고 오면 쉽게 이해된다.
		{
			int u, v; cin >> u >> v;
			int ans = 0;

			//두 노드에 속한 체인의 level을 맞춘다.
			if(chain_lv[u] > chain_lv[v]) swap(u, v);
			while(chain_lv[u] != chain_lv[v])
			{
				ans = max(ans, getVal(1, 1, N, HLD_num[chain_head[v]], HLD_num[v]));
				v = chain_par[v];
			}

			//두 노드에 속한 체인의 head를 맞춘다.
			while(chain_head[u] != chain_head[v])
			{
				ans = max(ans, getVal(1, 1, N, HLD_num[chain_head[u]], HLD_num[u]));
				ans = max(ans, getVal(1, 1, N, HLD_num[chain_head[v]], HLD_num[v]));
				u = chain_par[u], v = chain_par[v];
			}

			//u, v가 동일한 체인에 속한다.
			if(HLD_num[u] > HLD_num[v]) swap(u, v);
			ans = max(ans, getVal(1, 1, N, HLD_num[u] + 1, HLD_num[v]));

			cout << ans << "\n";
		}
	}
}