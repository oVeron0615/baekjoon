#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 300'001;
int N;
int A[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=1; i<=N; i++) cin >> A[i];

	int cnt = 1, seq = 0, mxSeq = 0;
	for(int i=1; i<=N; i++)
	{
		if(A[i-1] <= A[i]) seq++;
		else seq = 1, cnt++;
		mxSeq = max(mxSeq, seq);
	}

	cout << cnt << " " << mxSeq;
}