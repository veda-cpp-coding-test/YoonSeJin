//BOJ 3986 좋은 단어
#include <iostream>
#include <stack>

using namespace std;

int ans;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; 
    cin >> n;
    string s;

    for(int i=0; i<n; i++)
    {
        cin >> s;
        stack<int> st;
        for(int j=0; j<s.size(); j++)
        {
            if(!st.empty() && st.top() == s[j])
                st.pop();
            else
                st.push(s[j]);
        }
            if(st.empty()) ans++;    
    }
        cout << ans << "\n";
}
