#include <iostream>
#include <array>
#include <cmath>
using namespace std;

array<array<char, 6144>, 3072> star{};

void self(int x, int y, int k, int pm);

int main()
{
	int N, k, mid, pm, z;

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	for (int i{ 0 };; i++)
	{
		//k의 값과 중간값을 구함
		if (N == 3 * pow(2, i))
		{
			k = i;
			mid = (6 * pow(2, k) - 1) / 2;
			pm = 6 * pow(2, k - 2);
			break;
		}
	}

	//삼각형 형태의 별을 배열에 저장
	for (int i{ 0 }; i < N; i++)
	{
		int a = mid - i, b = mid + i;
		for (int j{ a }; j <= b; j++)
		{
			star[i][j] = '*';
		}
	}

	//빈 공간 뚫기
	self(N - 1, mid, k, pm);

	z = 6 * pow(2, k);
	//출력
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < z; j++)
		{
			if (star[i][j] == 0 || star[i][j] == ' ') cout << " ";
			else cout << star[i][j];
		}
		cout << "\n";
	}
}

void self(int x, int y, int k, int pm)
{
	if (k == 0)
	{
		star[x - 1][y] = ' ';
		return;
	}

	//역삼각형 공백 뚫기
	int count{ 0 };
	bool pass{ false };
	for (int i{ x };; i--)
	{
		for (int j{ y - count }; j <= y + count; j++)
		{
			if (star[i][j] == 0 || star[i][j] == ' ')
			{
				pass = true;
				break;
			}
			star[i][j] = ' ';
		}
		if (pass) break;
		count++;
	}

	//왼쪽, 오른쪽, 위쪽으로 재귀
	self(x, y - pm, k - 1, pm / 2);
	self(x, y + pm, k - 1, pm / 2);
	self(x - pm, y, k - 1, pm / 2);
}