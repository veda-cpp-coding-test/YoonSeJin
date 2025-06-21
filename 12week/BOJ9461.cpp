//BOJ9461 파도반 수열
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    long long T;
    cin >> T;
    vector <long long> v;
    v.assign(100, 0);
    
    v[0] = 1;
    v[1] = 1; 
    v[2] = 1;
    for (long long j = 3; j < 100; j++)
        v[j] = v[j-2] + v[j-3];
    for (long long i = 0; i < T; i++)
    {
        long long N;
        cin >> N;
        cout << v[N-1] << "\n";
    }

}
