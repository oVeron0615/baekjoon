#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

deque<char> dq;
int B = 0, W = 0;
int dir = 0;
// 0 : >, 1 : v, 2 : <, 3 : ^

void fallingDir1()
{
    while (!dq.empty())
    {
        if (dq.front() == 'w')
            break;
        else
        {
            dq.pop_front();
            B--;
        }
    }
}
void fallingDir3()
{
    while (!dq.empty())
    {
        if (dq.back() == 'w')
            break;
        else
        {
            dq.pop_back();
            B--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int Q;
    cin >> Q;
    while (Q--)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "push")
        {
            char c;
            cin >> c;
            dq.push_back(c);

            if (c == 'b')
                B++;
            else
                W++;

            if (dir == 1)
                fallingDir1();
            else if (dir == 3)
                fallingDir3();
        }
        if (cmd == "pop")
        {
            if (dq.empty())
                continue;

            if (dq.front() == 'b')
                B--;
            else
                W--;

            dq.pop_front();

            if (dir == 1) // 주의!
                fallingDir1();
        }
        if (cmd == "rotate")
        {
            char c;
            cin >> c;
            if (c == 'l')
                dir = (dir - 1 + 4) % 4;
            else
                dir = (dir + 1) % 4;

            if (dir == 1)
                fallingDir1();
            else if (dir == 3)
                fallingDir3();
        }
        if (cmd == "count")
        {
            char c;
            cin >> c;
            if (c == 'b')
                cout << B << "\n";
            else
                cout << W << "\n";
        }
    }
}