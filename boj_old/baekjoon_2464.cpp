#include <iostream>
#include <array>
using namespace std;

long long pow(int n);

int main()
{
	long long A, temp;
	array<bool, 200> binary{}; //각 배열의 index는 2의 지수를 의미 - 참이면 A가 그 지수를 지님
	int maxloc;

	cin >> A;
	temp = A; //temp에 A를 저장
	while (A != 0) //A를 2의 거듭제곱의 합으로 표현될 때 어떤 2의 지수가 필요한지 확인
	{
		int i;
		for (i = 0; pow(i) <= A; i++);
		if (A == temp) maxloc = i - 1; //최대 지수의 위치
		A -= pow(i - 1);
		binary[i - 1] = true;
	}

	long long big{ 0 }, small{ 0 }; //답 - big : 큰 수, small : 작은 수
	bool check{ false }, passbig{ false }, passsmall{ false };
	int oneCount{ 0 }; //지금까지 나온 1의 개수

	//예시 : 110110(2)
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
		if (i > maxloc) break; //i가 최대 지수보다 커지면 반복문 나감
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