#include <algorithm>
#include <cmath> // <math.h> 대신 <cmath> 사용을 권장합니다.
#include <iostream>
using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

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

    int _max = abs(arr[0] - arr[1]);
    _max = max(_max, abs(arr[n - 2] - arr[n - 1]));

    for (int i = 0; i < n - 2; i++) {
      _max = max(_max, abs(arr[i] - arr[i + 2]));
    }
    cout << _max << endl;
  }

  return 0;
}