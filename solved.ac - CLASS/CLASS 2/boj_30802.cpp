#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;
	vector<int> appCnt(6);
	for(int& appCnti : appCnt) cin >> appCnti;
	int T, P; cin >> T >> P;

	int ansT = 0;
	for(int appCnti : appCnt) 
	{
		if(appCnti == 0) continue;
		ansT += (appCnti - 1) / T + 1;
		//사이즈 입력값이 0이면 괄호 안 값이 음수가 되므로 예외 처리한다.
	}

	cout << ansT << "\n";
	cout << N / P << " " << N % P;
}