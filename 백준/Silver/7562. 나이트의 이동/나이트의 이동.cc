#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int dx[8] = { -2, -1, -2, 1, -1, 2, 1, 2 };
int dy[8] = { -1, -2, 1, -2, 2, -1, 2, 1 };
int l;



int bfs(pair<int, int> s, pair<int, int> e, int cnt) {

	vector<int> v = { s.first, s.second, cnt };
	queue<vector<int>> q;
	int visited[301][301] = { 0, };

	q.push(v);

	while (!q.empty())
	{
		int x = q.front()[0];
		int y = q.front()[1];
		int c = q.front()[2];

		q.pop();

		if (x == e.first && y == e.second) {
			return c;
		}
		for (int i = 0; i < 8; i++) {
			
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(0 <= nx && nx < l && 0 <= ny && ny < l && visited[nx][ny] == 0){
				
				vector<int> new_v = { nx, ny, c + 1 };
				q.push(new_v);
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

		cout << bfs(start, end, 0) << endl;
	}
	return 0;
}
