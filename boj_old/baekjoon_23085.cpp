#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int N, K, ans{ 0 };
string s;
bool vis[3001];
queue<pair<int, int>> qu;

void bfs(int, int);

int main()
{
	cin >> N >> K >> s;

	int h{ 0 }, t{ 0 };
	for (int i{ 0 }; i < s.size(); i++)
	{
		if (s[i] == 'H') h++;
		else t++;
	}
	bfs(h, t);
}

void bfs(int h, int t)
{
	qu.push({ h, t });
	vis[t] = true;
	int cnt{ 0 }, temp{ 1 };
	while (!qu.empty())
	{
		pair<int, int> cur = qu.front();
		qu.pop();

		int x{ cur.first }, y{ cur.second };
		if (y == N)
		{
			cout << ans;
			return;
		}
		temp--;
		for (int i{ 0 }; i <= K; i++)
		{
			int a{ x - (K - i)}, b{y - i};
			if (a >= 0 && b >= 0)
			{
				a += i;
				b += K - i;
				if (!vis[b])
				{
					vis[b] = true;
					qu.push({ a, b });
					cnt++;
				}
			}
		}
	
		if (temp == 0)
		{
			ans++;
			temp = cnt;
			cnt = 0;
		}
	}
	cout << -1;
}