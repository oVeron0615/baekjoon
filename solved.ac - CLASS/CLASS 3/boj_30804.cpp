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
	vector<int> fruits(N);
	for(int& fruit : fruits) cin >> fruit;

	int ans = 0;
	for(int f1=1; f1<=9; f1++)
	{
		for(int f2=1; f2<=9; f2++)
		{
			if(f1 == f2) continue;

			int cnt = 0;
			for(int fruit : fruits)
			{
				if(fruit == f1 || fruit == f2) cnt++;
				else cnt = 0;
				ans = max(ans, cnt);
			}
		}
	}
	cout << ans;
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

	int N; cin >> N;
	vector<int> fruits(N);
	for(int& fruit : fruits) cin >> fruit;

	int ans = 0;
	int kind_cnt = 0;
	vector<int> fruit_cnt(10);
	int l = 0;
	for(int r = 0; r < N; r++)
	{
		if(!fruit_cnt[fruits[r]]++) kind_cnt++;
		while(kind_cnt > 2)
		{
			if(!--fruit_cnt[fruits[l]]) kind_cnt--;
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans;
}
*/