#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	if(n == 0) 
	{
		cout << 0;
		return 0;
	}

	int cut = round(n * 0.15);

	vector<int> opinions(n);
	for(int& opinion : opinions) cin >> opinion;
	sort(opinions.begin(), opinions.end());

	double sum = 0;
	for(int i=cut; i<n-cut; i++) sum += opinions[i];
	cout << round(sum / (n - cut * 2));
}