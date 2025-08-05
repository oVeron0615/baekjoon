#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 1'000'001;
	int num[MAXN];
	bool isExist[MAXN] = {};
	int ans[MAXN] = {};

	int N; cin >> N;
	for(int i=1; i<=N; i++)
	{
		cin >> num[i];
		isExist[num[i]] = true;
	}

	for(int i=1; i<=N; i++)
	{
		int n = num[i];
		for(int m=n*2; m<MAXN; m+=n)
		{
			if(isExist[m]) ans[n]++, ans[m]--;
		}
	}

	for(int i=1; i<=N; i++) cout << ans[num[i]] << " ";
}

/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 1'000'001;
	int num[MAXN];
	bool isExist[MAXN] = {};
	int ans[MAXN] = {};

	int N; cin >> N;
	for(int i=1; i<=N; i++)
	{
		cin >> num[i];
		isExist[num[i]] = true;
	}

	for(int i=1; i<=N; i++)
	{
		int n = num[i];
		for(int m=1; m*m<=n; m++)
		{
			if(n % m == 0 && isExist[m]) ans[n]--, ans[m]++;
			if(n != m * m && n % m == 0 && isExist[n/m]) ans[n]--, ans[n/m]++;
		}
	}

	for(int i=1; i<=N; i++) cout << ans[num[i]] << " ";
}
*/