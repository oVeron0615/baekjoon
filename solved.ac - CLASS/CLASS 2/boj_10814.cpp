#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, string> pis;

bool cmp(pis p1, pis p2)
{
	return p1.first < p2.first;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;
	vector<pis> members(N);

	for(int i=0; i<N; i++)
	{
		int age; string name;
		cin >> age >> name;
		members[i] = {age, name};
	}

	stable_sort(members.begin(), members.end(), cmp);
	//안정 정렬 : 기준이 같다면 입력받은 순서를 기준으로 정렬한다.

	for(auto [age, name] : members) cout << age << " " << name << "\n";
}