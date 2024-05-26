#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int room[20][20] = { 0 };
int n;
vector<tuple<int, int, int, int>> student;

// 인접한 좋아하는 학생 수와 빈칸 수를 계산하고 최적의 위치를 선택하는 함수
pair<int, int> find_position(int s, int f1, int f2, int f3, int f4) {

    // {좋아하는 학생 수, 빈칸 수, 행, 열}
    vector<tuple<int, int, int, int>> candidates;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (room[i][j] != 0) continue; // 비어있는 칸만 고려
            int like_c = 0, empty_c = 0;

            for (int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (room[nx][ny] == 0) empty_c++;
                if (room[nx][ny] == f1 || room[nx][ny] == f2 || room[nx][ny] == f3 || room[nx][ny] == f4) like_c++;
            }

            candidates.push_back({ like_c, empty_c, i, j });
        }
    }

    sort(candidates.begin(), candidates.end(), [](const auto& a, const auto& b) {
        if (get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b); // 좋아하는 학생수가 많은 순
        if (get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b); // 빈 칸 수가 많은 순
        return tie(get<2>(a), get<3>(a)) < tie(get<2>(b), get<3>(b)); // 행, 열 순으로 정렬
        });

    return { get<2>(candidates[0]), get<3>(candidates[0]) };
}

void place_student(int s, int f1, int f2, int f3, int f4) {
    auto p = find_position(s, f1, f2, f3, f4);
    room[p.first][p.second] = s;
}

int sat_detect() {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int student_num = room[i][j];
            auto fav_s = student[student_num - 1];
            int like_c = 0;
            for (int d = 0; d < 4; ++d) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (room[nx][ny] == get<0>(fav_s) || room[nx][ny] == get<1>(fav_s) || room[nx][ny] == get<2>(fav_s) || room[nx][ny] == get<3>(fav_s)) {
                    like_c++;
                }

            }
            if (like_c == 1) ans += 1;
            else if (like_c == 2) ans += 10;
            else if (like_c == 3) ans += 100;
            else if (like_c == 4) ans += 1000;
        }
    }
    return ans;
}

int main() {
    cin >> n;
    student.resize(n * n);

    for (int i = 0; i < n * n; i++) {
        int s, f1, f2, f3, f4;
        cin >> s >> f1 >> f2 >> f3 >> f4;
        student[s - 1] = { f1, f2, f3, f4 };
        place_student(s, f1, f2, f3, f4);
    }

 /*   for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << room[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << sat_detect() << endl;

    return 0;
}
