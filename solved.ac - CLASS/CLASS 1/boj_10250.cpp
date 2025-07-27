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
    
    int T; cin >> T;
    while(T--)
    {
        int H, W, N; cin >> H >> W >> N;
        int ansH = (N - 1) % H + 1, ansW = (N - 1) / H + 1;
        cout << ansH << setw(2) << setfill('0') << ansW << "\n";
    }
}
/*
주어진 수가 N, 단위가 H인, 1부터 시작하는 몫과 나머지

- 몫
N : ansW
1, 2, ... , H : 1
H+1, H+2, ... , H*2 : 2

N-1 : ansW-1
0, 1, ... , H-1 : 0
H, H+1, ... , H*2-1 : 1

(N-1)/H = ansW-1
ansW = (N-1)/H + 1


- 나머지
N : ansH
1, 2, ... , H : 1, 2, ... , H
H+1, H+2, ... , H*2 : 1, 2, ... , H

N-1 : ansH-1
0, 1, ... , H-1 : 0, 1, ... , H-1
H, H+1, ... , H*2-1 : 0, 1, ... , H-1

(N-1)%H = ansH-1
ansH = (N-1)%H + 1
*/