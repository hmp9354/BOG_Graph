#include <iostream>

struct Node {
	int parent;
	int left = 0;
	int right = 0;
};

Node v[100002];
char check[100002] = { 0, };

int main() {
	int N;
	scanf_s("%d", &N);

	check[1] = 1;
	for (int i = 1; i < N; i++) {
		int a, b;
		scanf_s("%d %d", &a, &b);

		if (check[a]) {
			if (v[a].left == 0) {
				v[a].left = b;
				v[b].parent = a;
				check[b] = 1;
			}
			else {
				v[a].right = b;
				v[b].parent = a;
				check[b] = 1;
			}
		}
		else if (check[b]) {
			if (v[b].left == 0) {
				v[b].left = a;
				v[a].parent = b;
				check[a] = 1;
			}
			else {
				v[b].right = a;
				v[a].parent = b;
				check[a] = 1;
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		printf("%d\n", v[i].parent);
	}
}