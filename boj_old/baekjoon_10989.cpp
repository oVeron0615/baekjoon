#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

int N;
int arr[10001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for (int i{1}; i <= N; i++)
	{
		int n;
		cin >> n;
		arr[n]++;
	}

	for (int i{1}; i <= 10000; i++)
		for (int j{1}; j <= arr[i]; j++)
			cout << i << "\n";
}