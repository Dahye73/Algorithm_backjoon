#include <string>
#include <set>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    set<pair<pair<int, int>, pair<int, int>>> paths;
    int x = 0, y = 0; 

    for (char dir : dirs) {
        int nx = x, ny = y;
        
        if (dir == 'U' && y < 5) ny++;
        else if (dir == 'D' && y > -5) ny--;
        else if (dir == 'R' && x < 5) nx++;
        else if (dir == 'L' && x > -5) nx--;

        if (nx == x && ny == y) continue; 

        // 경로를 양방향으로 고려하여 저장
        pair<int, int> from = {x, y};
        pair<int, int> to = {nx, ny};
        pair<pair<int, int>, pair<int, int>> path = {from, to};

        if (paths.find(path) == paths.end() && paths.find({to, from}) == paths.end()) {
            answer++;
            paths.insert(path); 
        }

        x = nx;
        y = ny;
    }

    return answer;
}
