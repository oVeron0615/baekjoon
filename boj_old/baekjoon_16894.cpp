#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

ll N;
ll cnt = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    while (N != 1)
    {
        bool prime = true;
        for (ll i{2}; i * i <= N; i++)
        {
            if (N % i == 0)
            {
                N /= i, cnt++;
                prime = false;
                break;
            }
        }

        if (prime)
            N = 1, cnt++;
    }

    if (cnt == 2)
        cout << "cubelover";
    else
        cout << "koosaga";
}