#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int child[21][2];
string nodes[21];
bool leaf[21] = { false };

void inOrder(int root, int level) {
	if (root == -1) {
		return;
	}
	if (child[root][0] != -1 || child[root][1] != -1) {
		if (level != 0) {
			printf("(");
		}
		inOrder(child[root][0], level + 1);
		printf("%s", nodes[root].c_str());
		inOrder(child[root][1], level + 1);
		if (level != 0) {
			printf(")");
		}
	}
	else {
		printf("%s", nodes[root].c_str());
	}
}

int main() {
	//initialization
	for (int i = 0; i < 21; i++) {
		child[i][0] = -1;
		child[i][1] = -1;
	}

	int N;

	scanf_s("%d", &N);

	int v1, v2;
	for (int i = 1; i <= N; i++) {
		cin >> nodes[i] >> v1 >> v2;
		child[i][0] = v1;
		child[i][1] = v2;
		leaf[v1] = true;
		leaf[v2] = true;
	}

	int root = -1;
	for (int i = 1; i <= N; i++) {
		if (!leaf[i]) {
			root = i;
			break;
		}
	}

	inOrder(root, 0);
	printf("\n");

	system("pause");
	return 0;
}