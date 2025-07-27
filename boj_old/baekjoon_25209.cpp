#include <iostream>
#include <string>
#include <array>
using namespace std;

int main()
{
	int N, M;
	array<array<char, 30>, 30> board;
	array<array<string, 10>, 10> realboard;
	bool pass{ false };
	int area{ 0 };

	//입력
	cin >> N >> M;
	for (int i{ 0 }; i < N * 3; i++)
	{
		for (int j{ 0 }; j < M * 3; j++)
		{
			cin >> board[i][j];
		}
	}

	//입력받은 board를 문자로 바꿈
	for (int i{ 0 }; i < N * 3; i += 3)
	{
		for (int j{ 0 }; j < M * 3; j += 3)
		{
			if (board[i + 1][j + 1] == '.') realboard[i / 3][j / 3] = "W";
			else if (board[i + 1][j + 1] == '0') realboard[i / 3][j / 3] = "B0";
			else if (board[i + 1][j + 1] == '1') realboard[i / 3][j / 3] = "B1";
			else if (board[i + 1][j + 1] == '2') realboard[i / 3][j / 3] = "B2";
			else if (board[i + 1][j + 1] == '3') realboard[i / 3][j / 3] = "B3";
			else if (board[i + 1][j + 1] == '4') realboard[i / 3][j / 3] = "B4";
			else if (board[i + 1][j + 1] == '#')
			{
				if(board[i + 2][j + 2] == '#' && board[i + 2][j] == '#' 
					&& board[i][j + 2] == '#' && board[i][j] == '#')
					realboard[i / 3][j / 3] = "B";
				else if (board[i + 2][j + 2] == '.') realboard[i / 3][j / 3] = "W1";
				else if (board[i + 2][j] == '.') realboard[i / 3][j / 3] = "W2";
				else if (board[i][j + 2] == '.') realboard[i / 3][j / 3] = "W3";
				else if (board[i][j] == '.') realboard[i / 3][j / 3] = "W4";
			}
		}
	}

	//빡구현
	for (int i{ 0 }; i < N; i++)
	{
		for (int j{ 0 }; j < M; j++)
		{
			if (realboard[i][j] == "W")
			{
				if ((i != 0 && j != 0 && realboard[i - 1][j] == "W" && realboard[i][j - 1] == "W" && realboard[i - 1][j - 1] != "W" && realboard[i - 1][j - 1] != "W1")
					|| (i != 0 && j != M - 1 && realboard[i - 1][j] == "W" && realboard[i][j + 1] == "W" && realboard[i - 1][j + 1] != "W" && realboard[i - 1][j + 1] != "W2")
					|| (i != N - 1 && j != 0 && realboard[i + 1][j] == "W" && realboard[i][j - 1] == "W" && realboard[i + 1][j - 1] != "W" && realboard[i + 1][j - 1] != "W3")
					|| (i != N - 1 && j != M - 1 && realboard[i + 1][j] == "W" && realboard[i][j + 1] == "W" && realboard[i + 1][j + 1] != "W" && realboard[i + 1][j + 1] != "W4")
					|| (j != 0 && realboard[i][j - 1] == "W1" && (i == 0 || realboard[i - 1][j] != "W1"))
					|| (j != M - 1 && realboard[i][j + 1] == "W2" && (i == 0 || realboard[i - 1][j] != "W2"))
					|| (j != 0 && realboard[i][j - 1] == "W3" && (i == N - 1 || realboard[i + 1][j] != "W3"))
					|| (j != M - 1 && realboard[i][j + 1] == "W4" && (i == N - 1 || realboard[i + 1][j] != "W4")))
				{
					cout << "NO";
					pass = true;
					break;
				}
			}
			else if (realboard[i][j] == "B0")
			{
				int count{ 0 };
				if ((i != N - 1) && (realboard[i + 1][j] == "W1" || realboard[i + 1][j] == "W2"
					|| realboard[i + 1][j] == "W3" || realboard[i + 1][j] == "W4")) count++;
				if ((i != 0) && (realboard[i - 1][j] == "W1" || realboard[i - 1][j] == "W2"
					|| realboard[i - 1][j] == "W3" || realboard[i - 1][j] == "W4")) count++;
				if ((j != N - 1) && (realboard[i][j + 1] == "W1" || realboard[i][j + 1] == "W2"
					|| realboard[i][j + 1] == "W3" || realboard[i][j + 1] == "W4")) count++;
				if ((j != 0) && (realboard[i][j - 1] == "W1" || realboard[i][j - 1] == "W2"
					|| realboard[i][j - 1] == "W3" || realboard[i][j - 1] == "W4")) count++;
				if (count != 0)
				{
					cout << "NO";
					pass = true;
					break;
				}
			}
			else if (realboard[i][j] == "B1")
			{
				int count{ 0 };
				if ((i != N - 1) && (realboard[i + 1][j] == "W1" || realboard[i + 1][j] == "W2"
					|| realboard[i + 1][j] == "W3" || realboard[i + 1][j] == "W4")) count++;
				if ((i != 0) && (realboard[i - 1][j] == "W1" || realboard[i - 1][j] == "W2"
					|| realboard[i - 1][j] == "W3" || realboard[i - 1][j] == "W4")) count++;
				if ((j != N - 1) && (realboard[i][j + 1] == "W1" || realboard[i][j + 1] == "W2"
					|| realboard[i][j + 1] == "W3" || realboard[i][j + 1] == "W4")) count++;
				if ((j != 0) && (realboard[i][j - 1] == "W1" || realboard[i][j - 1] == "W2"
					|| realboard[i][j - 1] == "W3" || realboard[i][j - 1] == "W4")) count++;
				if (count != 1)
				{
					cout << "NO";
					pass = true;
					break;
				}
			}
			else if (realboard[i][j] == "B2")
			{
				int count{ 0 };
				if ((i != N - 1) && (realboard[i + 1][j] == "W1" || realboard[i + 1][j] == "W2"
					|| realboard[i + 1][j] == "W3" || realboard[i + 1][j] == "W4")) count++;
				if ((i != 0) && (realboard[i - 1][j] == "W1" || realboard[i - 1][j] == "W2"
					|| realboard[i - 1][j] == "W3" || realboard[i - 1][j] == "W4")) count++;
				if ((j != N - 1) && (realboard[i][j + 1] == "W1" || realboard[i][j + 1] == "W2"
					|| realboard[i][j + 1] == "W3" || realboard[i][j + 1] == "W4")) count++;
				if ((j != 0) && (realboard[i][j - 1] == "W1" || realboard[i][j - 1] == "W2"
					|| realboard[i][j - 1] == "W3" || realboard[i][j - 1] == "W4")) count++;
				if (count != 2) 
				{
					cout << "NO";
					pass = true;
					break;
				}
			}
			else if (realboard[i][j] == "B3")
			{
				int count{ 0 };
				if ((i != N - 1) && (realboard[i + 1][j] == "W1" || realboard[i + 1][j] == "W2"
					|| realboard[i + 1][j] == "W3" || realboard[i + 1][j] == "W4")) count++;
				if ((i != 0) && (realboard[i - 1][j] == "W1" || realboard[i - 1][j] == "W2"
					|| realboard[i - 1][j] == "W3" || realboard[i - 1][j] == "W4")) count++;
				if ((j != N - 1) && (realboard[i][j + 1] == "W1" || realboard[i][j + 1] == "W2"
					|| realboard[i][j + 1] == "W3" || realboard[i][j + 1] == "W4")) count++;
				if ((j != 0) && (realboard[i][j - 1] == "W1" || realboard[i][j - 1] == "W2"
					|| realboard[i][j - 1] == "W3" || realboard[i][j - 1] == "W4")) count++;
				if (count != 3)
				{
					cout << "NO";
					pass = true;
					break;
				}
			}
			else if (realboard[i][j] == "B4")
			{
				int count{ 0 };
				if ((i != N - 1) && (realboard[i + 1][j] == "W1" || realboard[i + 1][j] == "W2"
					|| realboard[i + 1][j] == "W3" || realboard[i + 1][j] == "W4")) count++;
				if ((i != 0) && (realboard[i - 1][j] == "W1" || realboard[i - 1][j] == "W2"
					|| realboard[i - 1][j] == "W3" || realboard[i - 1][j] == "W4")) count++;
				if ((j != N - 1) && (realboard[i][j + 1] == "W1" || realboard[i][j + 1] == "W2"
					|| realboard[i][j + 1] == "W3" || realboard[i][j + 1] == "W4")) count++;
				if ((j != 0) && (realboard[i][j - 1] == "W1" || realboard[i][j - 1] == "W2"
					|| realboard[i][j - 1] == "W3" || realboard[i][j - 1] == "W4")) count++;
				if (count != 4)
				{
					cout << "NO";
					pass = true;
					break;
				}
			}
			else if (realboard[i][j] == "W1")
			{
				if (i != N - 1 && j != M - 1)
				{
					if (!(realboard[i + 1][j] == "W" || realboard[i + 1][j] == "W3")
						|| !(realboard[i][j + 1] == "W" || realboard[i][j + 1] == "W2"))
					{
						cout << "NO";
						pass = true;
						break;
					}
				}

				int p = i, q = j;
				while (realboard[p][q] != "W4")
				{
					if (p + 1 == N || q + 1 == M)
					{
						cout << "NO";
						pass = true;
						break;
					}
					if (!(realboard[p][q] == "W" || realboard[p][q] == "W1"))
					{
						cout << "NO";
						pass = true;
						break;
					}
					p++;
					q++;
					area++;
				}
			}
			else if (realboard[i][j] == "W2")
			{
				if (i != N - 1 && j != 0)
				{
					if (!(realboard[i + 1][j] == "W" || realboard[i + 1][j] == "W4")
					|| !(realboard[i][j - 1] == "W" || realboard[i][j - 1] == "W1"))
					{
						cout << "NO";
						pass = true;
						break;
					}
				}

				int p = i, q = j;
				while (realboard[p][q] != "W3")
				{
					if (p + 1 == N || q == 0)
					{
						cout << "NO";
						pass = true;
						break;
					}
					if (!(realboard[p][q] == "W" || realboard[p][q] == "W2"))
					{
						cout << "NO";
						pass = true;
						break;
					}
					p++;
					q--;
					area--;
				}
			}
			else if (realboard[i][j] == "W3")
			{
				if (i != 0 && j != M - 1)
				{
					if (!(realboard[i - 1][j] == "W" || realboard[i - 1][j] == "W1")
					|| !(realboard[i][j + 1] == "W" || realboard[i][j + 1] == "W4"))
					{
						cout << "NO";
						pass = true;
						break;
					}
				}

				int p = i, q = j;
				while (realboard[p][q] != "W2")
				{
					if (p == 0 || q + 1 == M)
					{
						cout << "NO";
						pass = true;
						break;
					}
					if (!(realboard[p][q] == "W" || realboard[p][q] == "W3"))
					{
						cout << "NO";
						pass = true;
						break;
					}
					p--;
					q++;
					area--;
				}
			}
			else if (realboard[i][j] == "W4")
			{
				if (i != 0 && j != 0)
				{
					if (!(realboard[i - 1][j] == "W" || realboard[i - 1][j] == "W2")
					|| !(realboard[i][j - 1] == "W" || realboard[i][j - 1] == "W3"))
					{
						cout << "NO";
						pass = true;
						break;
					}
				}

				int p = i, q = j;
				while (realboard[p][q] != "W1")
				{
					if (p == 0 || q == 0)
					{
						cout << "NO";
						pass = true;
						break;
					}
					if (!(realboard[p][q] == "W" || realboard[p][q] == "W4"))
					{
						cout << "NO";
						pass = true;
						break;
					}
					p--;
					q--;
					area++;
				}
			}

			if (pass) break;
			if (i == N - 1 && j == M - 1)
			{
				if (area == 0) cout << "YES";
				else cout << "NO";
			}
		}
		if (pass) break;
	}
}