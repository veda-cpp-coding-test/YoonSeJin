//BOJ18258 큐2
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n;
    string s;
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if( s == "push")
        {
            cin >> k;
            q.push(k);        
        }
        else if ( s == "pop")
        {
            if(q.empty())
                cout << -1 << "\n";
            else
            {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if ( s == "size")
        {
            cout << q.size() << "\n";
        }
        else if ( s == "empty")
        {
            if(q.empty())
                cout << 1 << "\n";
            else 
                cout << 0 << "\n";
        }
        else if ( s == "front")
        {
            if(q.empty())
                cout << -1 << "\n";
            else
                cout << q.front() << "\n";
        }
        else if ( s == "back")
        {
            if(q.empty())
                cout << -1 << "\n";
            else
                cout << q.back() << "\n";
        }
    }
}