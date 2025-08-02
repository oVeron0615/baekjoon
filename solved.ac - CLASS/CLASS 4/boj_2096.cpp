#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 100000, C = 3, INF = 1e9;
	int score[MAXN][C], dpMax[2][C], dpMin[2][C];

	int N; cin >> N;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<C; j++)
		{
			cin >> score[i][j];
		}
	}

	for(int i=0; i<C; i++) dpMin[0][i] = dpMax[0][i] = score[0][i];
	for(int i=1; i<N; i++)
	{
		for(int j=0; j<C; j++)
		{
			dpMax[i%2][j] = 0;
			dpMax[i%2][j] = max(dpMax[i%2][j], dpMax[1-i%2][j]);
			if(j > 0) dpMax[i%2][j] = max(dpMax[i%2][j], dpMax[1-i%2][j-1]);
			if(j < 2) dpMax[i%2][j] = max(dpMax[i%2][j], dpMax[1-i%2][j+1]);
			dpMax[i%2][j] += score[i][j];

			dpMin[i%2][j] = INF;
			dpMin[i%2][j] = min(dpMin[i%2][j], dpMin[1-i%2][j]);
			if(j > 0) dpMin[i%2][j] = min(dpMin[i%2][j], dpMin[1-i%2][j-1]);
			if(j < 2) dpMin[i%2][j] = min(dpMin[i%2][j], dpMin[1-i%2][j+1]);
			dpMin[i%2][j] += score[i][j];
		}
	}

	int ansMax = 0, ansMin = INF;
	for(int i=0; i<C; i++) 
	{
		ansMax = max(ansMax, dpMax[(N-1)%2][i]);
		ansMin = min(ansMin, dpMin[(N-1)%2][i]);
	}
	cout << ansMax << " " << ansMin;
}