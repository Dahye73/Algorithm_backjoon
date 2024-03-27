#include<iostream>
using namespace std;

// 이동 순서
// left -> down -> right -> up
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };

int windy[4][9] = {
	{-1, 1, -2, 2, 0, -1, 1, -1, 1},  //left
	{-1, -1, 0, 0, 2, 0, 0, 1, 1},    //down
	{1, -1, 2, -2, 0, 1, -1, 1, -1},  //right
	{1, 1, 0, 0, -2, 0, 0, -1, -1},    //up
};
int windx[4][9] = {
	{1, 1, 0, 0, -2, 0, 0, -1, -1},   //left
	{-1, 1, -2, 2, 0, -1, 1, -1, 1},  //down
	{-1, -1, 0, 0, 2, 0, 0, 1, 1},    //right
	{1, -1, 2, -2, 0, 1, -1, 1, -1},  //up
};

// 각 칸의 모래의 양 퍼센트
int rate[9] = { 1, 1, 2, 2, 5, 7, 7, 10, 10 };
int n;
int a[499][499];

// 맵 밖으로 나가게 되는 모래의 양을 계산
int wind(int cy, int cx, int dir) {

	int ret = 0;
	int sand = a[cy][cx];

	// 원래의 모래양에서 이동하게 되는 모래의 양
	int sum = 0;

	for (int i = 0; i < 9; i++) {
		int ny = cy + windy[dir][i];
		int nx = cx + windx[dir][i];

		// 각 칸 마다 이동하게 되는 모래의 양
		int wind_sand = (sand * rate[i]) / 100;
		sum += wind_sand;

		// 맵 밖으로 나가게 되는 경우
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
			ret += wind_sand;
			continue;
		}

		// 맵 안인 경우 다음 위치의 모래와 나간 모래를 더해줌
		a[ny][nx] += wind_sand;
	}

	// 알파 위치의 모래의 양
	// 알파 : 남은 모래의 양
	int ny = cy + dy[dir];
	int nx = cx + dx[dir];
	int alpha = (sand - sum);
	if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
		ret += alpha;
	}
	else {
		a[ny][nx] += alpha;
	}

	a[cy][cx] = 0;
	return ret;
}
//토네이도 이동 구현
int solve(int cy, int cx) {

	int ret = 0;
	bool visited[499][499] = { false, };

	//이동방향
	int dir = -1;

	// 인덱스 0이 아닌경우 계속 반복
	// (0, 0)에 도달할때까지 반복
	while (true){

		if (cy == 0 && cx == 0)break;
		visited[cy][cx] = true;
		int nd = (dir + 1) % 4;
		int ny = cy + dy[nd];
		int nx = cx + dx[nd];

		if (visited[ny][nx] == true) {
			nd = dir;

			//다시 돌아감
			ny = cy + dy[nd];
			nx = cx + dx[nd];
			
		}

		ret += wind(ny, nx, nd);
		cy = ny;
		cx = nx;
		dir = nd;
	}

	return ret;
}
int main() {

	cin >> n;

	// 모래의 양을 입력 받음
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			cin >> a[i][j];

		}
	}

	// 토네이도는 항상 중앙에 위치
	int cy = n / 2;
	int cx = n / 2;
	int ans = solve(cy, cx);
	cout << ans << endl;

	return 0;
}