#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 26;
pair<char, char> graph[SZ];

void preorder(int u)
{
	cout << char(u + 'A');
	auto [l, r] = graph[u];
	if(l != '.') preorder(l - 'A');
	if(r != '.') preorder(r - 'A');
}

void inorder(int u)
{
	auto [l, r] = graph[u];
	if(l != '.') inorder(l - 'A');
	cout << char(u + 'A');
	if(r != '.') inorder(r - 'A');
}

void postorder(int u)
{
	auto [l, r] = graph[u];
	if(l != '.') postorder(l - 'A');
	if(r != '.') postorder(r - 'A');
	cout << char(u + 'A');
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;
	for(int i=0; i<N; i++)
	{
		char u, l, r; cin >> u >> l >> r;
		graph[u-'A'] = {l, r};
	}

	preorder(0); cout << "\n";
	inorder(0); cout << "\n";
	postorder(0);
}