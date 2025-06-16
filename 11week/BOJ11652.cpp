//BOJ 11652 카드
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    
    long long temp;
    vector<long long> v;

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    int max = 0;
    int cnt = 0;
    long long result = v[0];

    for (int i = 1; i < N; i++)
    {
        if (v[i] == v[i-1])
        {
            cnt++;
            if (cnt > max)
            {
                max = cnt;
                result = v[i];
            }
        }
        else
            cnt = 0;
    }
    
    cout << result;
}