#include <iostream>
#include <set>
using namespace std;

int gift[200001][2];
set<int> take[200001];
bool student[200001];
int ans;

void f(int);

int main()
{
	int N; cin >> N;
	for (int i{ 1 }; i <= N; i++)
	{
		cin >> gift[i][0] >> gift[i][1];
		take[gift[i][0]].insert(i); take[gift[i][1]].insert(i);
	}
	ans = N;

	for (int i{ 1 }; i <= N; i++)
	{
		if (take[i].size() < 2) f(i);
	}

	cout << ans << "\n";
	for (int i{ 1 }; i <= N; i++)
	{
		if (!student[i]) cout << i << " ";
	}
}

void f(int n)
{
	if (!student[n])
	{
		ans--;
		student[n] = true;
		take[gift[n][0]].erase(n); take[gift[n][1]].erase(n);
		if (take[gift[n][0]].size() < 2) f(gift[n][0]);
		if (take[gift[n][1]].size() < 2) f(gift[n][1]);

		if (take[n].size() == 1) f(*take[n].begin());
	}
}