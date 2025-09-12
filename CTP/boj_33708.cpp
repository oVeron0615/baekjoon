#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 200'001;
int N;
int A[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for(int i=1; i<=N; i++) cin >> A[i];

	bool isIncrease = true;
	for(int i=2; i<=N; i++)
	{
		if(A[i-1] > A[i]) isIncrease = false;
	}

	if(isIncrease)
	{
		cout << "YES";
		return 0;
	}

	for(int i=1; i<=N; i++)
	{
		if(A[i] == 1) continue;

		for(int j=2; j*j<=A[i]; j++)
		{
			if(A[i] % j == 0)
			{
				cout << "YES";
				return 0;
			}
		}

		if(i > 1 && A[i-1] != 1 || i < N && A[i+1] != 1)
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO";
}