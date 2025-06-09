//BOJ 10814 나이순 정렬
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}

int main()
{
    int N;
    cin >> N;
    int age;
    string name;
    vector<pair<int, string>> people;

    for(int i=0; i<N; ++i){
        cin >> age >> name;
        people.push_back({age, name});
    }

    stable_sort(people.begin(),people.end(), compare);

    for(int i=0; i<N; i++)
    {
        cout << people[i].first << " " << people[i].second << "\n";
    }

    return 0;
}