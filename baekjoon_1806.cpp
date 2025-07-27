#include <iostream>
using namespace std;

long long psum[100001];

int main()
{
	int N, S; cin >> N >> S;
	for (int i{ 1 }; i <= N; i++)
	{
		int a; cin >> a;
		psum[i] = a + psum[i - 1];
	}
	
	int p1{ 0 }, p2{ 1 }, len = 1e9;
	while (p2 <= N)
	{
		if (psum[p2] - psum[p1] >= S)
		{
			len = min(len, p2 - p1);
			p1++;
		}
		else p2++;
	}
	if (len == 1e9) cout << 0;
	else cout << len;
}