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
    int ans = 0;
    for(int i=1; i<=N; i++)
    {
        char number; cin >> number;
        //char은 공백 없이 입력받을 수 있다.
        ans += number - '0';
    }
    cout << ans;
}