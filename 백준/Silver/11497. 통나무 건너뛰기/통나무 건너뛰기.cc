#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    sort(arr, arr + n, greater<>());

    int max = abs(arr[0] - arr[1]);

    for (int i = 0; i < n - 1; i++) {
      if (i == n - 2) {
        if (abs(arr[i] - arr[i + 1]) > max) {
          max = abs(arr[i] - arr[i + 1]);
        }
        break;
      } else {
        if (arr[i] - arr[i + 2] > max) {
          max = abs(arr[i] - arr[i + 2]);
        }
      }
    }
    cout << max << endl;
  }

  return 0;
}