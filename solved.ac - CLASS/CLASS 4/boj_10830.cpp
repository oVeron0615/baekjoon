#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 6, MOD = 1000;
int A[MAXN][MAXN], ans[MAXN][MAXN];
int N;
ll B;

void calMatrix(int (&M1)[MAXN][MAXN], int (&M2)[MAXN][MAXN])
{
	int M[MAXN][MAXN] = {};
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			for(int k=1; k<=N; k++)
				M[i][j] += (M1[i][k] * M2[k][j]) % MOD, M[i][j] %= MOD;

	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			M1[i][j] = M[i][j];
}

void solve(ll b)
{
	if(b == 0)
	{
		for(int i=1; i<=N; i++) ans[i][i] = 1;
		return;
	}

	solve(b/2);
	calMatrix(ans, ans);
	if(b % 2) calMatrix(ans, A);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> B;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			cin >> A[i][j];

	solve(B);

	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}