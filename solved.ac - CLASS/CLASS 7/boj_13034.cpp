#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1001;
int N;
int g[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;
	g[0] = g[1] = 0;
	for(int i=2; i<=N; i++)
	{
		bool isExist[MAXN] = {};
		for(int j=0; j<=i-2; j++)
			isExist[g[j] ^ g[i - 2 - j]] = true;
		
		int mex = 0;
		while(isExist[mex]) mex++;
		g[i] = mex;
	}

	if(g[N]) cout << 1;
	else cout << 2;
} 