#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1000;
const int MAXAL = 26;

char L;
int N;
vector<string> S(MAXN);
vector<vector<int>> graph(MAXAL);
vector<int> ind(MAXAL);

void solve(int l, int r, int j)
{
	if(l == r) return;

	if(S[l].length() == j) l++;
	for(int i=l+1; i<=r; i++)
	{
		if(S[i].length() == j)
		{
			cout << "IMPOSSIBLE";
			exit(0);
		}
		if(S[i][j] != S[i-1][j])
		{
			graph[S[i-1][j]-'a'].push_back(S[i][j]-'a');
			ind[S[i][j]-'a']++;
			solve(l, i-1, j+1);
			l = i;
		}
	}
	solve(l, r, j+1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> L >> N;
	for(int i=0; i<N; i++) cin >> S[i];

	solve(0, N-1, 0);

	queue<int> qu;
	for(int i=0; i<=L-'a'; i++)
		if(!ind[i]) qu.push(i);

	vector<char> ans;
	while(!qu.empty())
	{
		if(qu.size() > 1)
		{
			cout << "AMBIGUOUS";
			return 0;
		}
		
		int u = qu.front(); qu.pop();
		ans.push_back('a' + u);

		for(int v : graph[u])
			if(!--ind[v]) qu.push(v);
	}

	for(int i=0; i<=L-'a'; i++)
	{
		if(ind[i])
		{
			cout << "IMPOSSIBLE";
			return 0;
		}
	}

	for(char c : ans) cout << c;
}