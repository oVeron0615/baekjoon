#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 100'001;
	ll histo[MAXN];

	while(true)
	{
		int n; cin >> n;
		if(n == 0) break;

		ll ans = 0;
		stack<int> st;
		for(int i=0; i<=n; i++) 
		{
			ll curH;
			if(i == n) curH = 0;
			else 
			{
				cin >> histo[i];
				curH = histo[i];
			}

			while(!st.empty() && histo[st.top()] > curH)
			{
				ll h = histo[st.top()]; st.pop();
				ll w = st.empty() ? i : i - st.top() - 1;
				ans = max(ans, h * w);
			}
			st.push(i);
		}

		cout << ans << "\n";
	}
}

/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100'001;
ll histo[MAXN], width[MAXN];
int n;

void solve(bool check)
{
	stack<pll> st;
	for(int i=1; i<=n; i++)
	{
		ll cnt = 1;
		while(!st.empty() && st.top().first > histo[i])
		{
			cnt += st.top().second;
			st.pop();
		}
		if(st.empty() || st.top().first < histo[i]) st.push({histo[i], cnt});
		else st.top().second += cnt;

		width[i] += st.top().second;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	while(true)
	{
		cin >> n;
		if(n == 0) break;

		for(int i=1; i<=n; i++) cin >> histo[i];
		memset(width, -1, sizeof(width));

		solve(0);
		reverse(histo + 1, histo + n + 1);
		reverse(width + 1, width + n + 1);
		solve(1);

		ll ans = 0;
		for(int i=1; i<=n; i++) ans = max(ans, histo[i] * width[i]);
		cout << ans << "\n";
	}
}
*/