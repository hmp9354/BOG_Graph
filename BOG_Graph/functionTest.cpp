#include <iostream>
using namespace std;

int TestFucn(int num) {	
	int way = 0;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 6; j++) {
			if (num + i == 6) {
				//way = num + num;
				return way;
			}
		}		
		way++;
	}
	return way;
}
int main() {
	int num = 9;
	int tmp = TestFucn(num);
	cout << "�Լ� ��ȯ ���� tmp�� �޾Ƽ� ��� : " << tmp << endl;
	cout << "�Լ� ��ȯ ���� �ٷ� ��� : "<<TestFucn(num);
}