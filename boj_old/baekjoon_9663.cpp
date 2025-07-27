#include <iostream>
#include <array>
#include <vector>
#include <cmath>
using namespace std;

void queen(int N, int c, int& count, vector<array<int, 2>> &spot, int start);

int main()
{
	int N, count{ 0 };
	vector<array<int, 2>> spot;

	cin >> N;
	queen(N, N, count, spot, 0);

	cout << count;
}

void queen(int N, int c, int& count, vector<array<int, 2>> &spot, int start)
{
	if (c == 0)
	{
		count++;
		return;
	}

	array<int, 2> s;
	for (int j{ 0 }; j < N; j++)
	{
		if (c == N)
		{
			//퀸이 들어간 좌표를 spot에 넣음
			s[0] = start, s[1] = j;
			spot.push_back(s);
			queen(N, c - 1, count, spot, start + 1);
			spot.pop_back();
		}
		else
		{
			bool pass{ false };
			for (int k{ 0 }; k < spot.size(); k++)
			{
				if (start == spot[k][0] || j == spot[k][1] || (fabs(start - spot[k][0]) == fabs(j - spot[k][1]))) break; //퀸이 올 수 없는 곳 제외

				if (k == spot.size() - 1) pass = true;
			}

			if (pass)
			{
				//퀸이 들어간 좌표를 spot에 넣음
				s[0] = start, s[1] = j;
				spot.push_back(s);
				queen(N, c - 1, count, spot, start + 1);
				spot.pop_back();
			}
		}
	}
}