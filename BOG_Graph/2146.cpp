#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int map[100][100] = { 0, };
int IsNum = 1;
char checkIslnd[100][100] = { 0, };
int Result = 100 * 100;
queue<pair<int, int>> list;

int makeBridge(int nowNum) {
	int tmpX[4] = { 0, 0, 1, -1 };
	int tmpY[4] = { 1, -1, 0, 0 };

	int way = 0;

	while (!list.empty()) {
		list.pop();
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == nowNum) {
				list.push(make_pair(i, j));						
			}
		}
	}	
	
	bool stop = false;
	while (!list.empty()) {		
		int size = list.size();
		for (int i = 0; i < size; i++) {
			int x = list.front().first;
			int y = list.front().second;

			list.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + tmpX[k];
				int ny = y + tmpY[k];

				if (nx >= 0 && nx < N && ny >= 0 && ny < N && !map[nx][ny] && !checkIslnd[nx][ny]) {					
					checkIslnd[nx][ny] = 1;
					list.push(make_pair(nx, ny));
				}
				else if (nx >= 0 && nx < N && ny >= 0 && ny < N && (map[nx][ny] != nowNum) && map[nx][ny]) {					
					stop = true;
					break;
					//return way;
				}
			}
			if (stop) { break; }
		}	
		if (stop) { break; }
		way++;
	}		
	return way;
}

void Solution() {	
	int tmp;
	for (int k = 1; k < IsNum; k++) {			
		tmp = makeBridge(k);
		if (Result > tmp) {			
			Result = tmp;			
		}			
	}
}

void putNum() {
	
	int tmpX[4] = { 0, 0, 1, -1 };
	int tmpY[4] = { 1, -1, 0, 0 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] && !checkIslnd[i][j]) {
				list.push(make_pair(i, j));
				checkIslnd[i][j] = 1;
				map[i][j] = IsNum;
		
				while (!list.empty()) {
					int x = list.front().first;
					int y = list.front().second;

					list.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + tmpX[k];
						int ny = y + tmpY[k];

						if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[nx][ny] && !checkIslnd[nx][ny]) {
							map[nx][ny] = IsNum;
							checkIslnd[nx][ny] = 1;
							list.push(make_pair(nx, ny));
						}
					}
				}
				IsNum++;
			}			
		}
	}
}

int main() {	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				map[i][j] = -1;
			}
		}
	}

	putNum();
	Solution();

	cout << Result;	
}