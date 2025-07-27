#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
vector<pii> td;
int n;
int SaE[1000000][2]; 

int main()
{
	cin >> n;
	for (int i{ 0 }; i < n; i++)
	{
		pii p;
		cin >> p.second >> p.first;
		td.push_back(p);
	}
	sort(td.begin(), td.end(), greater<>());
	//입력을 과제가 끝나는 시간 - 내림차순으로 정렬한다.

	for (int i{ 0 }; i < n; i++)
	{
		SaE[i][0] = td[i].first - td[i].second + 1; //과제를 시작하는 시간
		SaE[i][1] = td[i].first; //과제를 끝내는 시간

		if (i == 0) continue;

		if (SaE[i][1] >= SaE[i - 1][0]) //지금 할 숙제가 다음에 할 숙제와 시간이 겹친다면
		{
			int sub{ SaE[i][1] - SaE[i - 1][0] + 1 };
			SaE[i][0] -= sub;
			SaE[i][1] -= sub;
			//겹치는 날 만큼 숙제할 날을 앞당긴다.
		}
	}
	cout << SaE[n - 1][0] - 1; 
	//맨 처음 숙제를 시작하는 날에서 1을 뺀 숫자가 놀 수 있는 최대이다.
}