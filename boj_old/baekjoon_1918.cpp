#include <iostream>
#include <string>
using namespace std;

string postfix(string);

int main()
{
	string s; cin >> s;
	cout << postfix(s);
}

string postfix(string str)
{
	string alpha[100], arith[100];
	int alidx{ 0 }, aridx{ 0 };
	
	int check{ 0 };
	for (int i{ 0 }; i < str.length(); i++)
	{
		if (check > 0)
		{
			if (str[i] == '(') check++;
			else if (str[i] == ')') check--;
			continue;
		}

		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			arith[aridx] = str[i];
			aridx++;
		}
		else if (str[i] == '(')
		{
			check++;
			string s;
			int bracket{ 0 }, idx{ i };
			while (true)
			{
				if (str[idx] == '(')
				{
					if (bracket != 0) s += str[idx];
					bracket++;
				}
				else if (str[idx] == ')')
				{
					if (bracket != 1) s += str[idx];
					bracket--;
				}
				else s += str[idx];
				
				if (bracket == 0)
				{
					alpha[alidx] = postfix(s);
					alidx++;
					break;
				}
				idx++;
			}
		}
		else
		{
			alpha[alidx] = str[i];
			alidx++;
		}
	}
	
	for (int i{ 0 }; i < aridx; i++)
	{
		if (arith[i] == "*" || arith[i] == "/")
		{
			alpha[i + 1] = alpha[i] + alpha[i + 1] + arith[i];
			alpha[i] = "0";
		}
		else continue;
	}
	
	string s;
	int alx{ 0 }, arx;
	while (alpha[alx] == "0") alx++;

	s += alpha[alx];
	arx = alx; alx++;
	while (true)
	{
		if (alx >= alidx) break;
		while (alpha[alx] == "0") alx++;
		s += alpha[alx]; alx++;

		if (arx >= aridx) break;
		while (arith[arx] == "*" || arith[arx] == "/") arx++;
		s += arith[arx]; arx++;
	}
	return s;
}