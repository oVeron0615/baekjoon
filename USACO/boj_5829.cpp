#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MX = 1001;
int N, M, K;
vector<pii> graph(MX);
string dir;

int sailing(int cur)
{
    for(char d : dir)
    {
        auto [l, r] = graph[cur];
        cur = (d == 'L' ? l : r);
    }
    return cur;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    cin >> N >> M >> K;
    for(int i=1; i<=N; i++)
    {
        int x, y; cin >> x >> y;
        graph[i] = {x, y};
    }
    for(int i=0; i<M; i++)
    {
        char d; cin >> d;
        dir += d;
    }

    vector<int> vis(N+1, 0);
    vector<int> nextPort(N+1);

    int cur = 1, step = 1;
    while(!vis[cur] && K > 0)
    {
        vis[cur] = step++;
        int nxt = sailing(cur);
        cur = nextPort[cur] = nxt;
        K--;
    }

    if(K > 0)
    {
        int cycle = step - vis[cur];
        K %= cycle;

        while(K > 0) cur = sailing(cur), K--;
    }
    cout << cur;
} 