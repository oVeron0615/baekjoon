#include <iostream>
#include <array>
using namespace std;

array<array<int, 5>, 5> matrix; //����(�Է¹���) ���
array<array<int, 5>, 5> calMatrix; //��� ���

void self(int N, long long B);
void mulMatrix(int N);
void originMulMatrix(int N);

int main()
{
	int N;
	long long B;

	cin >> N >> B;
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			cin >> matrix[i][j];
		}
	}

	self(N, B); //��������

	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			cout << calMatrix[i][j] << " ";
		}
		cout << "\n";
	}
}

void self(int N, long long B)
{
	if (B == 1) //����� ����� �Է¹��� ��İ� �Ȱ��� ����
	{
		for (int i{ 0 }; i < N; i++)
		{
			for (int j{ 0 }; j < N; j++)
			{
				calMatrix[i][j] = matrix[i][j];
			}
		}
		return;
	}
	
	if (B % 2 == 0) //¦��
	{
		self(N, B / 2);
		mulMatrix(N);
	}
	else //Ȧ��
	{
		self(N, B / 2);
		mulMatrix(N);
		originMulMatrix(N);
	}
}

void mulMatrix(int N)
{
	array<array<int, 5>, 5> tempMatrix{}; //�ӽ� ����� ���

	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			for (int k{ 0 }; k < N; k++)
			{
				tempMatrix[i][j] += calMatrix[i][k] * calMatrix[k][j] % 1000;
			}
		}
	}

	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			calMatrix[i][j] = tempMatrix[i][j] % 1000;
		}
	}
}

void originMulMatrix(int N)
{
	array<array<int, 5>, 5> tempMatrix{};

	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			for (int k{ 0 }; k < N; k++)
			{
				tempMatrix[i][j] += calMatrix[i][k] * matrix[k][j] % 1000;
			}
		}
	}

	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < N; j++)
		{
			calMatrix[i][j] = tempMatrix[i][j] % 1000;
		}
	}
}