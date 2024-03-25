#include <iostream>
using namespace std;

int n, m;
int robot[50][50];
int visited[50][50];

// 북(0), 동(1), 남(2), 서(3)
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {

	cin >> n >> m;

	int r, c, d;

	cin >> r >> c >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> robot[i][j];
		}
	}

	int cnt = 0;

	while (true) {
		if (robot[r][c] == 0) {
			robot[r][c] = 2;
			cnt++;
		}

		bool cleaned = false;

		for (int i = 0; i < 4; i++) {
			d = (d + 3) % 4;
			int nx = r + dx[d];
			int ny = c + dy[d];

			// 청소하지 않은 칸을 찾으면
			if (robot[nx][ny] == 0) {
				r = nx;
				c = ny;
				cleaned = true;
				break;
			}
		}

		// 4방향 모두 청소할 곳이 없는 경우
		if (!cleaned) {

			//후진
			int back = (d + 2) % 4;
			r += dx[back];
			c += dy[back];

			if (robot[r][c] == 1) {
				break;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}