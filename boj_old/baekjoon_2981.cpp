#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, number;
	vector<int> n, sub, divide;

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	for (int i{ 0 }; i < N; i++)
	{
		cin >> number;
		n.push_back(number);
	}
	sort(n.begin(), n.end()); //입력받은 수 정렬

	for (int i{ 0 }; i < N - 1; i++) sub.push_back(n[i + 1] - n[i]);
	sort(sub.begin(), sub.end()); //입력받은 수의 차이 정렬

	for (int i{ 1 }; i * i <= sub[0]; i++)
	{
		if (i * i == sub[0]) divide.push_back(i);
		else if (sub[0] % i == 0)
		{
			if (i != 1) divide.push_back(i);
			divide.push_back(sub[0] / i);
		}
	}
	sort(divide.begin(), divide.end()); //수의 차이 중에서 가장 작은 수의 약수 정렬

	for (int i{ 0 }; i < divide.size(); i++)
	{
		bool pass{ true };
		for (int j{ 0 }; j < N - 1; j++)
		{
			if (sub[j] % divide[i] != 0)
			{
				pass = false;
				break;
			}
		}

		if (pass) cout << divide[i] << " ";
	}
}