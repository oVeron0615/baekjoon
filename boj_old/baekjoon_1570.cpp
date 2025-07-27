#include <iostream>
using namespace std;

int main()
{
	int N, SejunX, SejunY, mineX, mineY;
	cin >> N >> SejunX >> SejunY >> mineX >> mineY;

	int x{ mineX - SejunX }, y{ mineY - SejunY };
	if (x < 0 || y < 0) cout << -1;
	else if (x + y <= N)
	{
		for (int i{ 1 }; i <= x; i++) cout << "R";
		for (int i{ 1 }; i <= y; i++) cout << "U";
		for (int i{ 1 }; i <= N - (x + y); i++) cout << "R";
	}
	else
	{
		int M{ x + y };
		int Q{ M / N }, R{ M % N };
		int r1, r2, u1, u2;

		r1 = R;
		while (r1 >= 0)
		{
			if ((x - (Q + 1) * r1) % Q == 0)
			{
				r2 = (x - (Q + 1) * r1) / Q;
				u1 = R - r1;
				u2 = N - R - r2;
				if (r2 < 0 || u1 < 0 || u2 < 0)
				{
					r1--;
					continue;
				}
				break;
			}
			r1--;
		}

		if (r1 < 0) cout << -1;
		else
		{
			for (int i{ 1 }; i <= r1; i++) cout << "R";
			for (int i{ 1 }; i <= u1; i++) cout << "U";
			for (int i{ 1 }; i <= r2; i++) cout << "R";
			for (int i{ 1 }; i <= u2; i++) cout << "U";
		}
	}
}