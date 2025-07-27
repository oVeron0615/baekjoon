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

    double A, B; cin >> A >> B;
    cout << fixed << setprecision(9) << A/B;
    //fixed : 소수점 고정 출력
    //setprecision(n) : 유효 숫자를 n개까지 출력
    //fixed setprecision(n) : 반올림하여 소수점 아래 n자리 출력
}