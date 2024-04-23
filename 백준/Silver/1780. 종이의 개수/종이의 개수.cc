#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> v;

// 0 : -1 의 개수
// 1 : 0 의 개수
// 2 : 1 의 개수
int arr[3] = {
    0,
};

void divide(int x, int y, int n) {

  int paper = v[x][y];
  bool all_same = true;

  for (int i = x; i < x + n; i++) {
    for (int j = y; j < y + n; j++) {
      if (v[i][j] != paper) {
        all_same = false;
        break;
      }
    }
    if (!all_same)
      break;
  }

  if (all_same) {
    if (paper == -1)
      arr[0]++;
    else if (paper == 0)
      arr[1]++;
    else if (paper == 1)
      arr[2]++;
  } else {
    int size = n / 3;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        divide(x + i * size, y + j * size, size);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  v.resize(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> v[i][j];
    }
  }

  divide(0, 0, n);
  for (int i = 0; i < 3; i++) {
    cout << arr[i] << endl;
  }
  return 0;
}