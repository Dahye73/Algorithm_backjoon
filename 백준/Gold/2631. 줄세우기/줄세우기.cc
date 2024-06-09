#include <iostream>

using namespace std;

int main() {

  int n, result = 0;
  int arr[200], dp[200];
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (arr[j] < arr[i] && dp[i] <= dp[j]) {
        dp[i] += 1;
      }
    }

    result = max(result, dp[i]);
  }

  cout << n - result << endl;
  return 0;
}