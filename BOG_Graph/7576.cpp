#include <iostream>

int M, N;
int box[1001][1001] = { 0, };
int newBox[1001][1001] = { 0, };

int date = 0;

void DFS(int m, int n) {
	int tm = m;
	int tn = n;

	if (box[m][n] == 0) {
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				tn = n + i;
				tm = m + j;

				if (tn < 0 || tm < 0 || tn >= N || tm >= M) {
					continue;
				}
				if (box[tn][tm] == 1) {
					DFS(tn, tm);
				}
			}
		}
	}
	else if (box[m][n] == 1) {
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				tn = n + i;
				tm = m + j;

				if (box[tn][tm] == 0) {
					newBox[tn][tm] = 1;
				}
				else if (box[tn][tm] == 1) {
					DFS(tn, tm);
				}
			}
		}
	}
}

int main() {
	
	scanf_s("%d %d", &M, &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%d", &box[i][j]);
			newBox[i][j] = box[i][j];
		}
	}

	bool roop = true;
	while (roop) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (box[i][j] == 0) {
					DFS(i, j);
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				box[i][j] = newBox[i][j];
			}
		}
		date++;

		roop = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (box[i][j] == 0) { roop = true; }
			}
		}
	}
	
	printf("%d", date);
}