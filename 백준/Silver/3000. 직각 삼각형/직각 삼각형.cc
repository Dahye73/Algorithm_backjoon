#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  vector<pair<int, int>> points(N);
  unordered_map<int, int> x_count;
  unordered_map<int, int> y_count;

  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    points[i] = {x, y};
    x_count[x]++;
    y_count[y]++;
  }

  long long count = 0;

  for (auto point : points) {
    int x = point.first;
    int y = point.second;
    count += static_cast<long long>(x_count[x] - 1) * (y_count[y] - 1);
  }

  cout << count << endl;
  return 0;
}