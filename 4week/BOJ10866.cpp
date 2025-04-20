//BOJ10866 덱
#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    deque<int> dq;
    int num;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> s;
        if( s == "push_front")
        {
            cin >> num;
            dq.push_front(num);
        }
        else if( s == "push_back")
        {
            cin >> num;
            dq.push_back(num);
        }
        else if( s == "pop_front")
        {
            if(!dq.empty()){
                cout << dq.front() << "\n";
                dq.pop_front();
            }
            else cout << -1 << "\n";
        }
        else if( s == "pop_back")
        {
            if(!dq.empty())
            {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
            else cout << -1 << "\n";
        }
        else if( s == "size")
        {
            cout << dq.size() << "\n";
        }
        else if( s == "empty")
        {
            if(dq.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if( s == "front")
        {
            if(dq.empty()) cout << -1 << "\n";
            else cout << dq.front() << "\n";
        }
        else if( s == "back")
        {
            if(dq.empty()) cout << -1 << "\n";
            else cout << dq.back() << "\n";

        }
    }
}