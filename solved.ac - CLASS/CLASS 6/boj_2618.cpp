#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXW = 1001, INF = 1e9;
pii acci[MAXW];
int dp[MAXW][MAXW];
pii prv[MAXW][MAXW];
int N, W;
int X, Y;

int dist(int num, int a, int b)
{
	if(a > b) swap(a, b);

	int ax, ay, bx, by;
	if(num == 1 && a == 0) ax = 1, ay = 1;
	else if(num == 2 && a == 0) ax = N, ay = N;
	else ax = acci[a].first, ay = acci[a].second;
	bx = acci[b].first, by = acci[b].second;
	return abs(ax - bx) + abs(ay - by);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> W;
	for(int i=1; i<=W; i++)
	{
		int x, y; cin >> x >> y;
		acci[i] = {x, y};
	}

	fill(&dp[0][0], &dp[0][0] + MAXW * MAXW, INF);
	dp[0][0] = 0;
	
	int ans = INF;
	for(int i=0; i<W; i++)
	{
		for(int j=0; j<W; j++)
		{
			int k = max(i, j) + 1;

			int d = dp[i][j] + dist(1, i, k);
			if(dp[k][j] > d) dp[k][j] = d, prv[k][j] = {i, j};
			if(k == W && ans > dp[k][j]) ans = dp[k][j], X = k, Y = j;

			d = dp[i][j] + dist(2, j, k);
			if(dp[i][k] > d) dp[i][k] = d, prv[i][k] = {i, j};
			if(k == W && ans > dp[i][k]) ans = dp[i][k], X = i, Y = k;
		}
	}

	vector<int> track;
	while(!(X == 0 && Y == 0))
	{
		auto [PX, PY] = prv[X][Y];
		if(X == PX) track.push_back(2);
		else track.push_back(1);
		X = PX, Y = PY;
	}
	reverse(track.begin(), track.end());

	cout << ans << "\n";
	for(int a : track) cout << a << "\n";
}

/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXW = 1001, INF = 1e9;
pii acci[MAXW];
int dp[MAXW][MAXW];
pii prv[MAXW][MAXW];
int N, W;
int X, Y;

int dist(int num, int a, int b)
{
	if(a > b) swap(a, b);

	int ax, ay, bx, by;
	if(num == 1 && a == 0) ax = 1, ay = 1;
	else if(num == 2 && a == 0) ax = N, ay = N;
	else ax = acci[a].first, ay = acci[a].second;
	bx = acci[b].first, by = acci[b].second;
	return abs(ax - bx) + abs(ay - by);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> W;
	for(int i=1; i<=W; i++)
	{
		int x, y; cin >> x >> y;
		acci[i] = {x, y};
	}

	fill(&dp[0][0], &dp[0][0] + MAXW * MAXW, INF);
	dp[0][0] = 0;
	
	int ans = INF;
	for(int i=0; i<=W; i++)
	{
		for(int j=0; j<=W; j++)
		{
			if(i == j) continue;
			else if(i < j)
			{
				if(i == j - 1)
				{
					for(int k=0; k<j; k++) 
					{
						int d = dp[i][k] + dist(2, k, j);
						if(d < dp[i][j]) dp[i][j] = d, prv[i][j] = {i, k};
					}
				}
				else 
				{
					dp[i][j] = dp[i][j-1] + dist(2, j-1, j);
					prv[i][j] = {i, j-1};
				}
			}
			else
			{
				if(j == i - 1)
				{
					for(int k=0; k<i; k++) 
					{
						int d = dp[k][j] + dist(1, k, i);
						if(d < dp[i][j]) dp[i][j] = d, prv[i][j] = {k, j};
					}
				}
				else 
				{
					dp[i][j] = dp[i-1][j] + dist(1, i-1, i);
					prv[i][j] = {i-1, j};
				}
			}

			if(i == W || j == W) 
				if(ans > dp[i][j]) ans = dp[i][j], X = i, Y = j;
		}
	}

	vector<int> track;
	while(!(X == 0 && Y == 0))
	{
		auto [PX, PY] = prv[X][Y];
		if(X == PX) track.push_back(2);
		else track.push_back(1);
		X = PX, Y = PY;
	}
	reverse(track.begin(), track.end());

	cout << ans << "\n";
	for(int a : track) cout << a << "\n";
}
*/