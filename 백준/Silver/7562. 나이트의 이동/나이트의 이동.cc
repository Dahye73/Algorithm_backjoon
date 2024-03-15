#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include<cstring>
using namespace std;

int dx[8] = { -2, -1, -2, 1, -1, 2, 1, 2 };
int dy[8] = { -1, -2, 1, -2, 2, -1, 2, 1 };
int visited[301][301];
int chess[301][301];
int l;



int bfs(pair<int, int> s, pair<int, int> e) {

	queue < pair<int, int>> q;
	q.push({ s.first, s.second });
	visited[s.first][s.second] = 1;
	chess[s.first][s.second] = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == e.first && y == e.second) {
			return chess[x][y];
		}
		for (int i = 0; i < 8; i++) {
			
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(0 <= nx && nx < l && 0 <= ny && ny < l && visited[nx][ny] == 0){
				q.push({ nx, ny });
				chess[nx][ny] = chess[x][y] + 1;
				visited[nx][ny] = 1;
			}
		}
	}
	return -1;
}

int main() {

	int t;
	pair<int, int> start;
	pair<int, int> end;

	cin >> t;
	while (t--) {
		
		cin >> l;
		cin >> start.first >> start.second;
		cin >> end.first >> end.second;

		memset(visited, 0, sizeof(visited));
		memset(chess, 0, sizeof(chess));

		cout << bfs(start, end) << endl;
	}
	return 0;
}