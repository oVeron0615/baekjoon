#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 1025;
	int num[MAXN][MAXN], psum[MAXN][MAXN] = {};

	int N, M; cin >> N >> M;
	for(int i=1; i<=N; i++)
	{
		int sum = 0;
		for(int j=1; j<=N; j++)
		{
			cin >> num[i][j];
			sum += num[i][j];
			psum[i][j] = sum + psum[i-1][j];
		}
	}

	while(M--)
	{
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		cout << psum[x2][y2] + psum[x1-1][y1-1] 
			- psum[x1-1][y2] - psum[x2][y1-1] << "\n";
	}
}