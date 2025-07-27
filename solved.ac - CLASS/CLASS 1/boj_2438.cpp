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
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}