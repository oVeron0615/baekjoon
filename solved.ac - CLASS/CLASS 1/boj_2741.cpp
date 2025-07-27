#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int main()
{
	ios::sync_with_stdio(0);
    //c++의 표준 입출력과 c의 표준 입출력이 동기화(sync)되어 있기에, 이를 꺼준다.
    //이렇게 하면 cin, cout 입출력이 훨씬 빨라진다.
	cin.tie(0), cout.tie(0);
    //cin은 기본적으로 cout과 묶여(tied)있다.
    //따라서 cin에서 입력을 받기 전 항상 cout을 비워(flush)준다.
    //이를 해제하여 불필요한 flush를 막는다.

    int N; cin >> N;
    for(int i=1; i<=N; i++) cout << i << "\n";
}