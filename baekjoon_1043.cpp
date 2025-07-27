#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N, M, K;
bool vis[51];
vector<int> graph[51];
set<int> party[51];

void dfs(int);

int main()
{
	cin >> N >> M >> K;
	for (int i{ 0 }; i < K; i++)
	{
		int n; cin >> n;
		vis[n] = true;
	}
	for (int i{ 0 }; i < M; i++)
	{
		int a; cin >> a;
		vector<int> person;
		for (int j{ 0 }; j < a; j++)
		{
			int n; cin >> n;
			party[i].insert(n);
			person.push_back(n);
			for (int k{ 0 }; k < j; k++)
			{
				graph[person[j]].push_back(person[k]);
				graph[person[k]].push_back(person[j]);
			}
		}
	}

	for (int i{ 1 }; i <= N; i++)
	{
		if(vis[i]) dfs(i);
	}

	int cnt{ 0 };
	for (int i{ 0 }; i < M; i++)
	{
		bool check{};
		for (int j{ 1 }; j <= N; j++)
		{
			if (vis[j])
			{
				if (party[i].find(j) != party[i].end())
				{
					check = true;
					break;
				}
			}
		}
		if (!check) cnt++;
	}
	cout << cnt;
}

void dfs(int n)
{
	vis[n] = true;
	for (int i{ 0 }; i < graph[n].size(); i++)
	{
		int next = graph[n][i];
		if (!vis[next]) dfs(next);
	}
}