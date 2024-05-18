#include <iostream>
#include <vector>
using namespace std;

// 0 : x증가 , 1 : y감소, 2 : x감소, 3 : y증가
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int visited[101][101];

struct Curve {
  int x, y, d, g;
};

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;

  cin >> N;
  Curve c[N];

  //드래곤 커브 정보 입력
  for (int i = 0; i < N; i++) {

    cin >> c[i].x >> c[i].y >> c[i].d >> c[i].g;
  }

  for (int i = 0; i < N; i++) {

    vector<int> d;
    d.push_back(c[i].d);

    // 초기좌표
    visited[c[i].x][c[i].y] = 1;
    int nx = c[i].x + dx[c[i].d];
    int ny = c[i].y + dy[c[i].d];
    visited[nx][ny] = 1;

    // 드래곤 커브의 각 세대 생성
    for (int j = 0; j < c[i].g; j++) {
      int size = d.size();
      for (int k = size - 1; k >= 0; k--) {

        int new_d = (d[k] + 1) % 4;
        nx += dx[new_d];
        ny += dy[new_d];
        visited[nx][ny] = 1;
        d.push_back(new_d);
      }
    }
  }

  int cnt = 0;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (visited[i][j] == 1 && visited[i + 1][j] == 1 &&
          visited[i][j + 1] == 1 && visited[i + 1][j + 1] == 1) {
        cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
