#include <iostream>
#include <cmath>
using namespace std;

int N, M;
int weight[30];
bool dp[40001] = {}; //dp[i] = i에 해당하는 무게를 측정할 수 있는가?
int ind[40001]; //무게가 측정되었을 때 측정된 인덱스

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

void f(int index, int w) //추의 인덱스, 무게
{
	//왼쪽 저울과 오른쪽 저울의 차를 통해 측정할 수 있는 구슬을 알아냄
	if (index == N + 1) return;
	f(index + 1, w); //저울에 아무것도 하지 않음

	if (w != 0)
	{
		if (dp[abs(w)] && ind[abs(w)] <= index - 1) return;
		else
		{
			dp[abs(w)] = true;
			ind[abs(w)] = index - 1;
		}
	}

	//왼쪽에 추를 추가, 오른쪽에 추를 추가
	f(index + 1, w + weight[index]);
	f(index + 1, w - weight[index]);
}