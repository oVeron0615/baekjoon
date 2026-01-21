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
    vector<int> a(N + 1), b(N + 1);

    int sum = 0;
    for(int i=1; i<=N; i++) 
    {
        cin >> a[i];
        sum += a[i];
    }
    for(int i=1; i<=N; i++)
    {
        cin >> b[i];
        sum += b[i];
    } 

    int mxSum = 0;
    for(int i=1; i<=N-2; i++) mxSum += max(a[i], b[i]);
    mxSum += max(a[N-1] + b[N], b[N-1] + a[N]);

    int mnSum = sum - mxSum;
    cout << mxSum - mnSum;
}