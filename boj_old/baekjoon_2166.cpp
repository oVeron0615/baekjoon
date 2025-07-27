#include <iostream>
using namespace std;

int main()
{
	int x1, y1, x2, y2, x3, y3;
	double m1, m2, num, den;

	num = x2 - x1; den = y2 - y1;
	m1 = num / den;

	num = x3 - x2; den = y3 - y2;
	m2 = num / den;

	if (m1 > m2) cout << -1;
	else if (m1 < m2) cout << 1;
	else cout << 0;
}