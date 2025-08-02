#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1001;
int N;
int A[MAXN], dpLIS[MAXN], dpLDS[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=1; i<=N; i++) cin >> A[i];

	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<i; j++)
		{
			if(A[i] > A[j]) dpLIS[i] = max(dpLIS[i], dpLIS[j]);
		}
		dpLIS[i] += 1;
	}
	for(int i=N; i>=1; i--)
	{
		for(int j=N; j>i; j--)
		{
			if(A[i] > A[j]) dpLDS[i] = max(dpLDS[i], dpLDS[j]);
		}
		dpLDS[i] += 1;
	}

	int ans = 0;
	for(int i=1; i<=N; i++) ans = max(ans, dpLIS[i] + dpLDS[i] - 1);
	cout << ans;
}