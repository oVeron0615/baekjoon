#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int k = 1e9 * 2 + 1;
    vector<int> liq;

    //��� �������� ����
    int N; cin >> N;
    for (int i{ 0 }; i < N; i++)
    {
        int l; cin >> l;
        liq.push_back(l);
        if (abs(k) > abs(l)) k = l; //������ �ּ��� ��� ã�� 
    }
    sort(liq.begin(), liq.end());

    int l = 0, r = liq.size() - 1;

    if (0 < liq[l]) cout << liq[l] << " " << liq[l + 1]; //����� ���� ��Į��
    else if (0 > liq[r]) cout << liq[r - 1] << " " << liq[r]; //����� ���� �꼺
    else
    {
        //������ �ּ��� ����� �������� ������ �� ���� ����
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

        //��������
        int tmp1, tmp2, mn = 1e9 * 2 + 1;
        while (p1 >= 0 && p2 < liq.size())
        {
            //�� ��� ���� ������ �ּڰ����� ������ �� ����� ���� ����
            int sum = liq[p1] + liq[p2];
            if (mn > abs(sum))
            {
                mn = abs(sum);
                tmp1 = p1, tmp2 = p2;
            }
            if (sum > 0) p1--; //�� ����� ���� ����� ��
            else p2++; //�� ����� ���� ������ ��
        }
        cout << liq[tmp1] << " " << liq[tmp2];
    }
}