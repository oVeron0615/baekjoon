#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int k = 1e9 * 2 + 1;
    vector<int> liq;

    //용액 오름차순 정렬
    int N; cin >> N;
    for (int i{ 0 }; i < N; i++)
    {
        int l; cin >> l;
        liq.push_back(l);
        if (abs(k) > abs(l)) k = l; //절댓값이 최소인 용액 찾기 
    }
    sort(liq.begin(), liq.end());

    int l = 0, r = liq.size() - 1;

    if (0 < liq[l]) cout << liq[l] << " " << liq[l + 1]; //용액이 전부 알칼리
    else if (0 > liq[r]) cout << liq[r - 1] << " " << liq[r]; //용액이 전부 산성
    else
    {
        //절댓값이 최소인 용액을 기점으로 포인터 두 개를 결정
        int loc{ 0 }, p1, p2;
        while (k != liq[loc]) loc++;
        if (loc != 0 && (loc == liq.size() - 1 || abs(liq[loc - 1] + liq[loc]) < abs(liq[loc + 1] + liq[loc])))
        {
            p1 = loc - 1; p2 = loc;
        }
        else
        {
            p1 = loc; p2 = loc + 1;
        }

        //투포인터
        int tmp1, tmp2, mn = 1e9 * 2 + 1;
        while (p1 >= 0 && p2 < liq.size())
        {
            //두 용액 합의 절댓값이 최솟값보다 작으면 두 용액을 따로 저장
            int sum = liq[p1] + liq[p2];
            if (mn > abs(sum))
            {
                mn = abs(sum);
                tmp1 = p1, tmp2 = p2;
            }
            if (sum > 0) p1--; //두 용액의 합이 양수일 때
            else p2++; //두 용액의 합이 음수일 때
        }
        cout << liq[tmp1] << " " << liq[tmp2];
    }
}