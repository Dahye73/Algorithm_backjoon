#include <iostream>
#include <queue>
using namespace std;

int attack[6][3] = {
	{9, 3, 1},
	{9, 1, 3},
	{3, 9, 1},
	{3, 1, 9},
	{1, 3, 9},
	{1, 9, 3}
};

struct scv
{
	int a, b, c;
};

int visited[64][64][64];

int bfs(int _a, int _b, int _c) {

	queue<scv> q;

	visited[_a][_b][_c] = 1;
	q.push({ _a, _b,_c });
	
	while (!q.empty())
	{
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;

		q.pop();
		
		if (a == 0 && b == 0 && c == 0) {
			return visited[a][b][c] - 1;
		}
		for (int i = 0; i < 6; i++) {

			int na = max(0, a - attack[i][0]);
			int nb = max(0, b - attack[i][1]);
			int nc = max(0, c - attack[i][2]);

			if (visited[na][nb][nc] != 0)continue;

			q.push({ na, nb, nc });
			visited[na][nb][nc] = visited[a][b][c] + 1;
		}
	}
}
int main() {

	int n;
	int a[3] = { 0, };
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << bfs(a[0], a[1], a[2]);
	
	return 0;
}