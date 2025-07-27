#include <iostream>
#include <array>
using namespace std;

long long pow(int n);

int main()
{
	long long A, temp;
	array<bool, 200> binary{}; //�� �迭�� index�� 2�� ������ �ǹ� - ���̸� A�� �� ������ ����
	int maxloc;

	cin >> A;
	temp = A; //temp�� A�� ����
	while (A != 0) //A�� 2�� �ŵ������� ������ ǥ���� �� � 2�� ������ �ʿ����� Ȯ��
	{
		int i;
		for (i = 0; pow(i) <= A; i++);
		if (A == temp) maxloc = i - 1; //�ִ� ������ ��ġ
		A -= pow(i - 1);
		binary[i - 1] = true;
	}

	long long big{ 0 }, small{ 0 }; //�� - big : ū ��, small : ���� ��
	bool check{ false }, passbig{ false }, passsmall{ false };
	int oneCount{ 0 }; //���ݱ��� ���� 1�� ����

	//���� : 110110(2)
	for (int i{ 0 };; i++)
	{
		if (binary[i]) oneCount++;
		if (!passbig && i != 0 && !binary[i] && binary[i - 1])
		{
			big = temp;
			for (int j{ 0 }; j < i; j++)
			{
				if (binary[j]) big -= pow(j); //110000(2)
			}
			for (int j{ 0 }; j <= oneCount - 2; j++) big += pow(j); //110001(2)
			big += pow(i); //111001(2)
			passbig = true;
		}
		if (i > maxloc) break; //i�� �ִ� �������� Ŀ���� �ݺ��� ����
		if (!passsmall && i != 0 && binary[i] && !binary[i - 1])
		{
			small = temp;
			for (int j{ 0 }; j <= i; j++)
			{
				if (binary[j]) small -= pow(j); //110110(2)
			}
			for (int j{ i - 1 }; j >= i - oneCount; j--) small += pow(j); //110101(2)
			passsmall = true;
		}
	}
	cout << small << " " << big;
}

long long pow(int n)
{
	long long answer{ 1 };
	for (int i{ 1 }; i <= n; i++) answer *= 2;
	return answer;
}