#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N; cin >> N;
    int cntT = 0, cntS = 0;
    while(N--)
    {
        string S;
        cin.ignore();
        getline(cin, S);

        for(char c : S)
        {
            if(c == 't' || c == 'T') cntT++;
            else if(c == 's' || c == 'S') cntS++;
        }
    }

    cout << (cntT > cntS ? "English" : "French");
}