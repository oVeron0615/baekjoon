#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100'001, MAXP = 3'000'001;
int N;
vector<int> fibo;
int g[MAXP];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	fibo.push_back(1); fibo.push_back(1);
	while(true)
	{
		int sum = fibo[fibo.size()-1] + fibo[fibo.size()-2];
		if(sum > MAXP) break;
		fibo.push_back(sum);
	}

	for(int i=1; i<MAXP; i++)
	{
		bool isExist[50] = {};
		for(int f : fibo)
		{
			if(i-f < 0) break;
			isExist[g[i-f]] = true;
		}

		int mex = 0;
		while(isExist[mex]) mex++;
		g[i] = mex;
	}

	int nim_sum = 0;

	cin >> N;
	for(int i=1; i<=N; i++)
	{
		int pi; cin >> pi;
		nim_sum ^= g[pi];
	}

	if(nim_sum) cout << "koosaga";
	else cout << "cubelover";
}