#include <iostream>
using namespace std;

int combi(int n, int m) {

  int dp[30][30];

  
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 1;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (j == i) {
        dp[i][j] = 1;
      } else {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      }
    }
  }

  return dp[n][m];
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {

    int n, m;
    cin >> n >> m;
    cout << combi(m, n) << endl;
  }
  return 0;
}