#include <algorithm>
#include <iostream>
using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, K;
  int robot[204] = {0};
  int A[204];
  cin >> N >> K;

  for (int i = 0; i < N * 2; i++) {
    cin >> A[i];
  }

  // 과정 횟수 카운팅
  int ans = 0;
  while (true) {

    ans++;

    // 1. 벨트가 로봇과 함께 회전
    int lastA = A[N * 2 - 1];
    int lastR = robot[N * 2 - 1];
    for (int i = N * 2 - 2; i >= 0; i--) {
      A[i + 1] = A[i];
      robot[i + 1] = robot[i];
    }
    A[0] = lastA;
    robot[0] = lastR;

    robot[N - 1] = 0;

    // 2. 로봇 이동 ( 다음 칸에 로봇이 없거나 && 내구도 0이상)
    for (int i = N - 2; i >= 0; i--) {

      if (robot[i] == 1 && robot[i + 1] == 0 && A[i + 1] > 0) {

        robot[i] = 0;
        robot[i + 1] = 1;
        A[i + 1]--;
      }
    }

    robot[N - 1] = 0;

    // 3. 올리는 위치(가장 첫번째 위치)에 내구도가 0이 아니면 로봇을 올림
    if (A[0] != 0) {
      robot[0] = 1;
      A[0] -= 1;
    }

    int cnt = 0;

    // 4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정 종료
    for (int i = 0; i < N * 2; i++) {
      if (A[i] == 0)
        cnt++;
    }

    if (cnt >= K) {
      break;
    }
  }

  cout << ans << endl;
  return 0;
}