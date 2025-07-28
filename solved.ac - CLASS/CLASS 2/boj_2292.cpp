#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

//규칙이 있는 합에서 1부터 시작하는 몫 구하기
//O(sqrt(N)) : 반복문
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;
	int maxVal = 1, ans = 1;
	while(maxVal < N) maxVal += ans++ * 6;
	//층의 최댓값을 기준으로 N이 해당 층에 존재하는지 확인
	cout << ans;
}