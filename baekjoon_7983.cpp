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
	//�Է��� ������ ������ �ð� - ������������ �����Ѵ�.

	for (int i{ 0 }; i < n; i++)
	{
		SaE[i][0] = td[i].first - td[i].second + 1; //������ �����ϴ� �ð�
		SaE[i][1] = td[i].first; //������ ������ �ð�

		if (i == 0) continue;

		if (SaE[i][1] >= SaE[i - 1][0]) //���� �� ������ ������ �� ������ �ð��� ��ģ�ٸ�
		{
			int sub{ SaE[i][1] - SaE[i - 1][0] + 1 };
			SaE[i][0] -= sub;
			SaE[i][1] -= sub;
			//��ġ�� �� ��ŭ ������ ���� �մ���.
		}
	}
	cout << SaE[n - 1][0] - 1; 
	//�� ó�� ������ �����ϴ� ������ 1�� �� ���ڰ� �� �� �ִ� �ִ��̴�.
}