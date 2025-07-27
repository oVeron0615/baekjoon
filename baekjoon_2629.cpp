#include <iostream>
#include <cmath>
using namespace std;

int N, M;
int weight[30];
bool dp[40001] = {}; //dp[i] = i�� �ش��ϴ� ���Ը� ������ �� �ִ°�?
int ind[40001]; //���԰� �����Ǿ��� �� ������ �ε���

void f(int, int);

int main()
{
	cin >> N;
	for (int i{ 0 }; i < N; i++) cin >> weight[i];

	f(0, 0);

	cin >> M;
	for (int i{ 0 }; i < M; i++)
	{
		int marble;
		cin >> marble;
		if (dp[marble]) cout << "Y" << " ";
		else cout << "N" << " ";
	}
}

void f(int index, int w) //���� �ε���, ����
{
	//���� ����� ������ ������ ���� ���� ������ �� �ִ� ������ �˾Ƴ�
	if (index == N + 1) return;
	f(index + 1, w); //���￡ �ƹ��͵� ���� ����

	if (w != 0)
	{
		if (dp[abs(w)] && ind[abs(w)] <= index - 1) return;
		else
		{
			dp[abs(w)] = true;
			ind[abs(w)] = index - 1;
		}
	}

	//���ʿ� �߸� �߰�, �����ʿ� �߸� �߰�
	f(index + 1, w + weight[index]);
	f(index + 1, w - weight[index]);
}