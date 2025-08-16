#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1'000'003;
const int MAXN = 50;
ll road[MAXN][MAXN];
ll res[MAXN][MAXN];
int N, S, E, T;

void calMatrix(ll (&m1)[][MAXN], ll (&m2)[][MAXN])
{
	ll m[MAXN][MAXN] = {};
	for(int i=0; i<N*5; i++) 
		for(int j=0; j<N*5; j++) 
			for(int k=0; k<N*5; k++)
				m[i][j] += (m1[i][k] * m2[k][j]) % MOD, m[i][j] %= MOD;

	for(int i=0; i<N*5; i++) 
		for(int j=0; j<N*5; j++)
			m1[i][j] = m[i][j];
}

void solve(ll n)
{
	if(n == 0)
	{
		for(int i=0; i<N*5; i++) res[i][i] = 1;
		return;
	}

	solve(n/2);
	calMatrix(res, res);
	if(n % 2) calMatrix(res, road);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> S >> E >> T;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			char c; cin >> c;
			int len = c - '0';
			if(len > 0) road[i][j + (len - 1) * N] = 1; //i에서 j로 가는 시간이 len일 경우, 계산하기 len초 전 노드 j로 이동시킨다.
		}
	}
	for(int i=0; i<N; i++)
		for(int k=1; k<=4; k++)
			road[i + k * N][i + (k - 1) * N] = 1; //1초가 지나면 계산하기 k초 전 노드 i에서 k-1초 전 노드 i로 이동한다.

	solve(T);
	cout << res[S-1][E-1];
}