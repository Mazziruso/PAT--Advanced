#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#define maxn 2001

using namespace std;

int maxWeight;
int maxNode;
int P;
int num;

map<string, int> nameNode;
string *nodeName;

//result store
struct headNum {
	string name;
	int num;
};
vector<headNum> res;

bool *visit;
int **graph;

bool cmp(headNum h1, headNum h2) {
	return h1.name.compare(h2.name) < 0;
}

int dfs(int i) {

	int dist = 0;
	int weight = 0;

	visit[i] = true;

	for (int j = 0; j < P; j++) {
		if (!visit[j] && graph[i][j] > 0) {
			dist += dfs(j);
		}
		weight += graph[i][j];
	}

	if (weight > maxWeight) {
		maxWeight = weight;
		maxNode = i;
	}

	dist += weight;
	num++;
	return dist;
}

int main() {

	int N, K;
	scanf_s("%d %d",&N,&K);

	string name1;
	string name2;
	int time;
	int node = 0;
	nodeName = new string[maxn];

	graph = new int *[maxn];
	for (int i = 0; i < maxn; i++) {
		graph[i] = new int[maxn];
		fill(graph[i], graph[i] + maxn, 0);
	}

	int node1;
	int node2;
	for (int i = 0; i < N; i++) {
		cin >> name1 >> name2 >> time;
		if (nameNode.find(name1) == nameNode.end()) {
			nameNode.insert(pair<string, int>(name1, node));
			nodeName[node] = name1;
			node++;
		}
		if (nameNode.find(name2) == nameNode.end()) {
			nameNode.insert(pair<string, int>(name2, node));
			nodeName[node] = name2;
			node++;
		}

		node1 = nameNode.find(name1)->second;
		node2 = nameNode.find(name2)->second;
		graph[node1][node2] += time;
		graph[node2][node1] += time;
	}

	P = nameNode.size();

	//dfs
	visit = new bool[maxn];
	fill(visit, visit + maxn, false);

	headNum hn;
	int totalTime;
	for (int i = 0; i < P; i++) {
		num = 0;
		maxWeight = -1;
		if (!visit[i]) {
			totalTime = dfs(i);
			if (totalTime > 2*K && num > 2) {
				hn.name = nodeName[maxNode];
				hn.num = num;
				res.push_back(hn);
			}
		}
	}

	sort(res.begin(),res.end(),cmp);
	int resSize = res.size();
	
	printf("%d\n", resSize);
	for (int i = 0; i < resSize; i++) {
		cout << res[i].name << " " << res[i].num << endl;
	}

	system("pause");
	return 0;
}