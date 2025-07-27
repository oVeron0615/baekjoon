#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int T, x1, y1, x2, y2, cx, cy, r, n;

	cin >> T;
	for (int i{ 0 }; i < T; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;

		int count{ 0 };
		for (int j{ 0 }; j < n; j++)
		{
			bool pass{ false };

			cin >> cx >> cy >> r;
			if (fabs(x1 - cx) * fabs(x1 - cx)
				+ fabs(y1 - cy) * fabs(y1 - cy) 
				< r * r) 
				pass = true;
			if (fabs(x2 - cx) * fabs(x2 - cx)
				+ fabs(y2 - cy) * fabs(y2 - cy)
				< r * r)
			{
				if (pass) pass = false;
				else pass = true;
			}

			if (pass) count++;
		}

		cout << count << "\n";
	}
}