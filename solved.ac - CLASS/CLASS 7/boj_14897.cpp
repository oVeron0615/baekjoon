#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1'000'001, MAXA = 1'000'001, MAXM = 1'000'001;
int N, M;
int block;
int A[MAXN], cnt[MAXA];
int a = 0;

struct query
{
	int l, r, q;
};
vector<query> Q;

int ans[MAXM];

void add(int Ai) { if(!cnt[Ai]++) a++; }
void remove(int Ai) { if(!--cnt[Ai]) a--; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	block = sqrt(N);

	vector<int> tmpA;
	for(int i=1; i<=N; i++)
	{
		cin >> A[i];
		tmpA.push_back(A[i]);
	}

	sort(tmpA.begin(), tmpA.end());
	tmpA.erase(unique(tmpA.begin(), tmpA.end()), tmpA.end());
	for(int i=1; i<=N; i++)
		A[i] = lower_bound(tmpA.begin(), tmpA.end(), A[i]) - tmpA.begin() + 1;

	cin >> M;
	for(int q=1; q<=M; q++)
	{
		int i, j; cin >> i >> j;
		Q.push_back({i, j, q});
	}

	sort(Q.begin(), Q.end(), [](query q1, query q2) {
		if(q1.l / block != q2.l / block) return q1.l / block < q2.l / block;
		else return q1.r < q2.r;
	});

	int curL = 1, curR = 0;
	for(auto [l, r, q] : Q)
	{
		while(curR < r) add(A[++curR]);
		while(curL > l) add(A[--curL]);
		while(curR > r) remove(A[curR--]);
		while(curL < l) remove(A[curL++]);

		ans[q] = a;
	}

	for(int i=1; i<=M; i++) cout << ans[i] << "\n";
}