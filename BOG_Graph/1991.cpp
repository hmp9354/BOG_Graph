#include <iostream>
using namespace std;

struct Node {	
	char left;
	char right;
};

struct Node q[27];

void Preorder(char root) {
	if (root) {
		cout << root;
		if (q[root - 'A'].left != '.') {
			Preorder(q[root - 'A'].left);
		}
		if (q[root - 'A'].right != '.') {
			Preorder(q[root - 'A'].right);
		}		
	}
}

void Inorder(char root) {
	if (q[root - 'A'].left != '.') {
		Inorder(q[root - 'A'].left);
	}
	//cout << q[root - 'A'].left;
	cout << root;
	if (q[root - 'A'].right != '.') {
		//cout << q[root - 'A'].right;
		Inorder(q[root - 'A'].right);
	}
}

void Postorder() {

}

int main() {
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		char root, tleft, tright;
		cin >> root >> tleft >> tright;
				
		q[root-'A'].left = tleft;
		q[root - 'A'].right = tright;
	}

	Preorder('A');
	cout << "\n";
	Inorder('A');
}