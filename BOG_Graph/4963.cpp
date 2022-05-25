#include <iostream>

int w = 1, h = 1;
int numIsland = 0;
int island[50][50] = { 0, };
int visitLand[50][50] = { 0, };

void DFS(int a, int b) {
	if (island[a][b] && !visitLand[a][b]) {
		visitLand[a][b]++;
		numIsland++;
	}
	else if (!island[a][b]) { return; }

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			int atmp = a+i;
			int btmp = b+j;
			if (atmp < 0 || atmp >= h || btmp < 0 || btmp>=w) {
				continue;
			}
			if (island[atmp][btmp] && !visitLand[atmp][btmp]) {
				visitLand[atmp][btmp]++;
				DFS(atmp, btmp);
			}
		}
	}
}

int main() {
	
	while (1) {
		scanf_s("%d %d", &w, &h);
		if (!w && !h) {
			break;
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				island[i][j] = 0;
				visitLand[i][j] = 0;
			}
		}
		numIsland = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf_s("%d", &island[i][j]);
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (island[i][j]) {
					DFS(i, j);
				}
			}
		}

		printf("%d\n", numIsland);
	}
}