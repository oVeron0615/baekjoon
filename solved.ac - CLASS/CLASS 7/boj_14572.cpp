#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 100'001, MAXK = 31;
	vector<int> A[MAXN];

	int N, K, D; cin >> N >> K >> D;
	vector<pii> students;
	for(int i=1; i<=N; i++)
	{
		int M, d; cin >> M >> d;
		while(M--)
		{
			int Ai; cin >> Ai;
			A[i].push_back(Ai);
		}
		students.push_back({d, i});
	}
	sort(students.begin(), students.end());

	int Acnt[MAXK] = {};
	int p2 = 0;
	int ans = 0;
	for(int p1=0; p1<N; p1++)
	{
		auto [d1, stu1] = students[p1];
		for(int a : A[stu1]) Acnt[a]++;

		while(true)
		{
			auto [d2, stu2] = students[p2];
			if(d1 - d2 <= D) break;
			for(int a : A[stu2]) Acnt[a]--;
			p2++;
		}

		auto [d2, stu2] = students[p2];
		int allAlgoCnt = 0, allKnownCnt = 0;
		for(int i=1; i<=K; i++)
		{
			if(Acnt[i]) allAlgoCnt++;
			if(Acnt[i] == p1 - p2 + 1) allKnownCnt++;
		}

		ans = max(ans, (allAlgoCnt - allKnownCnt) * (p1 - p2 + 1));
	}
	cout << ans;
}