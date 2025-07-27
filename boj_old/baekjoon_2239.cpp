#include <iostream>
#include <array>
#include <vector>
using namespace std;

array<array<int, 9>, 9> sudoku;
vector<array<int, 2>> spots;
array<int, 2> spot;
bool passing{ false };

void cinsudoku();
void fillsudoku(int loc);
void coutsudoku();

int main()
{
	cinsudoku(); //스도쿠 입력
	fillsudoku(0); //스도쿠 채우기
	coutsudoku(); //스도쿠 출력
}

void cinsudoku()
{
	char number;
	for (int i{ 0 }; i < 9; i++)
	{
		for (int j{ 0 }; j < 9; j++)
		{
			cin >> number;
			sudoku[i][j] = number - '0';
			if (sudoku[i][j] == 0) //0인 좌표 spots vector에 저장
			{
				spot[0] = i, spot[1] = j;
				spots.push_back(spot);
			}
		}
	}
}

void fillsudoku(int loc)
{
	for (int value{ 1 }; value <= 9; value++) //0인 좌표에 1부터 9까지 전부 넣어봄
	{
		bool pass{ false };

		for (int i{ 0 }; i < 9; i++) //세로
		{
			if (value == sudoku[i][spots[loc][1]])
			{
				pass = true;
				break;
			}
		}
		if (pass) continue;

		for (int j{ 0 }; j < 9; j++) //가로
		{
			if (value == sudoku[spots[loc][0]][j])
			{
				pass = true;
				break;
			}
		}
		if (pass) continue;

		int squarei = spots[loc][0] - spots[loc][0] % 3;
		int squarej = spots[loc][1] - spots[loc][1] % 3;
		for (int i{ squarei }; i < squarei + 3; i++) //3 * 3 박스
		{
			for (int j{ squarej }; j < squarej + 3; j++)
			{
				if (value == sudoku[i][j])
				{
					pass = true;
					break;
				}
			}
			if (pass) break;
		}
		if (pass) continue;

		sudoku[spots[loc][0]][spots[loc][1]] = value; //전부 통과하면 일단 값을 채워넣음
		if (loc == spots.size() - 1) //spots의 끝에 도달하면 함수에서 나감
		{
			passing = true;
			return;
		}
		fillsudoku(loc + 1); //끝이 아니면 재귀
		if (passing) return;
		sudoku[spots[loc][0]][spots[loc][1]] = 0; //초기화
	}
}

void coutsudoku()
{
	for (int i{ 0 }; i < 9; i++)
	{
		for (int j{ 0 }; j < 9; j++)
		{
			cout << sudoku[i][j];
		}
		cout << "\n";
	}
}