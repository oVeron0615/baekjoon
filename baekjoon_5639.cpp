#include <iostream>
using namespace std;

int node[10000];
int graph[1000001][2];

void tree(int, int);
void dfs(int);

int main()
{
	int n, idx{ 0 };
	while (cin >> n) node[idx++] = n;
	tree(1, idx - 1);

	dfs(node[0]);
}

void tree(int s, int e)
{
	int root = node[s - 1];
	bool check{};
	for (int i{ s }; i <= e; i++)
	{
		if (i == s && node[i] < root)
		{
			graph[root][0] = node[i];
			check = true;
		}

		if (node[i] > root)
		{
			graph[root][1] = node[i];
			if (check)
			{
				tree(s + 1, i - 1);
				tree(i + 1, e);
			}
			else tree(i + 1, e);
			return;
		}
	}
	if (check)
	{
		graph[root][0] = node[s];
		tree(s + 1, e);
	}
}

void dfs(int x)
{
	if (graph[x][0] == 0 && graph[x][1] == 0)
	{
		cout << x << "\n";
		return;
	}

	if (graph[x][0] != 0) dfs(graph[x][0]);
	if (graph[x][1] != 0) dfs(graph[x][1]);
	cout << x << "\n";
}