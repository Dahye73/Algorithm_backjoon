#include <iostream>
#include <vector>
using namespace std;

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, d;
  vector<int> dist(10001);
  vector<pair<int, int>> pos[10001];

  cin >> n >> d;

  int start, end, cost;

  for (int i = 0; i < n; i++) {
    cin >> start >> end >> cost;

    if (end > d || end - start < cost)
      continue;
    pos[end].push_back({start, cost});
  }

  dist[0] = 0;
  for (int i = 1; i <= d; i++) {

    dist[i] = dist[i - 1] + 1;
    for (int j = 0; j < pos[i].size(); j++) {
      dist[i] = min(dist[i], dist[pos[i][j].first] + pos[i][j].second);
    }
  }

  cout << dist[d];
  return 0;
}