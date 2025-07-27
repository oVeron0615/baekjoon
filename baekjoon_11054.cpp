#include <iostream>
#include <cstring>
using namespace std;

int N, A[1000];
int dpmx[1000], dpmn[1000];

void fmx(int);
void fmn(int);

int main()
{
	cin >> N;
	for (int i{ 0 }; i < N; i++) cin >> A[i];
	memset(dpmx, -1, sizeof(dpmx));
	memset(dpmn, -1, sizeof(dpmn));

	for (int i{ 0 }; i < N; i++)
	{
		fmx(i);
		fmn(i);
	}

	int mx{ 0 };
	for (int i{ 0 }; i <= N; i++)
	{
		if (i == 0) mx = max(mx, dpmn[i]);
		else if (i == N) mx = max(mx, dpmx[i]);
		else
		{
			int temp, index{ i + 1 }, m{ -1 };
			for (int j{ i + 1 }; j < N; j++)
			{
				if (m < dpmn[j])
				{
					m = dpmn[j];
					index = j;
				}
			}

			if (A[i] == A[index]) temp = dpmx[i] + m - 1;
			else temp = dpmx[i] + m;
			mx = max(mx, temp);
		}
	}
	cout << mx;
}

void fmx(int x)
{
	if (dpmx[x] != -1) return;
	if (x == 0)
	{
		dpmx[x] = 1;
		return;
	}

	int mx{ 0 };
	for (int i{ x - 1 }; i >= 0; i--)
	{
		if (A[x] > A[i])
		{
			fmx(i);
			mx = max(mx, dpmx[i]);
		}
	}
	dpmx[x] = mx + 1;
}
void fmn(int x)
{
	if (dpmn[x] != -1) return;
	if (x == N - 1)
	{
		dpmn[x] = 1;
		return;
	}

	int mx{ 0 };
	for (int i{ x + 1 }; i < N; i++)
	{
		if (A[x] > A[i])
		{
			fmn(i);
			mx = max(mx, dpmn[i]);
		}
	}
	dpmn[x] = mx + 1;
}