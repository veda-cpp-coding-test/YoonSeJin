//1874 스택 수열
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int cnt = 1;
    int n;
    stack<int> s;
    vector<char> result;

    cin >> n;

    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;

        while (cnt <= x)
        {
            s.push(cnt);
            cnt += 1;
            result.push_back('+');
        }

        if(s.top() == x)
        {
            s.pop();
            result.push_back('-');
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] << "\n";
    }
}