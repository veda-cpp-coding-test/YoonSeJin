// BOJ1021 회전하는 큐
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int cnt = 0;
    deque<int> q;

    cin >> n >> m;

    for(int i = 0; i< n; i++)
    {
        q.push_back(i+1);
    }

    while(m--)
    {
        int num;
        cin >> num;

        int idx = 0;
        for(int i=0; i<q.size(); i++)
        {
            if(q[i] == num){
                idx = i;
                break;
            }
        }
        if (idx <= q.size()/2){
            for(int i=0; i< idx; i++)
            {
                q.push_back(q.front());
                q.pop_front();
                cnt++;
            }
            q.pop_front();
        }else{
            for(int i = 0; i< q.size() - idx; i++)
            {
                q.push_front(q.back());
                q.pop_back();
                cnt++;
            }
            q.pop_front();
        }
    }
    cout << cnt;
    
}