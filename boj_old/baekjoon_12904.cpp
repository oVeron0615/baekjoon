#include <iostream>
#include <string>
using namespace std;

int main()
{
	int TIndex;
	string S, T, temp;
	cin >> S >> T;

	for (TIndex = T.size() - 1; TIndex >= S.size(); TIndex--)
	{
		if (T[TIndex] == 'A') T.pop_back();
		else if (T[TIndex] == 'B')
		{
			T.pop_back();
			for (int len{ 1 }; len <= TIndex; len++)
			{
				temp += T[TIndex - len];
			}
			T = temp;
			temp = "";
		}
		cout << T << endl;
	}
	if (T == S) cout << 1;
	else cout << 0;
}