#include <iostream>
#include <stack>
#include <array>
using namespace std;

array<int, 1000000> A;

int main()
{
	int N;
	stack<int> st, NGE;
	
	cin >> N;
	for (int i{ 0 }; i < N; i++)
	{
		cin >> A[i];
	}

	for (int i{ N - 1 }; i >= 0; i--)
	{
		while (true)
		{
			if (st.empty())
			{
				NGE.push(-1);
				st.push(A[i]);
				break;
			}
			else if (A[i] >= st.top()) st.pop();
			else
			{
				NGE.push(st.top());
				st.push(A[i]);
				break;
			}
		}
	}

	while (!NGE.empty())
	{
		cout << NGE.top() << " ";
		NGE.pop();
	}
}