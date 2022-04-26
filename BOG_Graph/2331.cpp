#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main() {	
	int A, P;
	cin >> A >> P;	
	vector<int> numList(300000);

	numList[A] = 1;
	int sum = 0;
	int result = 2;
	while (1) {
		sum = 0;
		while (1) {
			sum += pow(A % 10, P);
			A /= 10;
			if (!A) {
				sum += pow(A % 10, P);
				A = sum;
				break;
			}
		}		
		if (numList[sum]) {					
			numList[sum]--;			
			break;
		}
		numList[sum] = result;		
		result++;
	}

	cout << numList[sum];
}