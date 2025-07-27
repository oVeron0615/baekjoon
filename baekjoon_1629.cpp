#include <iostream>
using namespace std;

int self(int A, int B, int C);

int main()
{
	int A, B, C;

	cin >> A >> B >> C;

	cout << self(A, B, C);
}

int self(int A, int B, int C)
{
	if (B == 1) return A % C;

	long long answer = self(A, B / 2, C);

	if (B % 2 == 0) return ((answer % C) * (answer % C)) % C;
	else return (((answer % C) * (answer % C)) % C * (A % C)) % C;
}