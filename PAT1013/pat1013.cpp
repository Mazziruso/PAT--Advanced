//dfs
/*#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

int N;
int **graph;
int *visit;

void DFSVisit(int u) {
	visit[u] = 1;
	for(int k=0; k<N; k++) {
		if(visit[k]==0 && graph[u][k]>0) {
			DFSVisit(k);
		}
	}
}

int main() {
	int M,K;
	int indexI,indexJ;
	int NumConnect;
	int node;

	scanf("%d %d %d\n",&N,&M,&K);

	graph = new int* [N];
	for(int i=0; i<N; i++) {
		graph[i] = new int[N];
	}

	for(int i=0; i<M; i++) {
		scanf("%d %d", &indexI, &indexJ);
		graph[indexI-1][indexJ-1]=1;
		graph[indexJ-1][indexI-1]=1;
	}

	visit = new int[N];
	while(K--) {
		scanf("%d",&node);
		fill(visit,visit+N,0);
		visit[node-1]=1;
		NumConnect = 0;
		for(int i=0; i<N; i++) {
			if(visit[i]==0) {
				DFSVisit(i);
				NumConnect++;
			}
		}

		if(NumConnect==0) {
			printf("0\n");
		} else {
			printf("%d\n",(NumConnect-1));
		}
	}


	return 0;
}*/

//union-find set
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

int N;
int *x;
int *y;
int *pre;

int find(int a) {
	if(a != pre[a]) {
		pre[a] = find(pre[a]);
	}
	return pre[a];
}

void join(int a,int b) {
	int rootA = find(a);
	int rootB = find(b);

	if(rootA != rootB) {
		pre[rootB] = rootA;
	}
}

void init() {
	for(int i=0; i<=N; i++) {
		pre[i] = i;
	}
}

int main() {

	int M,K;
	int NumConnected;

	scanf("%d %d %d", &N, &M, &K);

	x = new int[M];
	y = new int[M];
	pre = new int[N+1];

	for(int i=0; i<M; i++) {
		scanf("%d %d", x+i, y+i);
	}

	int u;
	while(K--) {
		scanf("%d", &u);

		init();
		for(int i=0; i<M; i++) {
			if(x[i]!=u && y[i]!=u) {
				join(x[i],y[i]);
			}
		}

		NumConnected = 0;
		for(int i=1; i<=N; i++) {
			if(i==pre[i] && i!=u) {
				NumConnected++;
			}
		}

		if(NumConnected==0) {
			printf("0\n");
		} else {
			printf("%d\n",NumConnected-1);
		}
	}

	return 0;
}