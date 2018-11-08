#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

//disjoint set union(并查集)
class DSU {
public:
	int M; //the total number of sets
	int N;
	int father[10001];
	
	DSU() {
		this->M = 0;
		this->N = 10001;
		for (int i = 0; i < 10001; i++) {
			father[i] = i;
		}
	}
	DSU(int N) {
		this->M = 0;
		this->N = N;
		for (int i = 0; i < 10001; i++) {
			father[i] = i;
		}
	}

	void setN(int N) {
		this->N = N;
	}

	int getNumSets() {
		int count = 0;
		for (int i = 1; i <= N; i++) {
			if (this->father[i] == i) {
				count++;
			}
		}
		this->M = count;
		return count;
	}

	//find root of set
	int findFather(int node) {
		if (node == this->father[node]) {
			return node;
		}
		this->father[node] = this->findFather(this->father[node]);
		return this->father[node];
	}

	//check whether two points are in same set
	bool checkSet(int node1, int node2) {
		int r1 = this->findFather(node1);
		int r2 = this->findFather(node2);
		return r1 == r2;
	}

	//union two sets
	void unionSet(int node1, int node2) {
		int r1 = this->findFather(node1);
		int r2 = this->findFather(node2);
		if (r1 != r2) {
			this->father[r1] = r2;
		}
	}

	//compress path
	void compress() {
		for (int i = 1; i <= this->N; i++) {
			findFather(i);
		}
	}
};

int main() {

	int N, K, Q;
	int bird;
	scanf_s("%d", &N);

	DSU sets;

	int birdF; //标识每张图中领头鸟id
	int maxIndex = -1; //which denotes the total number of birds
	while (N--) {
		scanf_s("%d", &K);
		if (K > 0) {
			scanf_s("%d", &birdF);
			K--;
			maxIndex = (maxIndex < birdF) ? birdF : maxIndex;
		}
		while (K--) {
			scanf_s("%d", &bird);
			sets.unionSet(birdF, bird);
			maxIndex = (maxIndex < bird) ? bird : maxIndex;
		}
	}

	//compress path
	sets.setN(maxIndex);
	sets.compress();
	int trees = sets.getNumSets();
	printf("%d %d\n", trees, maxIndex);

	//query
	scanf_s("%d", &Q);
	while (Q--) {
		scanf_s("%d %d", &birdF, &bird);
		printf("%s\n", sets.checkSet(birdF, bird) ? "Yes" : "No");
	}

	system("pause");
	return 0;
}