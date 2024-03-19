#include<iostream>
#include<string>
using namespace std;

int main() {

	int n, m, ans;
	int arr[50][50];
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	int len, max_len = min(n, m);
	int a, b, c, d;
	for (len = 1; len <= max_len; len++) {

		for (int i = 0; i <= n - len; i++) {
			for (int j = 0; j <= m - len; j++) {

				a = arr[i][j];
				b = arr[i + len - 1][j];
				c = arr[i][j + len - 1];
				d = arr[i + len - 1][j + len - 1];

				if (a == b && b == c && c == d)ans = len;
			}
		}
	}

	cout << ans * ans;

	return 0;
}