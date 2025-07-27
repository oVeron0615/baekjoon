#include <iostream>
#include <array>
using namespace std;

array<array<int, 5>, 5> matrix; //원본(입력받은) 행렬
array<array<int, 5>, 5> calMatrix; //계산 행렬

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

	self(N, B); //분할정복

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
	if (B == 1) //계산할 행렬을 입력받은 행렬과 똑같이 만듦
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
	
	if (B % 2 == 0) //짝수
	{
		self(N, B / 2);
		mulMatrix(N);
	}
	else //홀수
	{
		self(N, B / 2);
		mulMatrix(N);
		originMulMatrix(N);
	}
}

void mulMatrix(int N)
{
	array<array<int, 5>, 5> tempMatrix{}; //임시 저장용 행렬

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