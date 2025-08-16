#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct TrieNode
{
	TrieNode* child[26];
	bool isEnd;

	TrieNode()
	{
		fill(&child[0], &child[0] + 26, nullptr);
		isEnd = false;
	}
};

void deleteNode(TrieNode* curNode)
{
	for(int i=0; i<26; i++)
	{
		TrieNode*& childNode = curNode->child[i];
		if(childNode != nullptr) deleteNode(childNode);
	}
	delete curNode;
}

const int MAXN = 100001;
int N;

void solve()
{
	vector<string> dict;
	for(int i=1; i<=N; i++)
	{
		string s; cin >> s;
		dict.push_back(s);
	}

	TrieNode* root = new TrieNode; //루트 노드

	//Trie에 문자열 입력
	for(string s : dict)
	{
		TrieNode* curNode = root; //현재 노드를 루트 노드로 설정
		for(char c : s) //입력받은 문자열의 문자 순회
		{
			int idx = c - 'a';
			TrieNode*& childNode = curNode->child[idx]; //TrieNode*& : TrieNode 포인터의 참조
			if(childNode == nullptr) childNode = new TrieNode; //문자에 대응하는 자식에 노드가 없다면 만들어준다.
			curNode = childNode; //현재 노드에서 자식 노드로 이동
		}
		curNode->isEnd = true; //문자열의 끝에는 isEnd = true 처리
	}

	int sum = 0;

	//Trie에서 문자열 탐색
	for(string s : dict)
	{
		int cnt = 0;
		TrieNode* curNode = root; //현재 노드를 루트 노드로 설정
		for(char c : s)
		{
			int childCnt = 0;
			for(int j=0; j<26; j++)
				if(curNode->child[j] != nullptr) childCnt++;
			
			//루트 노드이거나, 자식의 수가 2개 이상이거나, 이 노드가 문자열의 끝이라면 무조건 다음 문자를 입력해야 한다.
			if(curNode == root || childCnt > 1 || curNode->isEnd) cnt++;
			curNode = curNode->child[c - 'a']; //현재 노드에서 자식 노드로 이동
		}
		sum += cnt;
	}

	deleteNode(root); //solve()를 호출할 때마다 TrieNode를 동적 할당하므로, 생성한 노드들을 delete해 준다.

	cout << fixed << setprecision(2) << double(sum) / N << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	while(cin >> N) solve();
}