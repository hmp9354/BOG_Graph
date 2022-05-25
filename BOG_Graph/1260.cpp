// Incomplete
#include <iostream>

char Node[10001][10001] = { 0, };
char visitNode[10001] = { 0, };

void DFS(int V, int N) {
	visitNode[V] = 1;
	printf("%d ", V);
	for (int i = 1; i <= N; i++) {
		if (Node[V][i] && !visitNode[i]) {						
			DFS(i, N);
		}
	}
}

//void BFS(int V, int N) {	
//	for (int i = 1; i <= N; i++) {
//		if (!visitNode[V]) {
//			visitNode[V] = 1;
//			printf("%d ", V);
//		}
//		if (Node[V][i]) {
//			if (!visitNode[i]) {
//				visitNode[i] = 1;				
//				printf("%d ", V);
//			}
//		}		
//	}
//	BFS()
//}

int main() {
	int N, M, V;
	scanf_s("%d %d %d", &N, &M, &V);	

	int a, b;
	for (int i = 0; i < M; i++) {
		scanf_s("%d %d", &a, &b);
		Node[a][b] = 1;
		Node[b][a] = 1;
	}
	
	DFS(V, N);
	printf("\n");

	for (int i = 0; i <= N; i++) {
		visitNode[i] = 0;
	}

	BFS(V, N);
}