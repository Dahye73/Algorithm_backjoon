#include<iostream>
#include<vector>
#include <climits>
using namespace std;

int n;
int ans = INT_MAX;
int arr[21][21];
int check[21];

void solve(int cnt, int prev) {

	if (cnt == n / 2) {

		int start = 0;
		int link = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				if (check[i] && check[j]) start += arr[i][j];
				if (!check[i] && !check[j]) link += arr[i][j];

			}
		}
		ans = min(ans, abs(start - link));
	}

	for (int i = prev + 1; i < n; i++) {
		check[i] = true;
		solve(cnt + 1, i);
		check[i] = false;
	}
	
}
int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	solve(0, 0);

	cout << ans << endl;
	return 0;
}