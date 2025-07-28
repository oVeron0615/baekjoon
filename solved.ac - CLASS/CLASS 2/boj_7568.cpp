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

	int N; cin >> N;
	vector<pii> dongchi(N);
	for(pii& i : dongchi)
	{
		int x, y; cin >> x >> y;
		i = {x, y};
	}

	for(int i=0; i<N; i++)
	{
		int grade = 1;
		for(int j=0; j<N; j++)
		{
			if(dongchi[i].first < dongchi[j].first 
				&& dongchi[i].second < dongchi[j].second) grade++;
		}
		cout << grade << " ";
	}
}