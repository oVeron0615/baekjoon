#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;

bool cmp(string s1, string s2)
{
	if(s1.size() == s2.size()) return s1 < s2;
	else return s1.size() < s2.size();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;
	vector<string> words(N);
	for(string& word : words) cin >> word;

	sort(words.begin(), words.end(), cmp);
	for(int i=0; i<N; i++)
	{
		if(i > 0 && words[i] == words[i-1]) continue;
		cout << words[i] << "\n";
	}
}