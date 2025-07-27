#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	vector<long long> P[2000], Wh[2000], Bh;
	long long Bp;
	long long p[2001] = {}, h{ 0 };

	int N, M, Q; cin >> N >> M >> Q;
	for (int m{ 0 }; m < M; m++)
	{
		int c; cin >> c;
		for (int i{ 0 }; i < c; i++)
		{
			long long p; cin >> p;
			P[m].push_back(p);
		}
		for (int i{ 0 }; i < c; i++)
		{
			long long wh; cin >> wh;
			Wh[m].push_back(wh);
		}
		long long bh; cin >> bh;
		Bh.push_back(bh);
	}
	for (int m{ 0 }; m < M; m++)
	{
		long long Wp; cin >> Wp;
		for (int i{ 0 }; i < Wh[m].size(); i++)
		{
			Wh[m][i] *= Wp;
		}
		Bh[m] *= Wp;
	}
	cin >> Bp;
	
	for (int m{ 0 }; m < M; m++)
	{
		for (int i{ 0 }; i < P[m].size(); i++)
		{
			p[P[m][i]] += Wh[m][i];
		}
		h += Bh[m];
	}

	for (int q{ 0 }; q < Q; q++)
	{
		long long ans{ 0 }, A;
		for (int i{ 0 }; i < N; i++)
		{
			cin >> A;
			ans += A * p[i + 1];
		}
		ans += h + Bp;
		cout << ans << "\n";
	}
}