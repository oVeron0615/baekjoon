#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> crain, box;
	int N, M;

	//입력, 오름차순 정렬
	cin >> N;
	for (int i{ 0 }; i < N; i++)
	{
		int c; cin >> c;
		crain.push_back(c);
	}
	cin >> M;
	for (int i{ 0 }; i < M; i++)
	{
		int b; cin >> b;
		box.push_back(b);
	}
	sort(crain.begin(), crain.end());
	sort(box.begin(), box.end());

	int t{ 1 }, cnt{ 0 };
	vector<bool> check(M, false);
	vector<int> loc;
	int crainIndex{ N - 1 }, boxIndex{ M - 1 };
	while (crainIndex >= 0 && boxIndex >= 0)
	{
		if (crain[crainIndex] >= box[boxIndex])
		{
			check[boxIndex] = true;
			loc.push_back(boxIndex);
			cnt++;
			crainIndex--;
			boxIndex--;
		}
		else boxIndex--;
	}

	if (check[M - 1] == false) cout << -1;
	else
	{
		while (cnt < M)
		{
			for (int i{ 0 }; i < loc.size(); i++)
			{
				while (true)
				{
					if (loc[i] < 0) break;

					if (check[loc[i]]) loc[i]--;
					else
					{
						check[loc[i]] = true;
						cnt++;
						break;
					}
				}
			}
			t++;
		}

		cout << t;
	}
}