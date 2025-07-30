#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool board[128][128];

pii colorpaper(int x, int y, int N)
{
	if(N == 0) return {0, 0};

	bool isWhite = true, isBlue = true;
	for(int i=x; i<x+N; i++)
	{
		for(int j=y; j<y+N; j++)
		{
			if(board[i][j]) isWhite = false;
			else isBlue = false;
		}
	}

	if(isBlue) return {1, 0};
	else if(isWhite) return {0, 1};
	else
	{
		auto [b1, w1] = colorpaper(x, y, N/2);
		auto [b2, w2] = colorpaper(x + N/2, y, N/2);
		auto [b3, w3] = colorpaper(x, y + N/2, N/2);
		auto [b4, w4] = colorpaper(x + N/2, y + N/2, N/2);
		return {b1 + b2 + b3 + b4, w1 + w2 + w3 + w4};
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin >> board[i][j];
		}
	}

	auto [b, w] = colorpaper(0, 0, N);
	cout << w << "\n" << b;
}