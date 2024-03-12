#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

bool visited[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int m, n, k;
vector<int> ans_v;
int ans = 0;

void bfs(int x, int y) {

	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = true;

	int cnt = 1;

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (!visited[ny][nx]) {
					q.push(make_pair(ny, nx));
					visited[ny][nx] = true;
					cnt++;
				}
			}
		}
	}

	ans_v.push_back(cnt);
}
int main() {

	cin >> m >> n >> k;

	while (k--) {
		
		int x1, y1, x2, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		for (int y = m - y2; y < m - y1; y++) {
			for (int x = x1; x < x2; x++) {
				visited[y][x] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
				ans++;
			}
		}
		
	}
	
	cout << ans << endl;

	sort(ans_v.begin(), ans_v.end());
	for (int i = 0; i < ans_v.size(); i++) {
		cout << ans_v[i] << " ";
	}
	
	return 0;
}