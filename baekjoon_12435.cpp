#include <iostream>
#include <vector>
using namespace std;

vector<int> d[1000001];
vector<int> Div[1000001];

int main()
{
	for (int i{ 2 }; i <= 1000000; i++)
	{
		int sum{ i * 2 };
		while (sum <= 1000000)
		{
			Div[sum].push_back(i);
			sum += i;
		}
	}
	for (int i{ 2 }; i <= 1000000; i++)
	{
		d[Div[i].size()].push_back(i);
	}

	int T; cin >> T;
	for (int t{ 1 }; t <= T; t++)
	{
		int N, M; cin >> N >> M;
		int ans{ 0 };
		if (Div[N].size() != 0)
		{
			for (int i{ 0 }; i < d[Div[N].size()].size(); i++)
			{
				if (Div[d[Div[N].size()][i]][0] >= M && d[Div[N].size()][i] < N) ans++;
			}
		}

		cout << "Case #" << t << ": " << ans << "\n";
	}
}