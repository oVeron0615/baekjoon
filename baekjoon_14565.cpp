#include <iostream>
#include <vector>
using namespace std;

int main()
{
	long long N, A; cin >> N >> A;

	vector<long long> x, y, cal;
	x.push_back(1), x.push_back(0);
	y.push_back(0), y.push_back(1);
	cal.push_back(N), cal.push_back(A);

	//Ȯ��� ��Ŭ���� �˰���
	int ind{ 0 };
	while (true)
	{
		if (cal[ind] % cal[ind + 1] == 0) break;
		long long p{ cal[ind] / cal[ind + 1] };

		x.push_back(x[ind] - x[ind + 1] * p);
		y.push_back(y[ind] - y[ind + 1] * p);
		cal.push_back(cal[ind] % cal[ind + 1]);
		ind++;
	}
	cout << N - A << " ";
	if (cal[cal.size() - 1] != 1) cout << -1; //�ּҰ������ 1�� �ƴ� - ������ x
	else
	{
		if (y[y.size() - 1] < 0) cout << N + y[y.size() - 1]; //y�� ���� - N�� ���ϸ� �ȴ�
		else cout << y[y.size() - 1];
	}
}