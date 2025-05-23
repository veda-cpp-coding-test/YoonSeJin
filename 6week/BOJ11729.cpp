//BOJ11729 하노이 탑 이동 순서
#include <iostream>
#include <math.h>
using namespace std;

void hanoi(int n, int start, int to, int bypass)
{
    if(n == 1)
        printf("%d %d \n", start, to);
    else{
        hanoi(n-1, start, bypass, to);
        printf("%d %d \n", start, to);
        hanoi(n-1, bypass, to, start);
    }
}

int main()
{   
    int num;
    
    cin >> num;
    cout << int(pow(2, num)) - 1 << "\n";
    hanoi(num, 1, 3, 2);

    return 0;
}