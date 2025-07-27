#include <bits/stdc++.h>
#define inf -1e18
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

int N, M;
vector<int> graph[32001];
int cache[32001];
stack<int> st;
bool isCycle = false;

void solve(int u)
{
    cache[u] = 2; // 방문 처리 완료
    for (int v : graph[u])
    {
        if (cache[v] == 1)  // 현재 방문 중
            isCycle = true; // 방문 중인 정점을 또 방문했다면 사이클 존재
        if (cache[v] == 0)  // 아직 방문하지 않음
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
        if (cache[i] == 0) // 아직 방문하지 않은 정점들을 DFS한다.
            solve(i);

    if (isCycle)
    {
        cout << -1 << "\n";
        return 0;
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}