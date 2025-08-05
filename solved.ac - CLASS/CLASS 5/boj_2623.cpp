#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1001;
vector<int> graph[MAXN];
int cache[MAXN];
int N, M;
stack<int> st;

void DFS(int u)
{
	cache[u] = 1;
	for(int v : graph[u])
	{
		if(cache[v] == 1)
		{
			cout << 0;
			exit(0);
		}
		if(cache[v] == 0) DFS(v);
	}
	cache[u] = 2;
	st.push(u);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	while(M--)
	{
		int pd; cin >> pd;
		vector<int> singer(pd);
		for(int i=0; i<pd; i++) 
		{
			cin >> singer[i];
			if(i > 0) graph[singer[i-1]].push_back(singer[i]);
		}
	}

	for(int i=1; i<=N; i++)
		if(cache[i] == 0) DFS(i);

	while(!st.empty())
	{
		cout << st.top() << "\n";
		st.pop();
	}
}