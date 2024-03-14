#include <iostream>
#include <string>
#include <stack>
using namespace std;

int m, n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int map[1001][1001];
bool visited[1001][1001];
bool chk;
stack<pair<int, int>> stk;

void dfs(int x, int y) {
	
	stk.push({ x, y });

	while (!stk.empty()) {
		int xx = stk.top().first;
		int yy = stk.top().second;

		stk.pop();

		for (int i = 0; i < 4; i++) {

			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if (0 <= nx && nx < m && 0 <= ny && ny < n && visited[nx][ny] == 0 && map[nx][ny] == 0) {
				
				if (nx == m - 1) {
					chk = true;
					break;
				}
				stk.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}
	}
}
int main() {

	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < n; j++) {

			if (s[j] == '0')map[i][j] = 0;
			else map[i][j] = 1;

		}
	}

	for (int j = 0; j < n; j++) {
		if (map[0][j] == 0) {
			dfs(0, j);
		}
	}
	if (chk == true) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}