#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int ans = 0, temp = 1;
    stack<char> st;
    string s;

    cin >> s;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == '(')
        {
            temp *= 2;
            st.push('(');
        }
        else if (s[i] == '[')
        {
            temp *= 3;
            st.push('[');
        }
        else if (s[i] == ')')
        {
            if (st.empty() || st.top() != '(')
            {
                ans = 0;
                break;
            }
            if (s[i- 1] == '(')
            {
                ans += temp;
            }
            temp /=2;
            st.pop();
        }
        else if (s[i] == ']')
        {
            if(st.empty() || st.top() != '[')
            {
                ans = 0; 
                break;
            }
            if (s[i-1] == '[')
            {
                ans += temp;
            }
            temp /=3;
            st.pop();
        }
    }
    if (!st.empty())
    {
        ans = 0;
    }   
    cout << ans;

    return 0;
}
