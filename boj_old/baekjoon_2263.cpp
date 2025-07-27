#include <iostream>
using namespace std;

int n;
int inorder[100000], postorder[100000], loc[100001];
int graph[100001][2];

int tree(int, int, int);
void dfs(int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n; cin >> n;
	for (int i{ 0 }; i < n; i++)
	{
		cin >> inorder[i];
		loc[inorder[i]] = i;
	}
	for (int i{ 0 }; i < n; i++) cin >> postorder[i];

	int root = tree(0, n - 1, 0);
	dfs(root);
}

int tree(int s, int e, int p)
{
	if (s == e) return postorder[e - p];

	int r = loc[postorder[e - p]];
	
	int root = postorder[e - p];
	if (r != s) graph[root][0] = tree(s, r - 1, p);
	if (r != e) graph[root][1] = tree(r + 1, e, p + 1);
	return root;
}

void dfs(int x)
{
	cout << x << " ";
	if(graph[x][0] != 0) dfs(graph[x][0]);
	if(graph[x][1] != 0) dfs(graph[x][1]);
}