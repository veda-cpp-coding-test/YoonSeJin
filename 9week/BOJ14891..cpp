//BOJ 14891 톱니바퀴
#include <iostream>
#include <deque>
using namespace std;

deque<int> gear[4];
int k;

void rotate(int idx, int dir, bool visited[]) {
    visited[idx] = true;

    if (idx > 0 && !visited[idx-1]) {
        if (gear[idx][6] != gear[idx-1][2]) 
            rotate(idx-1, -dir, visited);
    }

    if (idx < 3 && !visited[idx+1]) {
        if (gear[idx][2] != gear[idx+1][6])
            rotate(idx+1, -dir, visited);
    }

    if (dir == 1) { 
        int temp = gear[idx].back();
        gear[idx].pop_back();
        gear[idx].push_front(temp);
    } else { 
        int temp = gear[idx].front();
        gear[idx].pop_front();
        gear[idx].push_back(temp);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 4; i++) {
        string str;
        cin >> str;
        for (char c : str)
            gear[i].push_back(c - '0');
    }

    cin >> k;

    while (k--) {
        int idx, dir;
        cin >> idx >> dir;

        bool visited[4] = { false };
        rotate(idx - 1, dir, visited);
    }

    int score = 0;
    for (int i = 0; i < 4; i++) {
        if (gear[i][0] == 1)
            score += (1 << i);
    }

    cout << score << "\n";
    return 0;
}
