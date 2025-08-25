#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 2000;
int hp, wp, hm, wm;
int picture[SZ][SZ], master[SZ][SZ];
int pattern = 0;

int P[SZ], M[SZ][SZ];
int LPS[SZ];

struct TrieNode
{
	TrieNode* child[2] = {nullptr, nullptr};
	TrieNode* fail;
	int num = 0;
};
queue<TrieNode*> qu;

int KMP(int idx)
{
	int len = 0, res = 0;
	for(int i=0; i<wm; i++)
	{
		while(len > 0 && M[idx][i] != P[len]) len = LPS[len-1];
		if(M[idx][i] == P[len]) ++len;
		if(len == wp)
		{
			res++;
			len = LPS[len-1];
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> hp >> wp >> hm >> wm;
	for(int i=0; i<hp; i++)
	{
		for(int j=0; j<wp; j++) 
		{
			char c; cin >> c;
			picture[i][j] = (c == 'x' ? 0 : 1);
		}	
	}
	for(int i=0; i<hm; i++)
	{
		for(int j=0; j<wm; j++) 
		{
			char c; cin >> c;
			master[i][j] = (c == 'x' ? 0 : 1);
		}
	}
	
	TrieNode* root = new TrieNode;
	for(int j=0; j<wp; j++)
	{
		TrieNode* curNode = root;
		for(int i=0; i<hp; i++)
		{
			int idx = picture[i][j];
			TrieNode*& childNode = curNode->child[idx];
			if(!childNode) childNode = new TrieNode;
			curNode = childNode;
		}

		if(!curNode->num) curNode->num = ++pattern;
		P[j] = curNode->num;
	}

	root->fail = root;
	qu.push(root);
	while(!qu.empty())
	{
		TrieNode* curNode = qu.front(); qu.pop();
		for(int i=0; i<2; i++)
		{
			if(!curNode->child[i]) continue;
			TrieNode* childNode = curNode->child[i];
			TrieNode* failNode = curNode->fail;

			if(curNode != root)
			{
				while(failNode != root && !failNode->child[i]) failNode = failNode->fail;
				if(failNode->child[i]) failNode = failNode->child[i];
			}

			childNode->fail = failNode;
			if(failNode->num) childNode->num = failNode->num;

			qu.push(childNode);
		}
	}

	for(int j=0; j<wm; j++)
	{
		TrieNode* curNode = root;
		for(int i=0; i<hm; i++)
		{
			int idx = master[i][j];
			while(curNode != root && !curNode->child[idx]) curNode = curNode->fail;
			if(curNode->child[idx]) curNode = curNode->child[idx];
			M[i][j] = curNode->num;
		}
	}

	int len = 0;
	for(int i=1; i<wp; i++)
	{
		while(len > 0 && P[i] != P[len]) len = LPS[len-1];
		if(P[i] == P[len]) LPS[i] = ++len;
	}

	int ans = 0;
	for(int i=0; i<hm; i++) ans += KMP(i);
	cout << ans;
}