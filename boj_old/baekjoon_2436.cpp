#include <iostream>
using namespace std;

int main()
{
	long long G, L, ab, tmp1, tmp2, t1, t2;
	cin >> G >> L;

	ab = L / G;
	for (int i{ 1 }; i * i <= ab; i++)
	{
		if (ab % i == 0)
		{
			tmp1 = i;
			tmp2 = ab / i;

			int cnt{ 0 };
			for (int j{ 1 }; j <= tmp1; j++)
			{
				if (tmp1 % j == 0 && tmp2 % j == 0) cnt++;
			}
			if (cnt == 1)
			{
				t1 = tmp1;
				t2 = tmp2;
			}
		}
	}
	cout << t1 * G << " " << t2 * G;
}