#include <iostream>
#include <set>
using namespace std;

int main()
{
	int n, k; cin >> n >> k;
	set<int> s;
	for (int j{ 1 }; j <= k; j++) s.insert(j);
	
	int ans{ 1 };
	for (int i{ 0 }; i < n; i++)
	{
		int a; cin >> a;

		if (s.find(a) != s.end())
		{
			s.erase(a);
			if (s.empty())
			{
				for (int j{ 1 }; j <= k; j++) s.insert(j);
				ans++;
			}
		}
	}
	cout << ans;
}