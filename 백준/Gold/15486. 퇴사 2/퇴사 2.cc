#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // t : 걸리는 기간
  // p : 받는 금액
  int n, t, p;
  int dp[1500002] = {0};
  cin >> n;
  for (int i = 1; i < n + 1; i++) {
    cin >> t >> p;

    if (i + t <= n + 1) {
      dp[i + t] = max(dp[i + t], dp[i] + p);
    }
    dp[i + 1] = max(dp[i], dp[i + 1]);
  }

  cout << dp[n + 1];
  return 0;
}