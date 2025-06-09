//BOJ15688 수 정렬하기 5
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, number;
    vector<int> v;
    cin >> N;
    
    for(int i=0; i<N; i++)
    {
        cin >> number;
        v.push_back(number);
    }

    sort(v.begin(), v.end());

    for(int j=0; j<N; ++j)
    {
        cout << v[j] << "\n";
    }
    
    return 0;
}