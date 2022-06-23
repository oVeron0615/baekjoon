#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
using namespace std;

int N, ans{ 0 };
array<string, 10> word;
array<bool, 26> check{};
vector<char> alpha;
array<int, 26> integer;

void f(int loc, int bit);

int main()
{
	//�Է�, ���ĺ� üũ
	cin >> N;
	for (int i{ 0 }; i < N; i++)
	{
		cin >> word[i];
		for (int j{ 0 }; j < word[i].size(); j++)
		{
			check[word[i][j] - 'A'] = true;
		}
	}

	//�ܾ �ִ� ���ĺ��� alpha�� ����
	for (int i{ 0 }; i < 26; i++)
	{
		if (check[i]) alpha.push_back(i + 'A');
	}

	f(0, 0);
	cout << ans;
}

void f(int loc, int bit)
{
	//�� ����
	if (loc == alpha.size())
	{
		int sum{ 0 };
		for (int i{ 0 }; i < N; i++)
		{
			int multi{ 1 };
			for (int j{ static_cast<int>(word[i].size()) - 1 }; j >= 0; j--)
			{
				sum += integer[word[i][j] - 'A'] * multi;
				multi *= 10;
			}
		}
		ans = max(ans, sum);
		return;
	}

	//��Ʈ����ŷ - ���ĺ��� ���� ����
	for (int i{ 0 }; i < 10; i++)
	{
		if (!(bit & (1 << i)))
		{
			integer[alpha[loc] - 'A'] = i;
			f(loc + 1, bit + (1 << i));
		}
	}
}