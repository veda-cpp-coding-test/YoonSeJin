//BOJ 10799 쇠막대기
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str;
    stack<int> s;
    int cnt = 0;
    cin >> str;

    for(int i=0; i<str.size(); i++)
    {
        if (str[i] == '(' && str[i+1] == ')')
		{
			cnt += s.size();
			i++;
		}
		else if (str[i] == '(')
		{
			s.push(i);
		}
		else if (str[i] == ')')
		{
			cnt++;
			s.pop();
		}
    }
    cout << cnt << "\n";

    return 0;
}

