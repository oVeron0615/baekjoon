#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 500'001;
int SA[SZ], RA[SZ], tmpRA[SZ];
int LCP[SZ];
string S;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> S;
	if(S.size() == 1)
	{
		cout << 1 << "\n" << "x";
		return 0;
	}

	for(int i=0; i<S.size(); i++)
	{
		RA[i] = S[i];
		SA[i] = i;
	}

	for(int k=1; k<S.size(); k*=2)
	{
		auto cmp = [&](int n1, int n2)
		{
			if(RA[n1] != RA[n2]) return RA[n1] < RA[n2];
			int rn1 = n1 + k < S.size() ? RA[n1 + k] : -1;
			int rn2 = n2 + k < S.size() ? RA[n2 + k] : -1;
			return rn1 < rn2;
		};

		sort(SA, SA + S.size(), cmp);

		tmpRA[SA[0]] = 0;
		for(int i=1; i<S.size(); i++)
			tmpRA[SA[i]] = tmpRA[SA[i-1]] + (cmp(SA[i-1], SA[i]) ? 1 : 0);
		
		for(int i=0; i<S.size(); i++) RA[i] = tmpRA[i];
	}

	int len = 0;
	for(int i=0; i<S.size(); i++)
	{
		if(RA[i] == 0)
		{
			LCP[RA[i]] = -1;
			continue;
		}

		while(S[i + len] == S[SA[RA[i]-1] + len]) len++;
		LCP[RA[i]] = len;

		if(len > 0) len--;
	}

	for(int i=0; i<S.size(); i++) cout << SA[i] + 1 << " ";
	cout << "\n";
	for(int i=0; i<S.size(); i++)
	{
		if(LCP[i] == -1) cout << "x ";
		else cout << LCP[i] << " ";
	}
} 