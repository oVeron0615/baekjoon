#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 101;
int A[SZ], B[SZ];
vector<int> ans;
int AIdx = 0, BIdx = 0;
int N, M;
vector<pii> sortedA;

auto cmp = [](pii p1, pii p2)
{
	if(p1.first == p2.first) return p1.second < p2.second;
	else return p1.first > p2.first;
};

bool check()
{
	for(auto [Ai, i] : sortedA)
	{
		for(int j=BIdx+1; j<=M; j++)
		{
			if(Ai == B[j]) 
			{
				AIdx = i, BIdx = j;
				ans.push_back(Ai);
				return true;
			}
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=1; i<=N; i++) cin >> A[i];
	cin >> M;
	for(int i=1; i<=M; i++) cin >> B[i];
	
	do {
		sortedA.clear();
		for(int i=AIdx+1; i<=N; i++) sortedA.push_back({A[i], i});
		sort(sortedA.begin(), sortedA.end(), cmp);
	} while(check());

	cout << ans.size() << "\n";
	for(int a : ans) cout << a << " ";
}