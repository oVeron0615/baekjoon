#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 1'000'000;
string T, P;
int LPS[SZ];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	getline(cin, T);
	getline(cin, P);

	int len = 0; //처음, 매칭시킨 문자열의 길이는 0이다.
	for(int i=1; i<P.size(); i++) //P에서 P를 찾는다. i=0이면 자기 자신을 찾으므로 i=1부터 시작한다.
	{
		//서로 비교하는 문자가 다르다면, 접미어 부분에 접두어를 매칭시킨다.
		//길이가 0이면 매칭시킨 문자열이 없다는 뜻이므로 while문에서 빠져나가 처음부터 매칭시킨다.
		while(len > 0 && P[i] != P[len]) len = LPS[len - 1];
		if(P[i] == P[len]) LPS[i] = ++len; //비교하는 문자가 같으면 LPS가 이전보다 1 증가한다.
	}

	vector<int> ans;
	len = 0;
	for(int i=0; i<T.size(); i++) //T에서 P 찾기
	{
		while(len > 0 && T[i] != P[len]) len = LPS[len - 1];
		if(T[i] == P[len]) ++len;
		if(len == P.size()) //매칭시킨 문자열의 길이가 P의 길이라면, 문자열 P를 찾은 것이다.
		{
			ans.push_back(i - len + 2); //i - len + 1이 원래 답이지만, 문제에서 index가 1로 시작해 1을 더해주었다.
			len = LPS[len - 1]; //다시 접미어 부분에 접두사를 매칭시킨다.
		}
	}

	cout << ans.size() << "\n";
	for(int a : ans) cout << a << " ";
}