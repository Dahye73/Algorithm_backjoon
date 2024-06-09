#include <iostream>
using namespace std;

int main() {

  int h, w;
  int block[500];

  cin >> h >> w;
  for (int i = 0; i < w; i++) {
    cin >> block[i];
  }

  int ans = 0;
  for (int i = 1; i < w - 1; i++) {

    int max_left = 0;
    int max_right = 0;

    // 현재 위치 기준으로 왼쪽 중 가장 높은 값 구하기
    for (int l = 0; l < i; l++) {
      max_left = max(max_left, block[l]);
    }

    // 현재 위치 기준으로 오른쪽 중 가장 높은 값 구하기
    for (int r = i + 1; r < w; r++) {
      max_right = max(max_right, block[r]);
    }

    // 두개의 높이 중 더 작은 높이의 블록 선택
    int min_h = min(max_left, max_right);

    if (min_h > block[i])
      ans += (min_h - block[i]);
  }

  cout << ans << endl;
  return 0;
}