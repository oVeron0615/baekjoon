#include <iostream>
#include <array>
#include <cstring>
using namespace std;

array<int, 100> memory, Time;
int apploc_time_memory[100][10001];//앱의 위치와 시간에 따른 메모리

void dp(int, int, int, int, int);

int main()
{
	//입력
	int N, M;
	cin >> N >> M;
	for (int i{ 0 }; i < N; i++) cin >> memory[i];
	for (int i{ 0 }; i < N; i++) cin >> Time[i];

	memset(apploc_time_memory, -1, sizeof apploc_time_memory); //배열을 -1로 초기화

	dp(0, 0, 0, N, M);

	bool pass{ false };
	for (int i{ 0 }; i <= 10000; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			if (apploc_time_memory[j][i] >= M)
			{
				cout << i;
				pass = true;
				break;
			}
		}
		if (pass) break;
	}
}

void dp(int i, int j, int lastmemory, int N, int M)
{
	if (i == N) return; //앱의 위치가 N이면 리턴

	int k{ j + Time[i] };
	/*
	해당 앱을 실행할 경우,
	메모리가 -1이거나, 지금까지 더한 메모리의 합이
	이전 메모리와 현재 메모리의 합보다 작으면
	전자를 후자로 대체
	*/
	if (apploc_time_memory[i][k] == -1 ||
		(apploc_time_memory[i][k] != -1 
			&& apploc_time_memory[i][k] < lastmemory + memory[i]))
	{
		apploc_time_memory[i][k] = lastmemory + memory[i];
		if (lastmemory + memory[i] < M) //메모리가 M보다 크거나 같아지면 재귀하지 않음
		{
			dp(i + 1, k, apploc_time_memory[i][k], N, M);
		}
	}
	//앱을 실행하지 않을 경우 앱의 위치만 한 칸 옮김
	dp(i + 1, j, lastmemory, N, M);
}