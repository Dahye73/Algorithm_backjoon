#include <iostream>

using namespace std;

char find_moo(int n) {

  int k = 0;
  int l = 3; // s(0)의 길이

  // l(k) 가 n보다 크거나 같을 때까지 k와 l(k) 증가
  while (l < n) {
    k += 1;
    l = 2 * l + (k + 3);
  }

  // n번째 문자 찾기
  while (k > 0) {
    int prev_len = (l - (k + 3)) / 2;

    if (n <= prev_len) {
      l = prev_len;
      k -= 1;
    } else if (n <= prev_len + (k + 3)) {
      if (n == prev_len + 1)
        return 'm';
      else
        return 'o';
    } else {
      n -= (prev_len + (k + 3));
      l = prev_len;
      k -= 1;
    }
  }

  if (n == 1)
    return 'm';
  else
    return 'o';
}
int main() {

  int n;
  cin >> n;
  cout << find_moo(n) << endl;
  return 0;
}