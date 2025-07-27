#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> liq;

	int N; cin >> N;
	for (int i{ 0 }; i < N; i++)
	{
		int l; cin >> l;
		liq.push_back(l);
	}
	sort(liq.begin(), liq.end());

	long long MN = 1e9 * 3 + 1, t1, t2, t3;
	for (int i{ 0 }; i < N; i++)
	{
		//liq[i]�� �����ϰ� ���� push
		vector<int> liqTemp;
		for (int j{ 0 }; j < N; j++)
		{
			if (i != j) liqTemp.push_back(liq[j]);
		}

		//liq[i]�� ���� ������Ű�� ������ �� ���� �����ͷ� ��� 0�� ���� ����� ����� ����
		int p1 = 0, p2 = liqTemp.size() - 1, mn = 1e9 * 2 + 1;
		long long tmp1, tmp2;
		while (p1 < p2)
		{
			int sum = liqTemp[p2] + liqTemp[p1] + liq[i];
			if (mn > abs(sum))
			{
				mn = abs(sum);
				tmp1 = liqTemp[p1], tmp2 = liqTemp[p2];
			}

			if (sum < 0) p1++;
			else p2--;
		}

		if (MN > mn)
		{
			MN = mn;
			if (liq[i] < tmp1) t1 = liq[i], t2 = tmp1, t3 = tmp2;
			else if (liq[i] > tmp2) t1 = tmp1, t2 = tmp2, t3 = liq[i];
			else t1 = tmp1, t2 = liq[i], t3 = tmp2;
		}
	}
	cout << t1 << " " << t2 << " " << t3;
}