#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N, M; cin >> N >> M;
	string S; cin >> S;
	int len = 0; //매칭된 길이
	int ans = 0;
	for(char c : S) 
	{
		if(len % 2 == 0)
		{
			if(c == 'I') len++;
			else len = 0;
		}
		else
		{
			if(c == 'O') len++;
			else len = 1;
		}

		if(len >= N * 2 + 1 && len % 2 == 1) ans++;
	}
	cout << ans;
}
//S와 Pn을 매칭시킨다. I 다음 I, O 다음 O가 올 수 없다는 것에 주목하면 KMP를 쓰지 않고 해결할 수 있다.