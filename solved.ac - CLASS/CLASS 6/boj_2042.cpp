#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 4'000'001;
int N, M, K;
ll segTree[SZ]; //트리의 크기는 배열의 크기 * 4로 설정

//node : segTree의 index
//s, e : 현재의 구간 [s, e]

void update(int node, int s, int e, int idx, ll val) //idx, val : 입력받은 index와 값
{
	if(idx < s || e < idx) return; //index가 현재 구간에서 벗어나면 return
	if(s == e) //구간의 처음과 끝이 같을 때까지 내려왔다는 것은 목표하는 index에 도달했다는 뜻
	{
		segTree[node] = val; //값 수정
		return;
	}

	update(node*2, s, (s+e)/2, idx, val); //왼쪽 자식
	update(node*2+1, (s+e)/2+1, e, idx, val); //오른쪽 자식
	segTree[node] = segTree[node*2] + segTree[node*2+1]; //선조 노드 수정
}

ll getVal(int node, int s, int e, int l, int r) //l, r : 입력받은 구간
{
	if(r < s || e < l) return 0; //현재 구간이 입력받은 구간에서 아예 벗어나면 0 return
	if(l <= s && e <= r) return segTree[node]; //현재 구간이 입력받은 구간 내에 있다면, 현재 구간의 부분합 return

	//현재 구간이 입력받은 구간이 겹친다면, 현재 구간을 반으로 갈라 지식 노드 탐색
	return getVal(node*2, s, (s+e)/2, l, r) 
			+ getVal(node*2+1, (s+e)/2+1, e, l, r);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M >> K;
	for(int i=1; i<=N; i++) 
	{
		ll Ai; cin >> Ai;
		update(1, 1, N, i, Ai);
	}

	for(int i=1; i<=M+K; i++)
	{
		ll a, b, c; cin >> a >> b >> c;
		if(a == 1) update(1, 1, N, b, c);
		else cout << getVal(1, 1, N, b, c) << "\n";
	}
}