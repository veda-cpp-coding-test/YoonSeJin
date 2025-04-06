// BOJ_1475 방번호
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int A[10] = {};
    cin >> N;

    int count = 0;
    int index = 0;

    while(N>0)
    {
        int index = N % 10;

        if(index == 6 || index == 9)    // 6과 9는 하나로 통일하여 6에 값 저장
        {
            A[6]++;
        }
        else
        {
            A[index]++;
        }
        N/=10;
    }
    A[6] = (A[6]+1) /2;     //6과 9를 함께 취급하며 총 개수를 2로 나누며 올림 처리           

    int max = 0; 
    for(int i=0; i<9; i++)
    {
        if(A[i] > max)
        {
            max = A[i];
        }
    }
    cout << max << "\n";

    return 0;
}