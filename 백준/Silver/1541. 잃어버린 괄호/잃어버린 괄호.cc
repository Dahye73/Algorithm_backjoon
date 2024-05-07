#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {

  string s, tmp;
  bool minus = false;
  int result = 0;

  cin >> s;
  for (int i = 0; i < s.size() + 1; i++) {
    if (s[i] == '-' || s[i] == '+' || s[i] == '\0') {
      if (minus)
        result -= stoi(tmp);
      else
        result += stoi(tmp);

      tmp = "";

      if (s[i] == '-')
        minus = true;
    } else {
      tmp += s[i];
    }
  }

  cout << result;
  return 0;
}