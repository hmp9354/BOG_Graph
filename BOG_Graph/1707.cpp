// InComplete
#include <iostream>

void Search(char list[][20002], int E) {
	char numList[20002] = { 0 };

	for (int i = 1; i <= E; i++) {
		numList[i] = 1;
		for (int j = 1; j <= E; j++) {
			if (list[i][j]) {
				if (numList[j]) {
					printf("NO\n");
					return;
				}
				numList[j] = 1;
			}
		}
	}

	printf("YES\n");
}

int main() {
	int K, V, E;

	scanf_s("%d", &K);
	scanf_s("%d %d", &V, &E);

	char list[20002][20002] = { 0 };
	int u, v;

	int num = 0;
	while (num < K) {
		for (int i = 1; i <= E; i++) {
			for (int j = 1; j <= E; j++) {
				list[i][j] = 0;
			}
		}
		for (int i = 0; i < E; i++) {
			scanf_s("%d %d", &u, &v);
			list[u][v] = 1;
			list[v][u] = 1;
		}

		Search(list, E);
		num++;
	}
	
}