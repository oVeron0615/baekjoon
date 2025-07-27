#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

int N;
char ans[12][20];
bool visBorder[12][20];
char visAni[12][20];
int dir[2][4] = {{-2, 2, 0, 0}, {0, 0, -4, 4}};
char curAni;
bool isNotAns = false;

void aniDFS(int cx, int cy)
{
    visAni[cx][cy] = curAni;
    for (int i{0}; i < 4; i++)
    {
        int nx = cx + dir[0][i];
        int ny = cy + dir[1][i];

        if (nx >= 3 && nx <= 1 + 2 * N && ny >= 4 && ny <= 4 * N)
        {
            int midX = (cx + nx) / 2;
            int midY = (cy + ny) / 2;

            if (ans[midX][midY] != ' ')
                continue;

            if (visAni[nx][ny] == curAni)
                continue;
            else if (visAni[nx][ny] == 0)
            {
                if (ans[nx][ny] == '.' || ans[nx][ny] == curAni)
                    aniDFS(nx, ny);
                else
                {
                    isNotAns = true;
                    return;
                }
            }
            else
            {
                isNotAns = true;
                return;
            }
        }

        if (isNotAns)
            return;
    }
}

void borderDFS(int cx, int cy)
{
    if (cx == 2 + 2 * N && cy == 2 + 4 * N)
    {
        memset(visAni, 0, sizeof(visAni));
        isNotAns = false;

        for (int i{3}; i <= 1 + N * 2; i += 2)
        {
            for (int j{4}; j <= N * 4; j += 4)
            {
                if (visAni[i][j] == 0 && ans[i][j] != '.')
                {
                    curAni = ans[i][j];
                    aniDFS(i, j);
                }

                if (isNotAns)
                    return;
            }
        }

        cout << "yes\n";
        for (int i{1}; i <= 3 + 2 * N; i++)
        {
            for (int j{1}; j <= 3 + 4 * N; j++)
            {
                cout << ans[i][j];
            }
            cout << "\n";
        }
        exit(0);
    }

    visBorder[cx][cy] = true;
    for (int i{0}; i < 4; i++)
    {
        int nx = cx + dir[0][i];
        int ny = cy + dir[1][i];

        if (nx >= 1 && nx <= 3 + 2 * N && ny >= 1 && ny <= 3 + 4 * N)
        {
            if (visBorder[nx][ny])
                continue;

            int midX = (cx + nx) / 2;
            int midY = (cy + ny) / 2;

            if (cx == nx)
            {
                ans[midX][midY - 1] = '-';
                ans[midX][midY] = '-';
                ans[midX][midY + 1] = '-';
            }
            else
                ans[midX][midY] = '|';

            borderDFS(nx, ny);

            if (cx == nx)
            {
                ans[midX][midY - 1] = ' ';
                ans[midX][midY] = ' ';
                ans[midX][midY + 1] = ' ';
            }
            else
                ans[midX][midY] = ' ';
        }
    }
    visBorder[cx][cy] = false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    fill(&ans[0][0], &ans[11][20], ' ');

    cin >> N;
    for (int i{1}; i <= N; i++)
    {
        for (int j{1}; j <= N; j++)
        {
            char c;
            cin >> c;
            ans[1 + i * 2][j * 4] = c;
        }
    }

    for (int i{1}; i <= 3 + 2 * N; i++)
    {
        for (int j{1}; j <= 3 + 4 * N; j++)
        {
            if (i == 1 || i == 3 + 2 * N || j == 1 || j == 3 + 4 * N)
                ans[i][j] = '#';
            else if (i % 2 == 0 && (j - 2) % 4 == 0)
                ans[i][j] = '+';
        }
    }

    borderDFS(2, 2);
    cout << "no\n";
}