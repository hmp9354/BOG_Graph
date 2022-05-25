#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
char list[100][100] = { 0, };
int wayNum[100][100] = { 0, };

int num = 1;
int result = 101*101;
void DFS(int n, int m) {		
	if (n == N - 1 && m == M - 1) {
		return;
	}
	else {
		int tn = 0;
		int tm = 0;		
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				tn = n -1;
				tm = m;
			}
			else if (i == 1) {
				tn = n;
				tm = m - 1;
			}
			else if (i == 2) {
				tn = n + 1;
				tm = m;
			}
			else {
				tn = n;
				tm = m + 1;
			}
			if (!(tn == 0 && tm == 0) && !(tn == n && tm == m) && tn >= 0 && tm >= 0 && tn < N && tm < M && list[tn][tm]) {
				wayNum[n][m] = min(wayNum[tn][tm] + 1, wayNum[n][m]);				
			}
		}
		
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				tn = n - 1;
				tm = m;
			}
			else if (i == 1) {
				tn = n;
				tm = m - 1;
			}
			else if (i == 2) {
				tn = n + 1;
				tm = m;
			}
			else {
				tn = n;
				tm = m + 1;
			}
			if (!(tn == 0 && tm == 0) && !(tn == n && tm == m) && tn >= 0 && tm >= 0 && tn < N && tm < M && list[tn][tm]) {				
				DFS(tn, tm);
			}
		}
	}	
}

int main() {
	scanf_s("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (list[i][j]) {
				wayNum[i][j] = 101;
			}			
		}
	}

	wayNum[0][0] = 1;
	DFS(0, 0);

	cout << wayNum[N - 1][M - 1];
}