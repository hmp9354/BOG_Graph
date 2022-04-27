#include <iostream>

int main() {
	int N;
	scanf_s("%d", &N);

	char list[26][26] = { 0, };

	for (int i = 1; i <=N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &list[i][j]);
		}
	}
}