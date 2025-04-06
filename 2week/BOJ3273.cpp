//3273 두 수의 합
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,a;
    cin >> n;

    vector<int> v;

    for(int i=0; i<n; i++)
    {
        cin >> a;
        v.push_back(a);          
    }
    int x;
    cin >> x;

    sort(v.begin(),v.end());          //vector 오름차순 정렬
   int l = 0, r = n-1, count = 0;

   while(1) {
        if(l>=r)
            break;
        int sum = v[l] + v[r];
        if(sum == x){                // 두수의 합이 x와 같으면 count 1 증가 
            count++;
            l++;                     
            r--;
        }                           // 투포인터를 사용하여 x값 탐색
        else if(sum < x)            // 왼쪽 값 증가 시킴
            l++;
        else                        // 오른쪽 값 감소 시킴
            r--;
   }
   cout << count << "\n";

    return 0;
}