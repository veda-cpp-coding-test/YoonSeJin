//BOJ11651 좌표 정렬하기 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    if(a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    int N;
    cin >> N;
    int xx, yy;
    vector<pair<int, int>> v;

    for(int i=0; i<N; i++)
    {
        cin >> xx >> yy;
        v.push_back({xx, yy});
    }
    stable_sort(v.begin(), v.end(), compare);

    for(int i=0; i<N; i++)
    {
        cout << v[i].first << " " << v[i].second << "\n";
    }
    return 0;
}