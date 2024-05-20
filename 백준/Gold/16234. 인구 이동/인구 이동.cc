#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 상, 하, 좌, 우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int N, L, R;

int land[50][50];
int check[50][50];

bool bfs(int x, int y, vector<pair<int, int>> &unions, int &sum) {
  queue<pair<int, int>> q;
  q.push({x, y});
  check[x][y] = 1;
  unions.push_back({x, y});
  sum = land[x][y];
  int count = 1;

  while (!q.empty()) {
    pair<int, int> pos = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = pos.first + dx[i];
      int ny = pos.second + dy[i];

      if (0 <= nx && nx < N && 0 <= ny && ny < N && check[nx][ny] == 0) {
        int diff = abs(land[pos.first][pos.second] - land[nx][ny]);
        if (L <= diff && diff <= R) {
          check[nx][ny] = 1;
          q.push({nx, ny});
          unions.push_back({nx, ny});
          sum += land[nx][ny];
          count++;
        }
      }
    }
  }
  return count > 1;
}

int check_open() {

  // check 배열 초기화
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      check[i][j] = 0;
    }
  }

  bool isMoved = false;

  for (int x = 0; x < N; x++) {
    for (int y = 0; y < N; y++) {
      if (check[x][y] == 0) {
        vector<pair<int, int>> unions;
        int sum = 0;
        if (bfs(x, y, unions, sum)) {
          int num = sum / unions.size();
          for (auto pos : unions) {
            land[pos.first][pos.second] = num;
          }
          isMoved = true;
        }
      }
    }
  }
  return isMoved;
}
int main() {

  cin >> N >> L >> R;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> land[i][j];
    }
  }

  int cnt = 0;
  while (true) {
    if (!check_open()) {
      break;
    }
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}