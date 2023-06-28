#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

int N, K;
int A[500001];
vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;

    for (int i{1}; i <= N; i++)
        cin >> A[i];

    for (int i{1}; i <= N; i++)
        if (i < N && A[i] > A[i + 1])
            v.push_back(i);

    int cnt = 0;
    while (!v.empty())
    {
        int idx = v[0];
        vector<int> tmp;

        while (true)
        {
            idx = v[lower_bound(v.begin(), v.end(), idx) - v.begin()];

            while (idx < N && A[idx] > A[idx + 1])
            {
                swap(A[idx], A[idx + 1]);

                cnt++;
                if (cnt == K)
                    break;

                if (idx > 1 && A[idx - 1] > A[idx])
                    tmp.push_back(idx - 1);
                idx++;
            }

            if (cnt == K)
                break;

            if (idx > v[v.size() - 1])
                break;
        }

        if (cnt == K)
            break;

        v = tmp;
    }

    if (cnt < K)
        cout << -1;
    else
        for (int i{1}; i <= N; i++)
            cout << A[i] << " ";
}