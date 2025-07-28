#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;
	vector<int> num(N);
	for(int& n : num) cin >> n;

	double sum = 0;
	for(int n : num) sum += n;
	cout << int(round(sum / N)) << "\n";

	sort(num.begin(), num.end());
	cout << num[N / 2] << "\n";

	map<int, int> val_cnt;
	for(int n : num) val_cnt[n]++;
	int mxCnt = 0;
	vector<int> mxCntVal;
	for(auto [val, cnt] : val_cnt)
	{
		if(mxCnt < cnt)
		{
			mxCnt = cnt;
			mxCntVal.clear();
			mxCntVal.push_back(val);
		}
		else if(mxCnt == cnt) mxCntVal.push_back(val);
	}
	cout << ((mxCntVal.size() == 1) ? mxCntVal[0] : mxCntVal[1]) << "\n";

	cout << num[N - 1] - num[0];
}