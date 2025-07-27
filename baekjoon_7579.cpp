#include <iostream>
#include <array>
#include <cstring>
using namespace std;

array<int, 100> memory, Time;
int apploc_time_memory[100][10001];//���� ��ġ�� �ð��� ���� �޸�

void dp(int, int, int, int, int);

int main()
{
	//�Է�
	int N, M;
	cin >> N >> M;
	for (int i{ 0 }; i < N; i++) cin >> memory[i];
	for (int i{ 0 }; i < N; i++) cin >> Time[i];

	memset(apploc_time_memory, -1, sizeof apploc_time_memory); //�迭�� -1�� �ʱ�ȭ

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
	if (i == N) return; //���� ��ġ�� N�̸� ����

	int k{ j + Time[i] };
	/*
	�ش� ���� ������ ���,
	�޸𸮰� -1�̰ų�, ���ݱ��� ���� �޸��� ����
	���� �޸𸮿� ���� �޸��� �պ��� ������
	���ڸ� ���ڷ� ��ü
	*/
	if (apploc_time_memory[i][k] == -1 ||
		(apploc_time_memory[i][k] != -1 
			&& apploc_time_memory[i][k] < lastmemory + memory[i]))
	{
		apploc_time_memory[i][k] = lastmemory + memory[i];
		if (lastmemory + memory[i] < M) //�޸𸮰� M���� ũ�ų� �������� ������� ����
		{
			dp(i + 1, k, apploc_time_memory[i][k], N, M);
		}
	}
	//���� �������� ���� ��� ���� ��ġ�� �� ĭ �ű�
	dp(i + 1, j, lastmemory, N, M);
}