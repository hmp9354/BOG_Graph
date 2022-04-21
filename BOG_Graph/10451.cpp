#include <iostream>

int main() {
	int T, N;
	int list[1002] = { 0, };
	char checkNum[1002] = { 0, };

	scanf_s("%d", &T);

	for (int k = 0; k < T; k++) {
		scanf_s("%d", &N);

		for (int i = 1; i <= N; i++) {
			scanf_s("%d", &list[i]);
			checkNum[i] = 0;
		}

		int root = 1;
		int cycleNum = 0;
		
		for (int i = 1; i <= N; i++) {
			if (checkNum[i] == 1) { continue; }
			else {
				root = i;
				checkNum[i] = 1;
				int j = list[i];
				while (1) {
					checkNum[j] = 1;
					if ((root == list[j]) || (list[j] == j)) {
						cycleNum++;
						break;
					}
					else {						
						j = list[j];
					}
				}
			}
		}

		printf("%d\n", cycleNum);
	}
	
}