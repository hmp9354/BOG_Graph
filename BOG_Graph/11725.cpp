#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100002];
char check[100002] = { 0, };

void dfs(int r) {
	
	for (int i = 0; i < v[r].size(); i++) {
		int k = v[r][i];

		if (!check[k]) {
			check[k] = r;
			dfs(k);
		}
	}
}

int main() {
	int N;
	scanf_s("%d", &N);

	check[1] = 1;
	for (int i = 1; i < N; i++) {
		int a, b;
		scanf_s("%d %d", &a, &b);

		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= N; i++) {
		printf("%d\n", check[i]);
	}
}