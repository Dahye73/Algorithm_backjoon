#include<iostream>
using namespace std;

int N;
int paper[129][129];
int blue, white;

void PaperDivide(int y, int x, int size) {

	int check = paper[y][x];
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (check == 0 && paper[i][j] == 1)
			{
				check = 2;
			}
			else if (check == 1 && paper[i][j] == 0)
			{
				check = 2;
			}

			if (check == 2)
			{
				//왼쪽 위 사분면 탐색
				PaperDivide(y, x, size / 2);
				//오른쪽 위 사분면 탐색
				PaperDivide(y, x + size / 2, size / 2);
				//왼쪽 아래 사분면 탐색
				PaperDivide(y + size / 2, x, size / 2);
				//오른쪽 아래 사분면 탐색
				PaperDivide(y + size / 2, x + size / 2, size / 2);
				return;
			}
		}
	}
	if (check == 0) {
		white++;
	}
	else {
		blue++;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}

	PaperDivide(0, 0, N);
	cout << white << endl;
	cout << blue << endl;
	return 0;

}