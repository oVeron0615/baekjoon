#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void printAns(vector<int> v)
{
	sort(v.begin(), v.end());
	if(v.size() == 0) cout << "None\n";
	else
	{
		for(int stu : v) cout << stu << " ";
		cout << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	queue<pii> line;
	vector<int> A, B, C;

	int n; cin >> n;
	while(n--)
	{
		int o; cin >> o;
		if(o == 1)
		{
			int a, b; cin >> a >> b;
			line.push({a, b});
		}
		else
		{
			int b; cin >> b;
			auto [stu, food] = line.front(); line.pop();

			if(food == b) A.push_back(stu);
			else B.push_back(stu);
		}
	}

	while(!line.empty())
	{
		auto [stu, food] = line.front(); line.pop();
		C.push_back(stu);
	}

	printAns(A);
	printAns(B);
	printAns(C);
}