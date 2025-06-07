//BOJ 2448 별 찍기 - 11
#include <iostream>
#include <cstring>

using namespace std;

int N;
char s[3100][6200];

void star(int y, int x, int n){
    if ( n == 3){
        s[y][x] = '*';
        s[y+1][x-1] = '*';
        s[y+1][x+1] = '*';

        for (int i=0; i<5; i++)
        {
            s[y+2][x-2+i] = '*';
        }
    }
    else{
        star(y, x, n/2);
        star(y+n/2, x-n/2, n/2);
        star(y+n/2, x+n/2, n/2);
    }
}

void solution(){
    memset(s, ' ', sizeof(s));

    star(0, N-1, N);

    for(int i=0; i<N; i++)
    {
        for(int j=0; j< 2 * N - 1; j++){
            cout << s[i][j];
        }
        cout <<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    solution();

    return 0;
}
