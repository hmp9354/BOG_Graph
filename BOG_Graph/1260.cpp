// Incomplete
#include <iostream>

int main() {
	int N, M, V;
	scanf_s("%d %d %d", &N, &M, &V);

	int Node[1002][1002] = { 0, };
	int visitNode[1002] = { 0, };

	int a, b;
	for (int i = 0; i < M; i++) {
		scanf_s("%d %d", &a, &b);
		Node[a][b] = 1;
		Node[b][a] = 1;
	}

	while (1) {

	}
}