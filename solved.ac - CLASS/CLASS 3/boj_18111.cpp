#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N, M, B; cin >> N >> M >> B;
	vector<int> heights;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=M; j++)
		{
			int h; cin >> h;
			heights.push_back(h);
		}
	}

	int ansT = 1e9, ansH;
	for(int h=0; h<=256; h++)
	{
		int b = B, t = 0;
		for(int height : heights)
		{
			if(height > h) 
			{
				t += (height - h) * 2;
				b += height - h;
			}
			else
			{
				t += h - height;
				b -= h - height;
			}
		}

		if(b >= 0)
		{
			if(ansT >= t) ansT = t, ansH = h;
		}
	}

	cout << ansT << " " << ansH;
}