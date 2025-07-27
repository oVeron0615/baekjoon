#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	stack<pair<int, int>> st;
	stack<int> K;

	int N; cin >> N;
	for (int i{ 1 }; i <= N; i++)
	{
		int n; cin >> n;
		int a{ n }, b{ n }, k{ i };

		while (true)
		{
			if (st.empty())
			{
				st.push({ a, b });
				K.push(k);
				break;
			}

			auto [p, q] = st.top();
			int l = K.top();
			if (a - q == 1) a = p;
			else if (p - b == 1) b = q;
			else
			{
				st.push({ a, b });
				K.push(k);
				break;
			}

			cout << l << "\n";
			st.pop(); K.pop();
		}
	}
}