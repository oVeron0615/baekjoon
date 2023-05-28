#include <bits/stdc++.h>
#define AR 10000
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int k;
int alpha[26];
int l, r;
string L, R;

vector<int> graph[27 * AR];
bool vis[27 * AR];
bool isNoAns;

void DFS0(int u)
{
    if (u == 1)
    {
        isNoAns = true;
        return;
    }

    vis[u] = true;
    for (int v : graph[u])
    {
        if (vis[v])
            continue;
        DFS0(v);
    }
}
void DFS1(int u)
{
    if (u == 0)
    {
        isNoAns = true;
        return;
    }

    vis[u] = true;
    for (int v : graph[u])
    {
        if (vis[v])
            continue;
        DFS1(v);
    }
}
void DFS(int u)
{
    vis[u] = true;
    for (int v : graph[u])
    {
        if (vis[v])
            continue;
        DFS(v);
    }
}

void init()
{
    fill(&graph[0], &graph[27 * AR], vector<int>());
    memset(vis, false, sizeof(vis));
    isNoAns = false;
}

void solve()
{
    init();

    cin >> k;
    for (int i{0}; i < k; i++)
        cin >> alpha[i];
    cin >> l >> L >> r >> R;

    vector<int> vL, vR;
    for (char c : L)
    {
        if (c == '0' || c == '1')
            vL.push_back(c - '0');
        else
            for (int i{0}; i < alpha[c - 'a']; i++)
                vL.push_back((c - 'a' + 1) * AR + i);
    }
    for (char c : R)
    {
        if (c == '0' || c == '1')
            vR.push_back(c - '0');
        else
            for (int i{0}; i < alpha[c - 'a']; i++)
                vR.push_back((c - 'a' + 1) * AR + i);
    }

    if (vL.size() != vR.size())
    {
        cout << "0\n";
        return;
    }

    for (int i{0}; i < vL.size(); i++)
    {
        graph[vL[i]].push_back(vR[i]);
        graph[vR[i]].push_back(vL[i]);
    }

    for (int u : graph[0])
        DFS0(u);
    for (int u : graph[1])
        DFS1(u);
    if (isNoAns)
    {
        cout << "0\n";
        return;
    }

    int cnt = 0;
    for (int u{0}; u < (k + 1) * AR; u++)
    {
        if (vis[u] || graph[u].empty())
            continue;
        DFS(u);
        cnt++;
    }

    string ans = "1";
    while (cnt--)
    {
        int up = 0;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            int cal = (ans[i] - '0') * 2 + up;
            ans[i] = (cal % 10) + '0';
            up = cal / 10;
        }
        if (up == 1)
            ans = "1" + ans;
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int x;
    cin >> x;
    while (x--)
        solve();
}