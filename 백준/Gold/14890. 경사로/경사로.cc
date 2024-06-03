#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l;
    int map[100][100];

    // 총 지나갈 수 있는 길의 개수
    int road = 0;

    cin >> n >> l;
    vector<vector<int>> vecMap(2 * n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    // 가로 방향 길 추가
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vecMap[i].push_back(map[i][j]);
        }
    }

    // 세로 방향 길 추가
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            vecMap[j + n].push_back(map[i][j]);
        }
    }

    // 길을 검사하는 부분
    for (int i = 0; i < vecMap.size(); i++) {
        bool pass = true;
        
        // 경사로 설치여부 확인 -> 중복 설치를 제거하기 위함
        vector<bool> slope(vecMap[i].size(), false);

        for (int j = 0; j < vecMap[i].size() - 1; j++) {
            // 현재 위치와 다음 위치의 높이가 다를 경우
            if (vecMap[i][j] != vecMap[i][j + 1]) {
                // 차이가 1 이상인 경우
                if (abs(vecMap[i][j] - vecMap[i][j + 1]) > 1) {
                    pass = false;
                    break;
                }
                // 차이가 1인 경우
                else if (abs(vecMap[i][j] - vecMap[i][j + 1]) == 1) {
                    int cnt = 0;

                    // 다음 위치의 높이가 더 큰 경우
                    if (vecMap[i][j] < vecMap[i][j + 1]) {
                        for (int k = 0; k < l; k++) {
                            if (j - k >= 0 && vecMap[i][j - k] == vecMap[i][j] && !slope[j - k]) {
                                cnt++;
                                slope[j - k] = true;
                            }
                        }

                        if (cnt != l) {
                            pass = false;
                            break;
                        }
                    }
                    // 다음 위치의 높이가 더 작은 경우
                    else {
                        for (int k = 1; k <= l; k++) {
                            if (j + k < n && vecMap[i][j + k] == vecMap[i][j + 1] && !slope[j + k]) {
                                cnt++;
                                slope[j + k] = true;
                            }
                        }

                        if (cnt != l) {
                            pass = false;
                            break;
                        }
                        else {
                            j += l - 1; // 경사로 설치한 부분 건너뛰기
                        }
                    }
                }
            }
        }
        if (pass) road++;
    }

    cout << road << endl;
    return 0;
}
