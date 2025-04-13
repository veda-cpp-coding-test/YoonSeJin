//10773 제로
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k;
    stack<int> A;

    cin >> k;
    for(int i=0; i<k; i++)
    {
        int num;
        cin >> num;
        
        if(num == 0 && !A.empty())
        {
            A.pop();
        }
        else
        {
            A.push(num);
        }
    }

    int sum = 0;
    while(!A.empty())
    {
        
        sum += A.top();
        A.pop();
    }

        cout << sum << "\n";

    return 0;
}