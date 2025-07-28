#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string a, b, c; cin >> a >> b >> c;
	int val;
	if(a != "Fizz" && a != "Buzz" && a != "FizzBuzz")
		val = stoi(a) + 3;
	if(b != "Fizz" && b != "Buzz" && b != "FizzBuzz")
		val = stoi(b) + 2;
	if(c != "Fizz" && c != "Buzz" && c != "FizzBuzz")
		val = stoi(c) + 1;

	if(val % 3 == 0 && val % 5 == 0) cout << "FizzBuzz";
	else if(val % 3 == 0) cout << "Fizz";
	else if(val % 5 == 0) cout << "Buzz";
	else cout << val;
}