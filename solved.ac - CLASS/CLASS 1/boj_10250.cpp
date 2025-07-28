#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

//등차수열에서 1부터 시작하는 나머지, 몫 구하기

//O(1) 수학
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    
    int T; cin >> T;
    while(T--)
    {
        int H, W, N; cin >> H >> W >> N;
        int ansH = (N + H - 1) % H + 1, ansW = (N + H - 1) / H;
        //올림 나눗셈 -> 수를 1이 아닌 H부터 시작하게 한다.
        cout << ansH << setw(2) << setfill('0') << ansW << "\n";
    }
}

//O(N) 반복문
/*
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
	while (T--)
	{
		int H, W, N; cin >> H >> W >> N;
		int maxVal = 0, ansW = 0;
		while(maxVal < N)
		{
			maxVal += H; //등차수열을 직접 만든다
			ansW++;
		}
		int ansH = N - (ansW - 1) * H;

		cout << ansH << setw(2) << setfill('0') << ansW << "\n";
	}
}
*/