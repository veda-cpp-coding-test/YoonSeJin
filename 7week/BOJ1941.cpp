//BOJ 1941 소문난 칠공주
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

string A[5];
bool check[5][5];
int result = 0;
bool combination[25];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

bool bfs(int idx){
    memset(check, 0, sizeof(check));

    queue<pair<int, int>> q;
    int count = 0 ;

    q.push({idx /5, idx % 5});
    check[idx/5][idx%5] = true;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;

        count++;

        if (count == 7) return true;
        
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
            if(!combination[ny * 5 + nx]) continue;
            if(check[ny][nx]) continue;

            q.push({ny, nx});
            check[ny][nx] = true;
        }
    }

    return false;
}

void dfs(int cnt, int depth, int S){
    if (cnt == 7){
        if (S >= 4){
            if(bfs(depth)) result++;
        }
        return;
    }

    for(int i = depth; i<25; i++){
        if(combination[i]) continue;

        combination[i] = true;
        dfs(cnt + 1, i, S +(A[i/5][i%5] == 'S'));
        combination[i] = false;
    }
}

void solution(){
    dfs(0,0,0);

    cout << result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i=0; i<5; i++)
    {
        cin >> A[i];
    }

    solution();

    return 0;
}