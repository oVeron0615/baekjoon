#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1'000'000;
int n;
int slot[MAXN], LPS[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for(int i=n-1; i>=0; i--) cin >> slot[i];

	int len = 0;
	for(int i=1; i<n; i++)
	{
		while(len > 0 && slot[i] != slot[len]) len = LPS[len-1];
		if(slot[i] == slot[len]) LPS[i] = ++len;
	}

	int k = n, p = n;
	for(int i=0; i<n; i++)
	{
		int tmpk = n-1-i, tmpp = i + 1 - LPS[i];
		if(k + p > tmpk + tmpp || k + p == tmpk + tmpp && p > tmpp)
			k = tmpk, p = tmpp;
	}
	cout << k << " " << p;
}