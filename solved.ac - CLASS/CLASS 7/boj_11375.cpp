#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1001;
vector<int> graph[MAXN];
bool vis[MAXN];
int match[MAXN]; //match[i] = i번째 일에 매칭되는 직원
int N, M;

bool DFS(int u)
{
	vis[u] = true;
	for(int v : graph[u]) //직원과 연결된 일 탐색
	{
		if(vis[match[v]]) continue; //해당 일을 하는 직원 노드를 이미 방문했으면 무시
		if(!match[v] || DFS(match[v])) //그 일에 매칭된 직업이 없거나, 증가 경로를 발견했다면
		{
			match[v] = u; //그 일에 직원을 매칭
			return true;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	for(int u=1; u<=N; u++)
	{
		int n; cin >> n;
		while(n--)
		{
			int v; cin >> v;
			graph[u].push_back(v);
		}
	}

	int ans = 0;
	for(int u=1; u<=N; u++) //모든 직원에 대해 DFS 탐색
	{
		memset(vis, false, sizeof(vis));
		if(DFS(u)) ans++; //증가 경로 발견
	}
	cout << ans;
} 