#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

/*int *nodeP;

bool isBinary(int *node, int start, int end) {
	if (start >= end) {
		return true;
	}

	int index = start + 1;
	while (index <= end && node[start] > node[index]) {
		index++;
	}

	int pivot = index;
	while (index <= end && node[start] <= node[index]) {
		index++;
	}
	if (index <= end) {
		return false;
	}
	else {
		return isBinary(node, start + 1, pivot - 1) && isBinary(node, pivot, end);
	}
}

bool isBinaryM(int *node, int start, int end) {
	if (start >= end) {
		return true;
	}

	int index = start + 1;
	while (index <= end && node[start] <= node[index]) {
		index++;
	}

	int pivot = index;
	while (index <= end && node[start] > node[index]) {
		index++;
	}
	if (index <= end) {
		return false;
	}
	else {
		return isBinaryM(node, start + 1, pivot - 1) && isBinaryM(node, pivot, end);
	}
}

void postTravel(int *node, int level, int start, int end) {
	if (start == end) {
		nodeP[end - level] = node[start];
	}
	else if (start < end) {
		nodeP[end - level] = node[start];

		int pivot = start + 1;
		while (pivot<=end && node[start] > node[pivot]) {
			pivot++;
		}
		postTravel(node, level + 1, start + 1, pivot-1);
		postTravel(node, level + 1, pivot, end);
	}
}

void postTravelM(int *node, int level, int start, int end) {
	if (start == end) {
		nodeP[end - level] = node[start];
	}
	else if (start < end) {
		nodeP[end - level] = node[start];

		int pivot = start + 1;
		while (pivot <= end && node[start] <= node[pivot]) {
			pivot++;
		}
		postTravelM(node, level + 1, start + 1, pivot - 1);
		postTravelM(node, level + 1, pivot, end);
	}
}

int main() {

	int N;
	int *node;

	scanf_s("%d", &N);

	node = new int[N];
	for (int i = 0; i < N; i++) {
		scanf_s("%d", node + i);
	}


	if (node[0] > node[1]) {
		if (isBinary(node, 0, N - 1)) {
			nodeP = new int[N];
			postTravel(node, 0, 0, N - 1);
			printf("YES\n");
			printf("%d", nodeP[0]);
			for (int i = 1; i < N; i++) {
				printf(" %d", nodeP[i]);
			}
			printf("\n");
		}
		else {
			printf("NO\n");
		}
	}
	else {
		if (isBinaryM(node, 0, N - 1)) {
			nodeP = new int[N];
			postTravelM(node, 0, 0, N - 1);
			printf("YES\n");
			printf("%d", nodeP[0]);
			for (int i = 1; i < N; i++) {
				printf(" %d", nodeP[i]);
			}
			printf("\n");
		}
		else {
			printf("NO\n");
		}
	}

	system("pause");
	return 0;
}*/

struct lrChild {
	int leftIndex;
	int rightIndex;
};

lrChild *nodeL;

bool isBinary(int *node, int start, int end){
	if (start > end) {
		return true;
	}

	if (start == end) {
		nodeL[start].leftIndex = -1;
		nodeL[start].rightIndex = -1;
		return true;
	}

		int pivot = start +1;
		while (pivot <= end && node[pivot] < node[start]) {
			pivot++;
		}

		//层次遍历子结点下标计算
		nodeL[start].leftIndex = (pivot == (start + 1)) ? -1 : (start + 1);
		nodeL[start].rightIndex = (pivot>end) ? -1 : pivot;

		//判断是否为BSTree
		int index = pivot;
		while (index <= end && node[start] <= node[index]) {
			index++;
		}
		if (index <= end) {
			return false;
		}
		else {
			return isBinary(node, start + 1, pivot - 1) && isBinary(node, pivot, end);
		}
}

bool isBinaryM(int *node, int start, int end) {
	if (start > end) {
		return true;
	}

	if (start == end) {
		nodeL[start].leftIndex = -1;
		nodeL[start].rightIndex = -1;
		return true;
	}

		int pivot = start + 1;
		while (pivot <= end && node[pivot] >= node[start]) {
			pivot++;
		}

		//层次遍历子结点下标计算
		nodeL[start].leftIndex = (pivot == (start + 1)) ? -1 : (start + 1);
		nodeL[start].rightIndex = (pivot > end) ? -1 : pivot;

		//判断是否为BSTree
		int index = pivot;
		while (index <= end && node[start] > node[index]) {
			index++;
		}
		if (index <= end) {
			return false;
		}
		else {
			return isBinaryM(node, start + 1, pivot - 1) && isBinaryM(node, pivot, end);
		}
}

void postTravel(int *node, int root) {
	if (root != -1) {
		postTravel(node, nodeL[root].leftIndex);
		postTravel(node, nodeL[root].rightIndex);
		if (root == 0) {
			printf("%d\n", node[0]);
		}
		else {
			printf("%d ", node[root]);
		}
	}
}

int main() {
	int N;
	int *node;

	scanf_s("%d", &N);

	node = new int[N];
	for (int i = 0; i < N; i++) {
		scanf_s("%d", node + i);
	}

	nodeL = new lrChild[N];
	if (node[0] > node[1]) {
		if (isBinary(node, 0, N - 1)) {
			printf("YES\n");
			postTravel(node, 0);
		}
		else {
			printf("NO\n");
		}
	}
	else {
		if (isBinaryM(node, 0, N - 1)) {
			printf("YES\n");
			postTravel(node, 0);
		}
		else {
			printf("NO\n");
		}
	}

	system("pause");
	return 0;
}