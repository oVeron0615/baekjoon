#include <iostream>
#include <queue>
#include <array>
using namespace std;

array<array<int, 1500>, 1500> board;

int main()
{
	int N, tempi, tempj;
	priority_queue<array<int, 3>> pq;
	array<int, 3> column;

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			cin >> board[i][j];
			if (i == N - 1)
			{
				column[0] = board[i][j];
				column[1] = i, column[2] = j;
				pq.push(column);
			}
		}
	}

	for (int i{ 0 }; i < N - 1; i++)
	{
		tempi = pq.top()[1], tempj = pq.top()[2];
		pq.pop();
		column[0] = board[tempi - 1][tempj];
		column[1] = tempi - 1, column[2] = tempj;
		pq.push(column);
	}

	cout << pq.top()[0];
}