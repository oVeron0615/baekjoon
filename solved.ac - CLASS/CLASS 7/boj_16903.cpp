#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct TrieNode
{
	TrieNode* child[2];
	int cnt;

	TrieNode()
	{
		fill(&child[0], &child[0] + 2, nullptr);
		cnt = 0;
	}
};

void insert(TrieNode* curNode, int x, int i)
{
	curNode->cnt++;
	if(i < 0) return;

	int idx = (x >> i) & 1;
	TrieNode*& childNode = curNode->child[idx];
	if(childNode == nullptr) childNode = new TrieNode;
	insert(childNode, x, i-1);
}

void erase(TrieNode* curNode, int x, int i)
{
	curNode->cnt--;
	if(i < 0) return;

	int idx = (x >> i) & 1;
	TrieNode* childNode = curNode->child[idx];
	erase(childNode, x, i-1);
}

int getVal(TrieNode* curNode, int x, int i)
{
	if(i < 0) return 0;

	int idx = 1 - ((x >> i) & 1);
	if(curNode->child[idx] != nullptr && curNode->child[idx]->cnt) return getVal(curNode->child[idx], x, i-1) + idx * (1 << i);
	else return getVal(curNode->child[1-idx], x, i-1) + (1-idx) * (1 << i);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	TrieNode* root = new TrieNode;
	insert(root, 0, 30);

	int M; cin >> M;
	while(M--)
	{
		int o, x; cin >> o >> x;
		TrieNode* curNode = root;

		switch(o)
		{
			case 1: insert(root, x, 30); break;
			case 2: erase(root, x, 30); break;
			default: cout << (x ^ getVal(root, x, 30)) << "\n"; break;
		}
	}
}