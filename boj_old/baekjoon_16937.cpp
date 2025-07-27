#include <iostream>
using namespace std;

int main()
{
	int H, W, N; cin >> H >> W >> N;
	int sticker[101][2];

	for (int i{ 1 }; i <= N; i++)
	{
		cin >> sticker[i][0] >> sticker[i][1];
	}

	int mx{ 0 };
	for (int i{ 1 }; i <= N - 1; i++)
	{
		for (int j{ i + 1 }; j <= N; j++)
		{
			int r1{ sticker[i][0] }, c1{ sticker[i][1] };
			int r2{ sticker[j][0] }, c2{ sticker[j][1] };

			bool case1 = (r1 + r2 <= H && c1 <= W && c2 <= W);
			bool case2 = (r1 + r2 <= W && c1 <= H && c2 <= H);
			bool case3 = (c1 + c2 <= H && r1 <= W && r2 <= W);
			bool case4 = (c1 + c2 <= W && r1 <= H && r2 <= H);
			bool case5 = (r1 + c2 <= H && r2 <= W && c1 <= W);
			bool case6 = (r1 + c2 <= W && r2 <= H && c1 <= H);
			bool case7 = (r2 + c1 <= H && r1 <= W && c2 <= W);
			bool case8 = (r2 + c1 <= W && r1 <= H && c2 <= H);

			if (case1 || case2 || case3 || case4
				|| case5 || case6 || case7 || case8)
			{
				mx = max(mx, (r1 * c1 + r2 * c2));
			}
		}
	}

	cout << mx;
}