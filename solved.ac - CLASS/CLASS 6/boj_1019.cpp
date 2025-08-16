#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll N; cin >> N;
	for(int i=0; i<10; i++) //i : 찾고자 하는 탐색 숫자
	{
		ll ans = 0, val = 1; //val : 현재 위치
		while(val <= N)
		{
			ll upper_num = N / (val * 10); //upper_num : 현재 위치의 상위 숫자들
			ll cur_num = N % (val * 10) / val; //cur_num : 현재 위치의 숫자

			if(i == 0) upper_num--; //숫자의 앞자리가 0일 수는 없으므로, 상위 숫자에 1을 뺀다.
				 	
			ans += upper_num * val; //0 ~ upper_num - 1 만큼, 현재 위치의 숫자가 val개씩 존재
			if(i < cur_num) ans += val; //탐색 숫자가 현재 숫자보다 작다면, upper_num에도 탐색 숫자가 val만큼 존재
			else if(i == cur_num) ans += N % val + 1; //탐색 숫자가 현재 숫자와 같다면, 0 ~ 현재 위치의 하위 숫자들만큼 탐색 숫자가 존재

			val *= 10;
		}
		cout << ans << " ";
	}
}