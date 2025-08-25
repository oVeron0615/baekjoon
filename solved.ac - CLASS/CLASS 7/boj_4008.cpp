#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1'000'001;
ll n, a, b, c;
ll sum[MAXN];
ll dp[MAXN]; 
//dp[i] = max(-2a*sum[j]*sum[i] + (a*sum[j]*sum[j]-b*sum[j]+dp[j])) + a*sum[i]*sum[i] + b*sum[i] + c
//sum[i]를 변수 x라 생각하면 컨벡스 헐 트릭을 이용할 수 있다.

struct line
{
	ll sl, ic;
	double start;
};
vector<line> lines;

ll calSl(int i) { return -2 * a * sum[i]; }
ll calIc(int i) { return a * sum[i] * sum[i] - b * sum[i] + dp[i]; }
ll calC(int i) { return a * sum[i] * sum[i] + b * sum[i] + c; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> a >> b >> c;
	for(int i=1; i<=n; i++)
	{
		ll xi; cin >> xi;
		sum[i] += sum[i-1] + xi;
	}

	lines.push_back({calSl(0), calIc(0), 0.0});

	for(int i=1; i<=n; i++)
	{
		line x = {0, 0, double(sum[i])};
		line res = *prev(upper_bound(lines.begin(), lines.end(), x, [](line l1, line l2) {
			return l1.start < l2.start;
		}));

		dp[i] = res.sl * sum[i] + res.ic + calC(i);
		line l1 = {calSl(i), calIc(i), 0.0};

		while(true)
		{
			line l2 = lines.back();
			double cross = (double)(l2.ic - l1.ic) / (l1.sl - l2.sl);
			if(cross <= l2.start)
			{
				lines.pop_back();
				continue;
			}

			l1.start = cross;
			lines.push_back(l1);
			break;
		}
	}

	cout << dp[n];
}