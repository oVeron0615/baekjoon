#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, mx{ 0 };
int board[20][20];

void f(int);

int main()
{
	cin >> N;
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	f(0);
	cout << mx;
}

void f(int cnt)
{
	if (cnt == 5)
	{
		for (int i{ 0 }; i < N; i++)
		{
			for (int j{ 0 }; j < N; j++)
			{
				mx = max(mx, board[i][j]);
			}
		}
		return;
	}

	int tboard[20][20];
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			tboard[i][j] = board[i][j];
		}
	}

	for (int i{ 0 }; i < N; i++)
	{
		vector<int> v1, v2;
		queue<int> qu;
		for (int j{ 0 }; j < N; j++)
		{
			if (board[i][j] != 0) v1.push_back(board[i][j]);
		}

		for (int j{ 0 }; j < v1.size(); j++)
		{
			qu.push(v1[j]);
			if (qu.size() == 2)
			{
				if (qu.front() == qu.back())
				{
					v2.push_back(qu.front() * 2);
					qu.pop(); qu.pop();
				}
				else
				{
					v2.push_back(qu.front());
					qu.pop();
				}
			}
			if (j == v1.size() - 1)
			{
				while (!qu.empty())
				{
					v2.push_back(qu.front());
					qu.pop();
				}
			}
		}

		for (int j{ 0 }; j < N; j++)
		{
			if (j < v2.size()) board[i][j] = v2[j];
			else board[i][j] = 0;
		}
	}
	f(cnt + 1);
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			board[i][j] = tboard[i][j];
		}
	}

	for (int i{ 0 }; i < N; i++)
	{
		vector<int> v1, v2;
		queue<int> qu;
		for (int j{ 0 }; j < N; j++)
		{
			if (board[i][j] != 0) v1.push_back(board[i][j]);
		}

		for (int j = v1.size() - 1; j >= 0; j--)
		{
			qu.push(v1[j]);
			if (qu.size() == 2)
			{
				if (qu.front() == qu.back())
				{
					v2.push_back(qu.front() * 2);
					qu.pop(); qu.pop();
				}
				else
				{
					v2.push_back(qu.front());
					qu.pop();
				}
			}
			if (j == 0)
			{
				while (!qu.empty())
				{
					v2.push_back(qu.front());
					qu.pop();
				}
			}
		}
		
		for (int j{ N - 1 }; j >= 0; j--)
		{
			if (j >= N - v2.size())
			{
				board[i][j] = v2[N - j - 1];
			}
			else board[i][j] = 0;
		}
	}
	f(cnt + 1);
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			board[i][j] = tboard[i][j];
		}
	}

	for (int i{ 0 }; i < N; i++)
	{
		vector<int> v1, v2;
		queue<int> qu;
		for (int j{ 0 }; j < N; j++)
		{
			if (board[j][i] != 0) v1.push_back(board[j][i]);
		}

		for (int j{ 0 }; j < v1.size(); j++)
		{
			qu.push(v1[j]);
			if (qu.size() == 2)
			{
				if (qu.front() == qu.back())
				{
					v2.push_back(qu.front() * 2);
					qu.pop(); qu.pop();
				}
				else
				{
					v2.push_back(qu.front());
					qu.pop();
				}
			}
			if (j == v1.size() - 1)
			{
				while (!qu.empty())
				{
					v2.push_back(qu.front());
					qu.pop();
				}
			}
		}
		for (int j{ 0 }; j < N; j++)
		{
			if (j < v2.size()) board[j][i] = v2[j];
			else board[j][i] = 0;
		}
	}
	f(cnt + 1);
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			board[i][j] = tboard[i][j];
		}
	}

	for (int i{ 0 }; i < N; i++)
	{
		vector<int> v1, v2;
		queue<int> qu;
		for (int j{ 0 }; j < N; j++)
		{
			if (board[j][i] != 0) v1.push_back(board[j][i]);
		}

		for (int j = v1.size() - 1; j >= 0; j--)
		{
			qu.push(v1[j]);
			if (qu.size() == 2)
			{
				if (qu.front() == qu.back())
				{
					v2.push_back(qu.front() * 2);
					qu.pop(); qu.pop();
				}
				else
				{
					v2.push_back(qu.front());
					qu.pop();
				}
			}
			if (j == 0)
			{
				while (!qu.empty())
				{
					v2.push_back(qu.front());
					qu.pop();
				}
			}
		}
		for (int j{ N - 1 }; j >= 0; j--)
		{
			if (j >= N - v2.size()) board[j][i] = v2[N - j - 1];
			else board[j][i] = 0;
		}
	}
	f(cnt + 1);
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			board[i][j] = tboard[i][j];
		}
	}
}