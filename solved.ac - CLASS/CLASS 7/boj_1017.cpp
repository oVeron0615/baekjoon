#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 51;
int N;
int num[MAXN];
vector<int> graph[MAXN];
bool vis[MAXN];
vector<int> G;
int match[MAXN];

bool isPrime(int n)
{
	if(n == 1) return false;
	for(int i=2; i*i<=n; i++)
		if(n % i == 0) return false;
	return true;
}

bool DFS2(int u)
{
	vis[u] = true;
	for(int v : graph[u])
	{
		if(vis[match[v]]) continue;
		if(!match[v] || DFS2(match[v]))
		{
			match[v] = u;
			return true;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=1; i<=N; i++) cin >> num[i];

	for(int u=1; u<=N; u++)
	{
		for(int v=u+1; v<=N; v++)
		{
			if(isPrime(num[u] + num[v]))
			{
				graph[u].push_back(v);
				graph[v].push_back(u);
			}
		}
	}

	//홀, 짝으로 정점을 두 그룹으로 나눈다. 
	//소수는 2를 제외하고는 전부 홀수이고, 두 수의 합이 2가 될 수는 없으므로 두 수의 합은 무조건 홀수다.
	//두 수의 합이 홀수가 되기 위해서는 두 수가 홀수, 짝수여야 한다. 따라서 정점을 홀, 짝으로 나눈다.
	for(int i=2; i<=N; i++) 
		if(num[1] % 2 == num[i] % 2) G.push_back(i);
	
	vector<int> ans;
	for(int v : graph[1])
	{
		memset(match, 0, sizeof(match));
		match[v] = 1; //간선 고정

		int matchCnt = 1;
		for(int u : G)
		{
			memset(vis, false, sizeof(vis));
			vis[1] = true;
			if(DFS2(u)) matchCnt++;
		}

		if(matchCnt == N/2) ans.push_back(num[v]);
	}

	sort(ans.begin(), ans.end());
	if(ans.size() == 0) cout << -1;
	else
	{
		for(int a : ans) cout << a << " ";
	}
} 