#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 1'000'001, MAXN = 500'001;
int idx[SZ], B[MAXN];
int N;

ll mergeSort(int s, int e)
{
	if(s == e) return 0;

	ll cnt = 0;
	cnt += mergeSort(s, (s+e)/2);
	cnt += mergeSort((s+e)/2+1, e);

	vector<int> merged;
	int p1 = s, p2 = (s+e)/2+1;
	while(p1 <= (s+e)/2 && p2 <= e)
	{
		if(B[p1] < B[p2]) merged.push_back(B[p1++]);
		else merged.push_back(B[p2++]), cnt += p2 - s - merged.size();
	}
	while(p1 <= (s+e)/2) merged.push_back(B[p1++]);
	while(p2 <= e) merged.push_back(B[p2++]);

	for(int i=s; i<=e; i++) B[i] = merged[i-s];
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=1; i<=N; i++)
	{
		int num; cin >> num;
		idx[num] = i;
	}
	for(int i=1; i<=N; i++)
	{
		int num; cin >> num;
		B[i] = idx[num];
	}

	cout << mergeSort(1, N);
}