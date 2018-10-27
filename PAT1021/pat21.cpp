#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <list>
#include <set>

#define INI_MAX 2147483647

using namespace std;

typedef struct nodee {
	int id;
	int dist;
	int visit;
} nod;

int N;
nod *nodes;
list<nod*> *graph;
set<int> nodeRes;

void dfs_visit(nod *node, int distance) {
	(*node).visit = 1;
	distance++;
	(*node).dist = distance;

	for (auto &i : graph[(*node).id-1]) {
		if ((*i).visit != 1) {
			dfs_visit(i,distance);
		}
	}

}

bool cmp(nod n1, nod n2) {
	if(n1.dist>n2.dist) {
		return true;
	} else {
		return false;
	}
}

int findMax() {
	int index=0;
	int max=0;
	for(int i=0; i<N; i++) {
		if(nodes[i].dist>max){
			max = nodes[i].dist;
			index = i;
		}
	}
	for(int i=0; i<N; i++) {
		if(max == nodes[i].dist) {
			nodeRes.insert(nodes[i].id);
		}
	}
	return index;
}

void initial(){
	for(int i=0; i<N; i++) {
		nodes[i].dist = 0;
		nodes[i].visit = 0;
	}
}

void printDist() {

	findMax();
	for(const auto &i : nodeRes) {
		printf("%d\n",i);
	}
}

int main() {

	scanf_s("%d", &N);
	
	graph = new list<nod*>[N];

	nod vertex;
	nodes = new nod[N];
	for(int i=0; i<N; i++) {
		vertex.id = i+1;
		vertex.dist = 0;
		vertex.visit = 0;
		nodes[i]=vertex;
	}

	int indexI;
	int indexJ;
	for (int i = 0; i < (N - 1); i++) {
		scanf_s("%d %d",&indexI, &indexJ);
		graph[indexI - 1].push_back(nodes+indexJ-1);
		graph[indexJ - 1].push_back(nodes+indexI-1);
	}

	int connects = 0;
	for (int i = 0; i < N; i++) {
		if (nodes[i].visit != 1) {
			dfs_visit(nodes+i,0);
			connects++;
		}
	}

	int index;
	if (connects == 1) {
		index = findMax();
		initial();
		dfs_visit(nodes+index,0);
		printDist();
	}
	else {
		printf("Error: %d components\n", connects);
	}

	system("pause");
	return 0;
}