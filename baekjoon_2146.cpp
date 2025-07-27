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
				island(i, j); //���� �и��Ѵ�.
				cnt++;
			}
		}
	}

	//��ǥ ���� �� ��(grid[i][j], grid[p][q])�� ��
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			for (int p{ 0 }; p < N; p++)
			{
				for (int q{ 0 }; q < N; q++)
				{
					//�� ���� ��ǥ�� �ٸ���, �� �� 0�� �ƴϸ� �� ���� ���̸� ���� ans�� ��
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

//�׷����� �̿��� ���� �и��ϴ� �Լ�
void island(int x, int y)
{
	grid[x][y] = cnt;
	for (int i{ 0 }; i < 4; i++)
	{
		int a{ x + dir[0][i] }, b{ y + dir[1][i] };
		if (grid[a][b] == 1) island(a, b);
	}
}