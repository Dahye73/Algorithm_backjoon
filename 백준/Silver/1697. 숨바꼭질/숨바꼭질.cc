#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	queue<pair<int, int>> q;
	int visite[100001] = { 0, };


	q.push({ n, 0 });
	visite[n] = 1;
	while (!q.empty())
	{
		int d = q.front().first;
		int s = q.front().second;
		q.pop();

		if (d == k) {
			cout << s << endl;
			break;
		}

		
		int tmp[3] = { 0, };

		tmp[0] = d + 1;
		tmp[1] = d - 1;
		tmp[2] = d * 2;
		
		for (int i = 0; i < 3; i++) {

			if (tmp[i] >= 0 && tmp [i] <= 100000) {

				if (visite[tmp[i]] == 1) {
					continue;
				}
				visite[tmp[i]] = 1;
				q.push({ tmp[i], s + 1 });
			}
		}
	}
	return 0;
}