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
	cinsudoku(); //������ �Է�
	fillsudoku(0); //������ ä���
	coutsudoku(); //������ ���
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
			if (sudoku[i][j] == 0) //0�� ��ǥ spots vector�� ����
			{
				spot[0] = i, spot[1] = j;
				spots.push_back(spot);
			}
		}
	}
}

void fillsudoku(int loc)
{
	for (int value{ 1 }; value <= 9; value++) //0�� ��ǥ�� 1���� 9���� ���� �־
	{
		bool pass{ false };

		for (int i{ 0 }; i < 9; i++) //����
		{
			if (value == sudoku[i][spots[loc][1]])
			{
				pass = true;
				break;
			}
		}
		if (pass) continue;

		for (int j{ 0 }; j < 9; j++) //����
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
		for (int i{ squarei }; i < squarei + 3; i++) //3 * 3 �ڽ�
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

		sudoku[spots[loc][0]][spots[loc][1]] = value; //���� ����ϸ� �ϴ� ���� ä������
		if (loc == spots.size() - 1) //spots�� ���� �����ϸ� �Լ����� ����
		{
			passing = true;
			return;
		}
		fillsudoku(loc + 1); //���� �ƴϸ� ���
		if (passing) return;
		sudoku[spots[loc][0]][spots[loc][1]] = 0; //�ʱ�ȭ
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