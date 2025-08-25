#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 300'001, MAXC = 10'001, MAXM = 10'001;
int N, C, M;
int block;
int color[MAXN], cnt[MAXC];

struct query
{
	int l, r, q;
};
vector<query> Q;

int ans[MAXM];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> C;
	block = sqrt(N);
	for(int i=1; i<=N; i++) cin >> color[i];

	cin >> M;
	for(int i=1; i<=M; i++)
	{
		int A, B; cin >> A >> B;
		Q.push_back({A, B, i});
	}

	sort(Q.begin(), Q.end(), [](query q1, query q2) {
		if(q1.l / block != q2.l / block) return q1.l / block < q2.l / block;
		else return q1.r < q2.r;
	});

	int curL = 1, curR = 0;
	for(auto [l, r, q] : Q)
	{
		while(curR < r) cnt[color[++curR]]++;
		while(curL > l) cnt[color[--curL]]++;
		while(curR > r) --cnt[color[curR--]];
		while(curL < l) --cnt[color[curL++]];

		int mxCnt = 0, mxColor;
		for(int i=1; i<=C; i++)
		{
			if(mxCnt < cnt[i])
			{
				mxCnt = cnt[i];
				mxColor = i;
			}
		}

		if((r - l + 1) / 2 < mxCnt) ans[q] = mxColor;
		else ans[q] = -1;
	}

	for(int i=1; i<=M; i++)
	{
		if(ans[i] == -1) cout << "no\n";
		else cout << "yes " << ans[i] << "\n";
	}
}