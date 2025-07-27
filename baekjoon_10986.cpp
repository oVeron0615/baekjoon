#include <iostream>
using namespace std;

long long psum[1000000], mod[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M; cin >> N >> M;

	for (int i{ 1 }; i <= N; i++)
	{
		int Ai; cin >> Ai;
		psum[i] = psum[i - 1] + Ai;
		mod[psum[i] % M]++;
	}

	long long ans{ 0 };
	for (int i{ 0 }; i < M; i++)
	{
		if (i == 0) ans += mod[i] * (mod[i] + 1) / 2;
		else ans += mod[i] * (mod[i] - 1) / 2;
	}
	cout << ans;
}