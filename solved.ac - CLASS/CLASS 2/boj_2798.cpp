#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N, M; cin >> N >> M;
	vector<int> card(N);
	for(int& cardi : card) cin >> cardi;

	int ans = 0;
	for(int i=0; i<N; i++)
	{
		for(int j=i+1; j<N; j++)
		{
			for(int k=j+1; k<N; k++)
			{
				int sum = card[i] + card[j] + card[k];
				if(sum <= M) ans = max(ans, sum);
			}
		}
	}
	cout << ans;
}