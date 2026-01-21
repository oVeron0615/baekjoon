#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int R, S; cin >> R >> S;
    vector<vector<char>> board(R + 1, vector<char>(S + 1));

    for(int i=1; i<=R; i++)
        for(int j=1; j<=S; j++)
            cin >> board[i][j];
    
    int dir[2][8] = {{-1, 1, 0, 0, -1, -1, 1, 1}, {0, 0, -1, 1, -1, 1, -1, 1}};
    int ans = 0;
    int mxCnt = 0;
    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=S; j++)
        {
            int cnt = 0;
            for(int d=0; d<8; d++)
            {
                int ni = i + dir[0][d];
                int nj = j + dir[1][d];

                if(ni < 1 || ni > R || nj < 1 || nj > S) continue;

                if(board[i][j] == 'o') ans += (board[ni][nj] == 'o' ? 1 : 0);
                else cnt += (board[ni][nj] == 'o' ? 1 : 0);
            }

            mxCnt = max(mxCnt, cnt);
        }
    }

    cout << ans / 2 + mxCnt;
}