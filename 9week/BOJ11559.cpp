//BOJ 11559 Puyo Puyo
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

string board[12];
int visited[12][6];
vector<pair<int, int>> puyostk;
vector<pair<int, int>> dfsstk;

void drop() {
	for (int j = 0; j < 6; j++) {
		bool firstblank = 1;
		int i = 0;
		for (; i < 12; i++) {
			if (board[i][j] == '.') {
				firstblank = 0;
				break;
			}
		}
		
		if (firstblank) continue;

		int ii = i + 1;
		bool nextexist = 0;
		for (; ii < 12; ii++) {
			if (board[ii][j] != '.') {
				nextexist = 1;
				break;
			}
		}

		if (!nextexist) continue;
		
		for (; ii < 12; ii++) {
			board[i][j] = board[ii][j];
			board[ii][j] = '.';
			i++;
		}
		j--;
	}
}

int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };

void dfs() {
	while (!dfsstk.empty()) {
		auto current = dfsstk.back();
		dfsstk.pop_back();

		int i = current.first;
		int j = current.second;
		puyostk.push_back(current);

		for (int k = 0; k < 4; k++) {
			int ii = i + di[k];
			int jj = j + dj[k];
			if (ii < 0 || ii >= 12 || jj < 0 || jj >= 6) continue;
			if (!visited[ii][jj] && board[ii][jj] == board[i][j]) {
				visited[ii][jj] = 1;
				dfsstk.push_back({ ii,jj });
			}
		}
	}
}

bool chain() {
	bool ret = 0;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (!visited[i][j] && board[i][j] != '.') {
				dfsstk.push_back({ i,j });
				visited[i][j] = 1;
				dfs();
				if (puyostk.size() >= 4) {
					ret = 1;
					for (auto node : puyostk) {
						board[node.first][node.second] = '.';
					}
				}
				puyostk.clear();
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 11; i >= 0; i--) cin >> board[i];

	int ans = 0;
	while (chain()) {
		ans++;
		memset(visited, 0, sizeof(visited));
		drop();
	}

	cout << ans << '\n';
}