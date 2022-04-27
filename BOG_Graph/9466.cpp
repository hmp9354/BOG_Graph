// 해결 못함
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T, n;
	scanf_s("%d", &T);

	vector <int>list(100002);
	vector <int>chList(100002);

	for (int i = 0; i < T; i++) {
		scanf_s("%d", &n);		

		for (int j = 1; j <= n; j++) {
			scanf_s("%d", &list[j]);
		}

		int tmp = 0;
		int chNum = 1;
		int result = n;
		for (int j = 1; j <= n; j++) {
			tmp = j;
			while (1) {
				if (!chList[tmp]) {
					chList[tmp] = 1;

					if (chList[list[tmp]]) {
						if (list[tmp] == tmp) {							
							chNum = 1;
							result -= chNum;
							break;
						}
						else {
							result -= chNum;
							chNum = 1;
							break;
						}						
					}
					tmp = list[tmp];
					chNum++;
				}
				else { 
					chNum = 1;
					break; 
				}
			}
			
		}

		printf("%d\n", result);

		/*list.clear();
		chList.clear();*/
	}
}