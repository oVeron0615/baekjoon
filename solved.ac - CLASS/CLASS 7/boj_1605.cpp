#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXL = 200'000;
int L;
string S;

//RA[i] : S[i]에서 시작하는 접미사의 우선순위
//tmpRA : 임시 RA
//SA[i] : 접미사 배열에서 i번째로 오는 접미사
//결국 RA[SA[i]] = SA[RA[i]] = i이다. SA와 RA는 역관계를 가진다.
int RA[MAXL], tmpRA[MAXL], SA[MAXL];
int LCP[MAXL];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> L >> S;
	if(L == 1)
	{
		cout << 0;
		return 0;
	}

	for(int i=0; i<L; i++)
	{
		RA[i] = S[i]; //초기 우선순위는 아스키 코드 값으로 저장
		SA[i] = i;
	}

	for(int k=1; k<L; k*=2)
	{
		auto cmp = [&](int n1, int n2)
		{
			if(RA[n1] != RA[n2]) return RA[n1] < RA[n2]; //이어붙이지 않았을 때 우선순위 비교
			int rn1 = n1 + k < L ? RA[n1 + k] : -1;
			int rn2 = n2 + k < L ? RA[n2 + k] : -1;
			return rn1 < rn2; //이어붙였을 때 우선순위 비교
		};

		//현재 접미사의 길이의 2배만큼의 접미사를 생성해 우선순위 순으로 정렬
		sort(SA, SA + L, cmp);

		//정렬된 접미사 배열 순서대로 우선순위를 다시 지정
		tmpRA[SA[0]] = 0;
		for(int i=1; i<L; i++)
			tmpRA[SA[i]] = tmpRA[SA[i-1]] + (cmp(SA[i-1], SA[i]) ? 1 : 0); //우선순위가 차이가 난다면 우선순위를 1 더한다.
		
		for(int i=0; i<L; i++) RA[i] = tmpRA[i];
	}

	//LCP 배열 생성
	int len = 0;
	for(int i=0; i<L; i++) //S[0] ~ S[L-1];
	{
		if(RA[i] == 0) //우선순위가 가장 높다면 예외처리
		{
			LCP[RA[i]] = -1; //LCP 배열은 접미사 배열의 index를 따른다.
			continue;
		}

		//S[i]부터 시작하는 접미사, 이보다 우선순위가 하나 낮은 접미사 배열을 비교해 얼마나 겹치는지 계산
		while(S[i + len] == S[SA[RA[i]-1] + len]) len++;
		LCP[RA[i]] = len;

		if(len > 0) len--; //S[i+1]로 시작하는 접미사는 S[i]로 시작하는 배열에서 처음 문자가 잘린 형태이므로, 최소한 len-1개는 겹칠 것이다.
	}

	int ans = 0;
	for(int i=0; i<L; i++) ans = max(ans, LCP[i]);
	cout << ans;
} 