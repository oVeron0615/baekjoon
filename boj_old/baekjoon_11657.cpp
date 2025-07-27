//���� - ���� �˰���
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	typedef pair<int, int> pii;
	vector<pii> graph[501];
	vector<int> dist(501, 1e9);

	int N, M; cin >> N >> M;
	for (int i{ 0 }; i < M; i++)
	{
		int A, B, C; cin >> A >> B >> C;
		graph[A].push_back({ B, C });
	}

	bool update;
	dist[1] = 0; //���� ������ 0
	for (int k{ 1 }; k <= N; k++) //N�� ��ȭ �õ�
	{
		update = false;
		for (int i{ 1 }; i <= N; i++) //����� ���� ���ο� ���� ��ȭ �õ�
		{
			for (int j{ 0 }; j < graph[i].size(); j++)
			{
				int x = graph[i][j].first, y = graph[i][j].second;
				if (dist[x] > dist[i] + y)
				{
					dist[x] = dist[i] + y;
					update = true; //��ȭ�Ǿ����� ǥ��
				}
			}
		}

		if (!update) break; //��ȭ�� �� �Ǿ����� �ٷ� ����
	}

	if (update) cout << -1; //N�� ��ȭ�� �Ǿ��ٴ� ���� ���� ����Ŭ�� �����Ѵٴ� ��
	else
	{
		for (int i{ 2 }; i <= N; i++)
		{
			if (dist[i] == 1e9) cout << -1 << "\n";
			else cout << dist[i] << "\n";
		}
	}
}