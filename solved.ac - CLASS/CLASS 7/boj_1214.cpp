#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int D, P, Q; cin >> D >> P >> Q;
	if(P > Q) swap(P, Q);

	int ans = D + P;
	//P * x + Q * y = D + r;
	//x를 구할 때 P로 값을 나누므로, 나머지 r은 0~P-1 범위이다. 따라서 반복문을 P번만 실행한다.
	//y의 범위는 0 ~ D / Q + 1이다. 
	//Q 값이 sqrt(Q)보다 작으면 P < Q에 의해 반복문은 P번 실행되고, sqrt(Q)보다 크면 D / Q + 1번 실행된다.
	//시간복잡도는 sqrt(Q)이다.
	for(int y=0; y<=min(P, D / Q + 1); y++)
	{
		int x; //해를 직접 구해 최솟값을 찾는다.
		if(Q * y >= D) x = 0;
		else x = (D - Q * y) / P + ((D - Q * y) % P ? 1 : 0);
		ans = min(ans, P * x + Q * y);
	}
	cout << ans; 
}