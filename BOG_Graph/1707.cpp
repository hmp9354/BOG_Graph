// InComplete
#include <iostream>

char list[20001][20001] = { 0 };

void Search(char list[][20001], int E) {
	char numList[20001] = { 0 };

	numList[1] = 1;
	int color = 2;
	for (int i = 1; i <= E; i++) 
	{			
		for (int j = 1; j <= E; j++) 
		{
			if (!numList[i])
			{
				numList[i] = 1;
			}
			if (list[i][j]) {				
				if (!numList[j]) {
					if (numList[i] == 2) { numList[j] = 1; }
					else { numList[j] = 2; }										
				}
				else {
					if (numList[i] == numList[j]) {
						printf("NO\n");
						return;
					}
				}
			}				
		}		
	}

	printf("YES\n");
}

int main() {
	int K, V, E;

	scanf_s("%d", &K);
	
	int u, v;
	int num = 0;
	while (num < K) {
		scanf_s("%d %d", &V, &E);
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