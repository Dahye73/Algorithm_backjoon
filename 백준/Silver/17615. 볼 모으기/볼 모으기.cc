#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void set(int &cnt, bool &isColor) {
  cnt = 0;
  isColor = true;
}
int main() {

  int n;
  cin >> n;

  string balls;
  cin >> balls;

  int cnt = 0;
  bool isColor = true;
  int min_c = INT_MAX;

  // 1. 빨간공을 오른쪽으로 모으는 경우
  for (int i = n - 1; i >= 0; i--) {
    if (isColor && balls[i] == 'B')
      isColor = false;

    if (!isColor && balls[i] == 'R')
      cnt++;
  }
  min_c = min(min_c, cnt);

  // 2. 빨간공을 왼쪽으로 모으는 경우
  set(cnt, isColor);
  for (int i = 0; i < n; i++) {
    if (isColor && balls[i] == 'B')
      isColor = false;
    if (!isColor && balls[i] == 'R')
      cnt++;
  }
  min_c = min(min_c, cnt);

  // 3. 파란공을 오른쪽으로 모으는 경우
  set(cnt, isColor);
  for (int i = n - 1; i >= 0; i--) {
    if (isColor && balls[i] == 'R')
      isColor = false;

    if (!isColor && balls[i] == 'B')
      cnt++;
  }

  min_c = min(min_c, cnt);

  // 4. 파란공을 왼쪽으로 모으는 경우
  set(cnt, isColor);
  for (int i = 0; i < n; i++) {
    if (isColor && balls[i] == 'R')
      isColor = false;
    if (!isColor && balls[i] == 'B')
      cnt++;
  }
  min_c = min(min_c, cnt);

  cout << min_c << endl;
  return 0;
}