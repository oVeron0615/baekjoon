#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9;
vector<int> preorder;

void postorder(int s, int e)
{
	if(s > e) return;

	int idx = e+1;
	for(int i=s+1; i<=e; i++)
	{
		if(preorder[s] < preorder[i])
		{
			idx = i;
			break;
		}
	}

	postorder(s+1, idx-1);
	postorder(idx, e);
	cout << preorder[s] << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int node;
	while(cin >> node) preorder.push_back(node);
	postorder(0, preorder.size()-1);
}