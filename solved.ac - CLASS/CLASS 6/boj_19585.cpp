#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 2000;

struct TrieNode
{
	map<char, TrieNode*> child;
	bool isEnd = false;
};

void insert(TrieNode* curNode, string& s)
{
	for(int i=0; i<s.size(); i++)
	{
		int idx = s[i] - 'a';
		TrieNode*& childNode = curNode->child[idx];
		if(childNode == nullptr) childNode = new TrieNode;
		curNode = childNode;
	}
	curNode->isEnd = true;
}

TrieNode* search(TrieNode* curNode, int idx)
{
	TrieNode* childNode = curNode->child[idx];
	if(childNode == nullptr) return nullptr;
	return childNode;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int C, N; cin >> C >> N;

	TrieNode* color = new TrieNode;
	for(int i=1; i<=C; i++)
	{
		string s; cin >> s;
		insert(color, s);
	}

	TrieNode* name = new TrieNode;
	for(int i=1; i<=N; i++)
	{
		string s; cin >> s;
		reverse(s.begin(), s.end());
		insert(name, s);
	}

	int Q; cin >> Q;
	while(Q--)
	{
		string s; cin >> s;
		TrieNode* curNode;
		bool endIdx[SZ] = {};
		bool isYes = false;

		curNode = color;
		for(int i=0; i<s.size(); i++)
		{
			curNode = search(curNode, s[i] - 'a');
			if(curNode == nullptr) break;
			if(curNode->isEnd) endIdx[i] = true;
		}

		curNode = name;
		for(int i=s.size()-1; i>=0; i--)
		{
			curNode = search(curNode, s[i] - 'a');
			if(curNode == nullptr) break;
			if(curNode->isEnd)
			{
				if(i > 0 && endIdx[i-1]) isYes = true;
			}
		}

		if(isYes) cout << "Yes\n";
		else cout << "No\n";
	}
}