// 5397 키로거
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while(n--) {
        string input;
        cin >> input;

        stack<char> left, right;

        for(char ch : input) {
            if(ch == '<') {
                if(!left.empty()) {
                    right.push(left.top());
                    left.pop();
                }
            }
            else if(ch == '>') {
                if(!right.empty()) {
                    left.push(right.top());
                    right.pop();
                }
            }
            else if(ch == '-') {
                if(!left.empty()) left.pop();
            }
            else {
                left.push(ch);
            }
        }

        while(!right.empty()) {
            left.push(right.top());
            right.pop();
        }

        string result;
        while(!left.empty()) {
            result += left.top();
            left.pop();
        }

        reverse(result.begin(), result.end());
        cout << result << "\n";
    }

    return 0;
}
