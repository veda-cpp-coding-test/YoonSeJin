// BOJ_2577 숫자의 개수
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A,B,C;
    int multi = 1;

    cin >> A >> B >> C;

    int num[10] = {};

    multi = A * B * C;
    
    while(multi>0)          // multi의 각 자릿수를 분해하며 배열에 해당 숫자의 개수를 증가시킴
    {
         num[multi%10]++;           
         multi /= 10;
    }

    for(int i=0; i<10; i++)
    {
        cout << num[i] << "\n";
    }

}