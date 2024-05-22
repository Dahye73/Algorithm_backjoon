#include <iostream>
using namespace std;

int n, k;
int kit[9];
bool check[9];
int cnt;

void permutation(int depth, int weight) {

  if (depth == n) {

    cnt++;
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!check[i] && weight - k + kit[i] >= 500) {
      check[i] = true;
      permutation(depth + 1, weight - k + kit[i]);
      check[i] = false;
    }
  }
}

int main() {

  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> kit[i];
  }
  permutation(0, 500);

  cout << cnt << endl;
  return 0;
}