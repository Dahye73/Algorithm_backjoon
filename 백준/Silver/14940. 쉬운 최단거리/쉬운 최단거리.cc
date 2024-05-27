#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
pair<int, int> goal;
int map[1001][1001];
int dist[1001][1001];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void bfs() {
    queue<pair<int, int>> q;
    q.push(goal);
    dist[goal.first][goal.second] = 0;

    while (!q.empty()) {

        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == 1 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    memset(dist, -1, sizeof(dist));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                goal = { i, j };
            }
            else if (map[i][j] == 0) {
                dist[i][j] = 0; // 갈 수 없는 땅은 거리 0으로 표시
            }
            
        }
    }

    bfs();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}