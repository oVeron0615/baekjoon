#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct tetro
{
	bool area[4][4];
	int r, c;
};

vector<tetro> block;
int board[501][501];

int solve(int x, int y, tetro b)
{
	int sum = 0;
	auto [area, r, c] = b;
	for(int i=x; i<x+r; i++)
	{
		for(int j=y; j<y+c; j++)
		{
			if(area[i-x][j-y]) sum += board[i][j];
		}
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	block.push_back({{{1, 1, 1, 1}}, 1, 4});
	block.push_back({{{1}, {1}, {1}, {1}}, 4, 1});
	block.push_back({{{1, 1}, {1, 1}}, 2, 2});
	block.push_back({{{1, 0}, {1, 1}, {0, 1}}, 3, 2});
	block.push_back({{{0, 1}, {1, 1}, {1, 0}}, 3, 2});
	block.push_back({{{0, 1, 1}, {1, 1, 0}}, 2, 3});
	block.push_back({{{1, 1, 0}, {0, 1, 1}}, 2, 3});
	block.push_back({{{1, 0}, {1, 0}, {1, 1}}, 3, 2});
	block.push_back({{{0, 1}, {0, 1}, {1, 1}}, 3, 2});
	block.push_back({{{1, 1}, {0, 1}, {0, 1}}, 3, 2});
	block.push_back({{{1, 1}, {1, 0}, {1, 0}}, 3, 2});
	block.push_back({{{1, 1, 1}, {1, 0, 0}}, 2, 3});
	block.push_back({{{1, 1, 1}, {0, 0, 1}}, 2, 3});
	block.push_back({{{0, 0, 1}, {1, 1, 1}}, 2, 3});
	block.push_back({{{1, 0, 0}, {1, 1, 1}}, 2, 3});
	block.push_back({{{1, 1, 1}, {0, 1, 0}}, 2, 3});
	block.push_back({{{0, 1, 0}, {1, 1, 1}}, 2, 3});
	block.push_back({{{0, 1}, {1, 1}, {0, 1}}, 3, 2});
	block.push_back({{{1, 0}, {1, 1}, {1, 0}}, 3, 2});

	int N, M; cin >> N >> M;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=M; j++)
		{
			cin >> board[i][j];
		}
	}

	int ans = 0;
	for(tetro b : block)
	{
		auto [area, r, c] = b;
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=M; j++)
			{
				if(i <= N - r + 1 && j <= M - c + 1)
					ans = max(ans, solve(i, j, b));
			}
		}
	}
	cout << ans;
}