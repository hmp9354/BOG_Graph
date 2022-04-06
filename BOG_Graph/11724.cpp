#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, M;
	scanf_s("%d %d", &N, &M);

	char list[1001][1001] = { 0 };

	int a, b;
	for (int i = 0; i < M; i++) {
		scanf_s("%d %d", &a, &b);
		list[a][b] = 1;
		list[b][a] = 1;
	}

	queue<int> q;
	char numList[1001] = { 0, };

	
	int v;

	int result = 0;
	

	for (int i = 1; i <= N; i++) {
		if (!numList[i]) {
			q.push(i);
			numList[i] = 1;
			while (q.size()) {
				v = q.front();
				numList[i] = 1;
				q.pop();
				for (int i = 1; i <= N; i++) {
					if (numList[i] == 1 || !list[v][i])
						continue;
					q.push(i);
				}
			}
			result++;
		}
	}

	printf("%d", result);
}