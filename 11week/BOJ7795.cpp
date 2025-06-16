//BOJ 7795 먹을 것인가 먹힐 것인가
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T ;
    cin >> T;

    vector<int> res;

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        vector<int> A(N), B(M);
        for(int i = 0; i < N; i++)
            cin >> A[i];
        for(int i = 0; i < M; i++)
            cin >> B[i];
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        int p_b = 0, result = 0;
        for (int i = 0; i < N; i++)
        {
            while((p_b < M) && A[i] > B[p_b])
            {
                p_b++;
            }
            result += p_b;
        }
        res.push_back(result);
    }
    for(auto x : res)
        cout << x << "\n";
}