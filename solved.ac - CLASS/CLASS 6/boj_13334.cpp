#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

auto cmp = [](pii p1, pii p2) { return p1.second < p2.second; };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const int MAXN = 100001;
	int n; cin >> n;
	pii line[MAXN];

	for(int i=1; i<=n; i++)
	{
		int s, e; cin >> s >> e;
		if(s > e) swap(s, e);
		line[i] = {s, e};
	}
	sort(line + 1, line + n + 1, cmp); //끝점을 기준으로 정렬

	int d; cin >> d;
	priority_queue<pii, vector<pii>, greater<pii>> pq; //철로에 들어갈 수 있는 선분들을 시작점을 기준으로 정렬
	int ans = 0;
	for(int i=1; i<=n; i++) //끝점을 기준으로 정렬된 선분들을 하나씩 살펴본다.
	{
		pq.push(line[i]);
		//어떠한 선분의 시작점이 방금 넣은 선분의 끝점보다 거리가 d보다 더 떨어져 있다면, 그 선분은 철로에 포함될 수 없다.
		while(!pq.empty() && pq.top().first < line[i].second - d) pq.pop();
		ans = max(ans, int(pq.size()));
	}
	cout << ans;
}