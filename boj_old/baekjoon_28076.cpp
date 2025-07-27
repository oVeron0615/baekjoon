#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int N;
int tab[200001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i{1}; i <= N; i++)
        cin >> tab[i];
    sort(tab + 1, tab + N + 1);

    int q = N / 3;
    if (N == 1)
        cout << tab[1];
    else if (N == 2)
        cout << tab[1] + tab[2] - 1;
    else if (N % 3 == 0 || N % 3 == 1)
        cout << tab[q] + tab[q * 2] + tab[N] - 3;
    else if (N % 3 == 2)
        cout << tab[q] + tab[q * 2 + 1] + tab[N] - 3;
}