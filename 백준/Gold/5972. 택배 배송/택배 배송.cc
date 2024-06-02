#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> dijkstra(int start, int n, vector<pair<int, int>> graph[]) {

  // 거리를 저장할 배열 ->  무한대로 초기화
  vector<int> dist(n + 1, INT_MAX);

  // 우선순위 큐 정의 (최소힙) : 현재의 위치에서 가장 거리가 짧은 인접한 노드를
  // 선택
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  dist[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {

    int cur_dist = pq.top().first;
    int cur_node = pq.top().second;

    pq.pop();

    for (int i = 0; i < graph[cur_node].size(); i++) {

      int next_dist = cur_dist + graph[cur_node][i].second;
      int next_node = graph[cur_node][i].first;

      if (next_dist < dist[next_node]) {
        dist[next_node] = next_dist;
        pq.push({next_dist, next_node});
      }
    }
  }

  return dist;
}
int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> graph[n + 1];

  for (int i = 0; i < m; i++) {

    int from, to, cost;
    cin >> from >> to >> cost;

    graph[from].push_back({to, cost});
    graph[to].push_back({from, cost});
  }

  vector<int> answer;
  answer = dijkstra(1, n, graph);
  cout << answer[n] << endl;

  return 0;
}