//1158 요세푸스 문제
#include <iostream>
#include <queue>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int n,k;

    cin >> n >> k;

    queue<int> q;

    for(int i=0; i<n; i++)
    {
        q.push(i+1);
    }

    cout << "<";

    while(!q.empty()){
        for(int i = 1; i<=k; i++)
        {
            int tmp = q.front();
            q.pop();

            if(i != k)
            {
                q.push(tmp);
            }
            else
            {
                cout << tmp;
                if(!q.empty()) 
                    cout << ", ";
            }
        }
    }
    cout << ">";

}