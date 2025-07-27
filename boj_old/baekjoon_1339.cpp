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
	//입력, 알파벳 체크
	cin >> N;
	for (int i{ 0 }; i < N; i++)
	{
		cin >> word[i];
		for (int j{ 0 }; j < word[i].size(); j++)
		{
			check[word[i][j] - 'A'] = true;
		}
	}

	//단어에 있는 알파벳을 alpha에 저장
	for (int i{ 0 }; i < 26; i++)
	{
		if (check[i]) alpha.push_back(i + 'A');
	}

	f(0, 0);
	cout << ans;
}

void f(int loc, int bit)
{
	//합 구함
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

	//비트마스킹 - 알파벳에 숫자 지정
	for (int i{ 0 }; i < 10; i++)
	{
		if (!(bit & (1 << i)))
		{
			integer[alpha[loc] - 'A'] = i;
			f(loc + 1, bit + (1 << i));
		}
	}
}