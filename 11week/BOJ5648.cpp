//BOJ 5648 역원소 정렬
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<long long> v;
    cin >> n;
    string s[n];
    for(int i=0; i<n; i++)
    {
        cin >> s[i];
        reverse(s[i].begin(), s[i].end());
        v.push_back(atoll(s[i].c_str()));
    }
    sort(v.begin(), v.end());
    for (int i=0; i<v.size(); i++)
    {
        cout << v[i] << "\n";
    }
}