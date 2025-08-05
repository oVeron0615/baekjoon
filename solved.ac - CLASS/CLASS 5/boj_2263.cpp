#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100001;
int inorder[MAXN], postorder[MAXN];
int n;

void solve(int si, int ei, int sp, int ep)
{
	if(si > ei || sp > ep) return;

	cout << postorder[ep] << " ";

	int R = si;
	while(inorder[R] != postorder[ep]) R++;

	solve(si, R-1, sp, sp+R-si-1);
	solve(R+1, ei, ep+R-ei, ep-1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for(int i=1; i<=n; i++) cin >> inorder[i];
	for(int i=1; i<=n; i++) cin >> postorder[i];

	solve(1, n, 1, n);
}