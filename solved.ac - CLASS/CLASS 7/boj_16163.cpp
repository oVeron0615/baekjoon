#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string tmp, S = "!";
const int SZ = 4'000'001;
int center = -1, arc = -1;
int rad[SZ];
ll ans = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> tmp;
	for(char c : tmp) //짝수 팰린드롬은 구하지 못 하기에, 임의의 문자를 끼워 넣어 짝수 팰린드롬을 홀수로 만든다.
	{
		S.push_back(c);
		S.push_back('!');
	}

	for(int i=0; i<S.size(); i++)
	{
		if(i <= arc) rad[i] = min(arc - i, rad[2 * center - i]);
		while(true)
		{
			int l = i - rad[i] - 1, r = i + rad[i] + 1; //팰린드롬 직접 찾기
			if(l >= 0 && r < S.size() && S[l] == S[r]) //팰린드롬이라면 ark, center, rad[i]를 갱신한다.
			{
				if(arc < i + ++rad[i]) arc = i + rad[i], center = i;
			}
			else break;
		}
		ans += (rad[i] + 1) / 2; //반지름 길이가 (2배 - 1)이 되었기에, 답은 2로 나눠야 한다.
	}

	cout << ans;
}