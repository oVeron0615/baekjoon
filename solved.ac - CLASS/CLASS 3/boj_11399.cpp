#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;
	vector<int> times(N);
	for(int& t : times) cin >> t;
	sort(times.begin(), times.end());

	int ans = 0, psum = 0;
	for(int t : times) psum += t, ans += psum;
	cout << ans;
}

/*
마지막 사람이 인출하는 데 걸리는 시간은 어떻게 줄을 서던 같다.
끝에서 두 번째 사람이 인출하는 데 걸리는 시간은, 마지막 사람이 인출하는 데 걸리는 시간이 클수록 작을 것이다.
즉, 자기 뒤편의 사람들이 돈을 인출하는 데 걸리는 시간의 합이 크면 클수록, 자신의 시간은 작아질 것이다.
따라서 오름차순으로 정렬 후 누적합을 구하면 된다.
*/
