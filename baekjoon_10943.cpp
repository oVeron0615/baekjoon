#include <iostream>
#include <array>
#include <vector>
using namespace std;

array<int, 2001> arr;
array<array<int, 2>, 1000001> questions;
array<array<int, 2>, 2001> pelindrome;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	//입력
	int N, M;
	cin >> N;
	for (int i{ 1 }; i <= N; i++) cin >> arr[i];
	cin >> M;
	for (int i{ 1 }; i <= M; i++)
	{
		cin >> questions[i][0] >> questions[i][1];
	}

	int max, min, count;
	for (int i{ 1 }; i <= N; i++) //중간값에 대한 팰린드롬 홀짝에 따라 저장
	{
		max = i; min = i; count = -1;
		while (min >= 1 && max <= N)
		{
			if (arr[max] == arr[min])
			{
				max++; min--;
				count++;
			}
			else break;
		}
		pelindrome[i][0] = count;

		max = i + 1; min = i; count = -1;
		while (min >= 1 && max <= N)
		{
			if (arr[max] == arr[min])
			{
				max++; min--;
				count++;
			}
			else break;
		}
		pelindrome[i][1] = count;
	}

	for (int i{ 1 }; i <= M; i++)
	{
		int mid{ (questions[i][0] + questions[i][1]) / 2};
		int sub{ questions[i][1] - questions[i][0] };

		if (sub / 2 <= pelindrome[mid][sub % 2]) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
}