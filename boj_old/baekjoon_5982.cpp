#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int L, NW;
string P;
vector<string> W;
vector<string> endWord[1000];
string dp[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> L >> NW;
    cin >> P;
    for (int i{1}; i <= NW; i++)
    {
        string w;
        cin >> w;
        W.push_back(w);
    }

    for (int i{0}; i < L; i++)
    {
        for (string w : W)
        {
            int idx = i - w.size() + 1;
            if (idx < 0)
                continue;

            bool isMatch = true;
            for (char c : w)
            {
                if (c != P[idx] && P[idx] != '?')
                {
                    isMatch = false;
                    break;
                }
                idx++;
            }

            if (isMatch)
                endWord[i].push_back(w);
        }
    }

    fill(&dp[0], &dp[1001], "!");
    dp[0] = "";
    for (int i{1}; i <= L; i++)
    {
        string mnStr = "!";
        for (string w : endWord[i - 1])
        {
            if (dp[i - w.size()] == "!")
                continue;

            if (mnStr == "!")
                mnStr = dp[i - w.size()] + w;
            else
                mnStr = min(mnStr, dp[i - w.size()] + w);
        }
        dp[i] = mnStr;
    }
    cout << dp[L] << "\n";
}