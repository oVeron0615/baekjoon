#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    string S; cin >> S;
    int len = S.length();

    int dp[100][100];
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len; j++)
        {
            dp[i][j] = 1;
        }
    }
    dp[0][len-1] = 0;

    for(int i=0; i<len; i++)
    {
        for(int l=0; l<len-i; l++)
        {
            int r = l + i;

            for(int m=r-1; m>=(l+r+1)/2; m--)
            {
                string s1 = S.substr(l, m-l+1);
                string s2 = S.substr(m+1, r-m);
                
                if(s1.find(s2) == 0) dp[l][r] = (dp[l][r] + dp[l][m]) % 2014;
                if(s1.rfind(s2) == s1.length() - s2.length()) dp[l][r] = (dp[l][r] + dp[l][m]) % 2014;
            }

            for(int m=l+1; m<=(l+r)/2; m++)
            {
                string s1 = S.substr(m, r-m+1);
                string s2 = S.substr(l, m-l);
                
                if(s1.find(s2) == 0) dp[l][r] = (dp[l][r] + dp[m][r]) % 2014;
                if(s1.rfind(s2) == s1.length() - s2.length()) dp[l][r] = (dp[l][r] + dp[m][r]) % 2014;
            }
        }
    }

    cout << dp[0][len-1];
}