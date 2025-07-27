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
    
    int testGrade; cin >> testGrade;
    if(testGrade >= 90) cout << "A";
    else if(testGrade >= 80) cout << "B";
    else if(testGrade >= 70) cout << "C";
    else if(testGrade >= 60) cout << "D";
    else cout << "F";
}