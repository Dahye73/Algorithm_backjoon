#include <iostream>
using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int dp[1000001] = {0};
  int n;
  cin >> n;

  dp[1] = 1;
  dp[2] = 2;

  for (int i = 3; i < n + 1; i++) {
    dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;
  }

  cout << dp[n];
  return 0;
}