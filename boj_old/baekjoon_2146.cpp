#include <iostream>
#include <cmath>
using namespace std;

int N;
int grid[100][100];
int cnt{ 2 };
int dir[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };
int ans{ 1000 };

void island(int x, int y);

int main()
{
	cin >> N;
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			cin >> grid[i][j];
		}
	}

	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			if (grid[i][j] == 1)
			{
				island(i, j); //섬을 분리한다.
				cnt++;
			}
		}
	}

	//좌표 내의 두 점(grid[i][j], grid[p][q])을 비교
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			for (int p{ 0 }; p < N; p++)
			{
				for (int q{ 0 }; q < N; q++)
				{
					//두 점의 좌표가 다르고, 둘 다 0이 아니면 두 점의 길이를 구해 ans와 비교
					if (grid[i][j] != grid[p][q]
						&& grid[i][j] != 0 && grid[p][q] != 0)
					{
						ans = min(ans, abs(i - p) + abs(j - q) - 1);
					}
				}
			}
		}
	}

	cout << ans;
}

//그래프를 이용해 섬을 분리하는 함수
void island(int x, int y)
{
	grid[x][y] = cnt;
	for (int i{ 0 }; i < 4; i++)
	{
		int a{ x + dir[0][i] }, b{ y + dir[1][i] };
		if (grid[a][b] == 1) island(a, b);
	}
}