#include<iostream>
#include<vector>
#include <climits>
using namespace std;

// 연산자 : 덧셈(+), 뺄셈(-), 곱셈(x), 나눗셈(/)
int n;
int max_num = INT_MIN;
int min_num = INT_MAX;
int num[11];
int operate[4];

void solution(int result, int idx) {

	if (idx == n) {
		if (result > max_num)max_num = result;
		if (result < min_num)min_num = result;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (operate[i] > 0) {

			operate[i]--;
			if (i == 0)solution(result + num[idx], idx + 1);
			else if (i == 1)solution(result - num[idx], idx + 1);
			else if (i == 2)solution(result * num[idx], idx + 1);
			else if (i == 3)solution(result / num[idx], idx + 1);

			operate[i]++;
		}
	}
	return;
}
int main() {

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
		
	for (int i = 0; i < 4; i++)
		cin >> operate[i];
	
	solution(num[0], 1);

	cout << max_num << "\n" << min_num << endl;

	return 0;
}