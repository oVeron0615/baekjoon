#include <iostream>
#include <array>
using namespace std;

int main()
{
	int N, S;
	array<int, 20> arr;
	cin >> N >> S;

	for (int i{ 0 }; i < N; i++) cin >> arr[i];

	int ans{ 0 };
	for (int i{ 1 }; i < (1 << N); i++)
	{
		int sum{ 0 };
		for (int j{ 0 }; j < N; j++)
		{
			if (i & (1 << j)) sum += arr[j];
		}
		if (sum == S) ans++;
	}

	cout << ans;
}

//비트마스킹 : 비트 연산을 이용한 배열 표기법
//line14 : 1부터 2의 N승 - 1까지 조사(00001 ~ 11111)
//line19 : 1을 j만큼 밀어서 그 자리에 1이 있으면 1을 연산, 아니면 0 연산
/*
i : 0 0 1 1 0
j : 0 0 1 0 0
답: 0 0 1 0 0 - 0아니므로 참
똑같이 1이면 해당 인덱스에 속하는 원소가 존재한다는 뜻
*/