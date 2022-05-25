#include <iostream>

char list[26][26] = { 0, };
char checkList[26] = { 0, };

void DFS(int root, int &num) {
	for (int i = 1; i <= 26; i++) {
		if (list[root][i]) {			
			if (!checkList[i]) {				
				checkList[i] = 1;
			}		
			num++;
			DFS(i, num);
		}		
	}
	
}
int main() {
	int N, num = 1;
	scanf_s("%d", &N);
	
	for (int i = 1; i <=N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf_s("%c", &list[i][j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (!checkList[i]) {
			DFS(i, num);
			printf("%d\n", num);
			num = 1;
		}		
	}
}