#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct TrieNode
{
	map<string, TrieNode*> child;
	bool isEnd = false;
};

const int MAXN = 1001;
int N;

void DFS(TrieNode* curNode, int depth)
{
	if(curNode->isEnd) return;
	for(auto [s, childNode] : curNode->child)
	{
		for(int i=1; i<=depth; i++) cout << "--";
		cout << s << "\n";
		DFS(childNode, depth+1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	TrieNode* root = new TrieNode; 

	cin >> N;
	for(int i=1; i<=N; i++)
	{
		TrieNode* curNode = root;

		int K; cin >> K;
		for(int i=1; i<=K; i++)
		{
			string s; cin >> s;
			if((curNode->child).find(s) == (curNode->child).end())
				(curNode->child).insert({s, new TrieNode});
			curNode = (curNode->child)[s];
		}
		curNode->isEnd = true;
	}

	TrieNode* curNode = root;
	DFS(root, 0);
}