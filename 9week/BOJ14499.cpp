//BOJ14499 주사위 굴리기
#include <iostream>
using namespace std;
int board[20][20];
int dice[6];

int N, M, x, y, k;

int move(int dir){
    if(dir == 1 && y + 1 < M) {
        y++;
        return 1;
    }
    else if(dir == 2 && y - 1 >=0){
        y--;
        return 1;
    }
    else if(dir == 3 && x - 1 >=0){
        x--;
        return 1;
    }
    else if(dir == 4 && x + 1 < N){
        x++;
        return 1;
    }
    return 0;
}

void rotate(int dir){
    int tmp = dice[0];
    if( dir == 1){
        dice[0] = dice[3];
        dice[3] = dice[1];
        dice[1] = dice[2];
        dice[2] = tmp;
    }
    else if(dir == 2){
        dice[0] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[3];
        dice[3] = tmp;
    }
    else if(dir == 3){
        dice[0] = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[4];
        dice[4] = tmp;
    }
    else if(dir == 4){
        dice[0] = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[5];
        dice[5] = tmp;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int dir;

    cin >> N >> M  >> x >> y >> k;

    for(int i = 0; i< N; i++)
        for(int j = 0; j< M; j++)
            cin >> board[i][j];
    
    for(int i=0; i< k; i++)
    {
        cin >> dir;
        if(move(dir)){
            rotate(dir);
            if(board[x][y]){
                dice[0] = board[x][y];
                board[x][y] = 0;
            }
            else{
                board[x][y] = dice[0];
            }
            cout << dice[1] << "\n";
        }
    }
}