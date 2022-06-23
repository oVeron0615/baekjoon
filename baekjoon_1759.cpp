#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

int L, C, consonant{ 0 }, vowel{ 0 };
vector<char> alpha;
string password;

void f(int loc);

int main()
{
	//�Է�, ���ĺ� ����
	char a;
	cin >> L >> C;
	for (int i{ 0 }; i < C; i++)
	{
		cin >> a;
		alpha.push_back(a);
	}
	sort(alpha.begin(), alpha.end());

	f(0);
}

void f(int loc)
{
	//��ȣ ���
	if (password.size() == L && vowel >= 1 && consonant >= 2)
	{
		cout << password << "\n";
		return;
	}
	if (loc == C) return;

	//���� - vowel�� 1 ����, ���� - consonant�� 1 ���� -> ���
	//��Ʈ��ŷ
	for (int i{ loc }; i < C; i++)
	{
		password.push_back(alpha[i]);
		switch (alpha[i])
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u': vowel++; f(i + 1); vowel--; break;
		default: consonant++; f(i + 1); consonant--;
		}
		password.pop_back();
	}
}