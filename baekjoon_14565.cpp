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

	//확장된 유클리드 알고리즘
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
	if (cal[cal.size() - 1] != 1) cout << -1; //최소공배수가 1이 아님 - 곱역원 x
	else
	{
		if (y[y.size() - 1] < 0) cout << N + y[y.size() - 1]; //y가 음수 - N을 더하면 된다
		else cout << y[y.size() - 1];
	}
}