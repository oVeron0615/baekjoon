#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
	int N, K, popCount, sIndex{ 0 }, i, sub{ 0 };
	deque<int> dq;
	string s;
	
	cin >> N >> K >> s;
	popCount = K;
	while (true)
	{
		if (popCount == 0 || sIndex == N) break;

		int S = dq.size();
		for (i = sIndex; i <= sIndex + popCount - S; i++) //�� ���� ������ �ִ��� ã�� ���
		{
			if (dq.empty() || s[i] - '0' <= dq.back()) dq.push_back(s[i] - '0');
			else
			{
				while (s[i] - '0' > dq.back())
				{
					dq.pop_back();
					sub++;
					if (dq.empty()) break;
				}
				dq.push_back(s[i] - '0');
			}
		}
		cout << dq.front();
		dq.pop_front();
		sIndex = i;
		popCount -= sub;
		sub = 0;
	}
	for (i = sIndex; i < N; i++) cout << s[i] - '0';
}