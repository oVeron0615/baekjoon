#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int N;
string key = "";
unordered_map<string, vector<string>> prefix;
unordered_map<string, int> fm;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i{1}; i <= N; i++)
    {
        string w;
        cin >> w;

        for (int j{0}; j <= w.size(); j++)
        {
            string p = w.substr(0, j);
            if (prefix.find(p) == prefix.end())
                prefix.insert({p, vector<string>()});

            if (prefix[p].size() < 2)
            {
                prefix[p].push_back(w);
                if (fm.find(p) == fm.end())
                    fm.insert({p, i});
            }

            if (prefix[p].size() == 2)
            {
                if (key.size() < p.size() || key.size() == p.size() && fm[key] > fm[p])
                    key = p;
            }
        }
    }

    for (string s : prefix[key])
        cout << s << "\n";
}