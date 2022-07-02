#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	vector<array<int, 2>> classes;
	array<int, 2> c;

	//�Է�, ȸ�� ���� ������ �������� ����
	cin >> N;
	for (int i{ 0 }; i < N; i++)
	{
		cin >> c[0] >> c[1];
		classes.push_back(c);
	}
	sort(classes.begin(), classes.end());

	int ans{ 0 };
	priority_queue<int, vector<int>, greater<int>> pq;

	pq.push(classes[0][1]); //ù ���� ������ �ð� push
	ans++;
	for (int i{ 1 }; i < N; i++)
	{
		pq.push(classes[i][1]); //���� ������ �ð� push
		ans++;
		if (classes[i][0] >= pq.top()) //���� ���� �ð��� ���� ���� ������ �ð����� ũ�ų� ������
		{
			pq.pop(); //�� �ð��� pop
			ans--;
		}
	}
	cout << ans;
}