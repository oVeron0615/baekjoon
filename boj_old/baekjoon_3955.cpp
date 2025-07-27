#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t; cin >> t;
	for (int i{ 0 }; i < t; i++)
	{
		long long K, C; cin >> K >> C;

		bool check;
		vector<long long> x, y, cal;
		x.push_back(1), x.push_back(0);
		y.push_back(0), y.push_back(1);

		if (K > C)
		{
			check = true;
			cal.push_back(K), cal.push_back(C);
		}
		else
		{
			check = false;
			cal.push_back(C), cal.push_back(K);
		}
		if (K == 1 && C == 1)
		{
			cout << 2 << "\n";
			continue;
		}

		int ind{ 0 };
		while (true)
		{
			if (cal[ind] % cal[ind + 1] == 0) break;
			long long p{ cal[ind] / cal[ind + 1] };

			x.push_back(x[ind] - x[ind + 1] * p);
			y.push_back(y[ind] - y[ind + 1] * p);
			cal.push_back(cal[ind] % cal[ind + 1]);
			ind++;
		}

		if (cal[cal.size() - 1] != 1) cout << "IMPOSSIBLE" << "\n";
		else
		{
			int ans;
			if (check)
			{
				if (x[x.size() - 1] < 0) ans = y[y.size() - 1];
				else ans = K + y[y.size() - 1];
			}
			else
			{
				if (y[y.size() - 1] < 0) ans = x[x.size() - 1];
				else ans = K + x[x.size() - 1];
			}

			if (ans <= 1e9) cout << ans << "\n";
			else cout << "IMPOSSIBLE" << "\n";
		}
	}
}