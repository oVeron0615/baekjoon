#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100'001;
ll a[MAXN], b[MAXN];
ll dp[MAXN];
int n;

struct line
{
	ll sl, ic; //기울기, 절편
	double start; //선분의 시작점의 x좌표
};
vector<line> lines;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n; i++) cin >> b[i];

	lines.push_back({b[1], 0, 0.0}); //초기 선분
	for(int i=2; i<=n; i++)
	{
		//x좌표가 a[i]인 선분을 이분 탐색으로 찾기 - lower_bound를 쓰면 end()를 찾을 수 있으므로 upper_bound 이후 prev 적용
		line x = {0, 0, double(a[i])};
		line res = *prev(upper_bound(lines.begin(), lines.end(), x, [](line l1, line l2){
			return l1.start < l2.start;
		}));

		dp[i] = res.sl * a[i] + res.ic;
		line l1 = {b[i], dp[i], 0.0};

		while(true)
		{
			line l2 = lines.back();
			double cross = (double)(l2.ic - l1.ic) / (l1.sl - l2.sl); //새로 만든 선분과 맨 뒤의 선분의 교차점
			if(cross <= l2.start) //뒤의 선분의 시작점의 x좌표보다 교차점의 x좌표가 더 작다면, 맨 뒤의 선분을 제거한다.
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