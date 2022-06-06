#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v[10002];
int c[10002] = { 0, };
int maxdist = 0;
int nodeA = 1;
int n;

void DFS(int num, int dist) {

	if (c[num]) {
		return;
	}

	c[num] = 1;
	if (dist > maxdist) {
		maxdist = dist;
		nodeA = num;
	}

	for (int i = 0; i < v[num].size(); i++) {		
		DFS(v[num][i].first, v[num][i].second + dist);
	}
}

int main() {	
	scanf_s("%d", &n);

	for (int i = 0; i < n-1; i++) {
		int parent, node, weight;
		scanf_s("%d %d %d", &parent, &node, &weight);

		v[parent].push_back(make_pair(node, weight));
		v[node].push_back(make_pair(parent, weight));
	}
	
	DFS(1, 0);
	//printf("%d %d\n", nodeA, maxdist);


	for (int i = 0; i <= n; i++) {
		c[i] = 0;
	}	
	//maxdist = 0;	
	DFS(nodeA, 0);

	printf("%d", maxdist);
}