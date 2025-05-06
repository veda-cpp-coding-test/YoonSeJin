//BOJ24479 알고리즘 수업 - 깊이 우선 탐색1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> list;
vector <int> visit;
int order = 1;

void dfs(int start)
{
    visit[start] = order;

    for(int i=0; i<list[start].size(); i++)
    {
        int next = list[start].at(i);
        
        if(!visit[next])
        {
            order++;
            dfs(next);
        }
    }
}

int main()
{
    int n, m, r = 0;

    cin >> n >> m >> r;

    list = vector<vector<int>>(n+1);
    visit = vector<int>(n+1, 0);

    for(int i=0; i<m; i++)
    {
        int u, v;
        
        cin >> u >> v;

        list[u].push_back(v);
        list[v].push_back(u);
    }

    for(int i=0; i<n; i++)
        sort(list[i].begin(), list[i].end());

        dfs(r);
    for(int i=1; i<n+1; i++)
    {
        cout << visit[i] <<"\n";
    }
    return 0;
}