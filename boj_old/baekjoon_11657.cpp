//벨만 - 포드 알고리즘
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
	dist[1] = 0; //시작 정점은 0
	for (int k{ 1 }; k <= N; k++) //N번 완화 시도
	{
		update = false;
		for (int i{ 1 }; i <= N; i++) //연결된 간선 전부에 대해 완화 시도
		{
			for (int j{ 0 }; j < graph[i].size(); j++)
			{
				int x = graph[i][j].first, y = graph[i][j].second;
				if (dist[x] > dist[i] + y)
				{
					dist[x] = dist[i] + y;
					update = true; //완화되었으면 표기
				}
			}
		}

		if (!update) break; //완화가 안 되었으면 바로 나감
	}

	if (update) cout << -1; //N번 완화가 되었다는 것은 음수 사이클이 존재한다는 뜻
	else
	{
		for (int i{ 2 }; i <= N; i++)
		{
			if (dist[i] == 1e9) cout << -1 << "\n";
			else cout << dist[i] << "\n";
		}
	}
}