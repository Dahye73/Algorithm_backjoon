#include <iostream>
#include <set>
using namespace std;

int arr[4] = {1, 5, 10, 50};
set<int> sums;
int N;

void combi(int depth, int start, int current_sum) {

  if (depth == N) {
    sums.insert(current_sum);
    return;
  }

  for (int i = start; i < 4; i++) {
    combi(depth + 1, i, current_sum + arr[i]);
  }
}

int main() {
  cin >> N;
  combi(0, 0, 0);
  cout << sums.size() << endl;
  return 0;
}