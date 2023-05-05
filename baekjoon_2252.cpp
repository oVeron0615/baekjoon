#include <bits/stdc++.h>
#define inf -1e18
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

int N, M;
vector<int> graph[32001];
bool vis[32001];
stack<int> st;

void solve(int u)
{
    vis[u] = true;
    for (int v : graph[u])
    {
        if (vis[v])
            continue;
        solve(v);
    }
    st.push(u);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    for (int i{1}; i <= M; i++)
    {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
    }

    for (int i{1}; i <= N; i++)
        if (!vis[i])
            solve(i);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}