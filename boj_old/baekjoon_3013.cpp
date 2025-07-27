#include <iostream>
using namespace std;

int psum[100001], l[100001], r[100001];

int main()
{
	int N, B; cin >> N >> B;
	int loc;
	for (int i{ 1 }; i <= N; i++)
	{
		int Ai; cin >> Ai;
		if (Ai > B) Ai = 1;
		else if (Ai < B) Ai = -1;
		else
		{
			Ai = 0;
			loc = i;
		}

		psum[i] += psum[i - 1] + Ai;
	}

	for (int i{ 0 }; i < loc; i++) l[psum[loc] - psum[i] + 50000]++;
	for (int i{ loc }; i <= N; i++) r[psum[i] - psum[loc] + 50000]++;
	
	int ans{ 0 };
	for (int i{ 0 }; i <= 100000; i++) ans += l[i] * r[100000 - i];
	cout << ans;
}