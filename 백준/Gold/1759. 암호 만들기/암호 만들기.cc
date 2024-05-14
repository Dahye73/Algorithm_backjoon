#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int l, c;
char alpha[16];
string pwd = "";

void combi(int depth, int start, int cc, int cv) {

  if (depth == l) {
    if (cv <= 0 && cc <= 0) {
      cout << pwd << endl;
    }
    return;
  }

  for (int i = start; i < c; i++) {
    pwd += alpha[i];

    if (strchr("aeiou", alpha[i])) {
      combi(depth + 1, i + 1, cc, cv - 1); // 모음이면 cv를 감소
    } else {
      combi(depth + 1, i + 1, cc - 1, cv); // 자음이면 cc를 감소
    }
    pwd.pop_back();
  }
}

int main() {

  cin >> l >> c;
  for (int i = 0; i < c; i++)
    cin >> alpha[i];

  // 증가하는 순서로 정렬
  sort(alpha, alpha + c);
  combi(0, 0, 2, 1);
  return 0;
}