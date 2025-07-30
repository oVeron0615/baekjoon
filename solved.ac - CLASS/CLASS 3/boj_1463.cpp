#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;
	vector<int> num_cnt(N+1, 0);
	for(int i=2; i<=N; i++)
	{
		num_cnt[i] = num_cnt[i-1];
		if(i % 3 == 0) num_cnt[i] = min(num_cnt[i], num_cnt[i/3]);
		if(i % 2 == 0) num_cnt[i] = min(num_cnt[i], num_cnt[i/2]);
		num_cnt[i]++;
	}
	cout << num_cnt[N];
}

/*
#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define MAX 1e9

int DP(vector<int>& num_cnt, int N)
{
	if(num_cnt[N] != -1) return num_cnt[N];
	if(N == 1) return num_cnt[N] = 0;

	num_cnt[N] = MAX;
	if(N % 3 == 0) num_cnt[N] = min(num_cnt[N], DP(num_cnt, N/3));
	if(N % 2 == 0) num_cnt[N] = min(num_cnt[N], DP(num_cnt, N/2));
	num_cnt[N] = min(num_cnt[N], DP(num_cnt, N-1));
	return num_cnt[N] += 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;
	vector<int> num_cnt(N+1, -1);
	cout << DP(num_cnt, N);
}
*/