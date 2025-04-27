// BOJ 7562 나이트의 이동
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int a[301][301];
int dx[] = {  1,  2,  2,  1, -1, -2, -1, -2 };
int dy[] = {  2,  1, -1, -2, -2, -1,  2,  1 };


queue <pair<int, int>> q;

int t;
int i;

void bfs(){
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int k = 0; k < 8; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if( 0 <= nx && nx < i && 0 <= ny &&ny < i)
            {
                if(a[nx][ny] == -1)
                {
                    a[nx][ny] = a[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    
    while (t--)
    {
        while(!q.empty()) q.pop();
        memset(a, -1, sizeof(a));
        int x1, y1;
        int x2, y2;

        cin >> i;
        cin >> x1 >> y1;
        cin >> x2 >> y2;

        q.push(make_pair(x1,y1));
        a[x1][y1]=0;
        
        bfs();

        cout << a[x2][y2] << "\n";
    }
    return 0;
}
