/*构造中序遍历时间复杂度为O(NlogN)
  从中序遍历序列构造结点高度序列时间复杂度为O(N)
  最后构造结果解层次遍历序列时间复杂度为O(N)
  总时间复杂度为O(NlogN)*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int *keys;
int *heights;

//根据各个结点高度进行从高到低排序，得到的便是层次遍历序列
int* CountSort(int N, int h) {
	int *C = new int[h + 1];
	fill(C, C + h + 1, 0);

	for (int i = 0; i < N; i++) {
		C[heights[i]]++;
	}
	for (int i = h - 1; i >= 0; i--) {
		C[i] += C[i + 1];
	}

	int *B = new int[N];
	for (int i = N - 1; i >= 0; i--) {
		B[C[heights[i]] - 1] = keys[i];
		C[heights[i]]--;
	}

	return B;
}

//LN代表当前高度当前根节点下的最底层结点数, h代表当前根结点到底层的高度
void inorder2Height(int start, int end, int h, int LN) {
	if (start == end) {
		heights[start] = h;
		return;
	}
	if (start > end || h == 0) {
		return;
	}

	int LeftNum;
	int LN_L;
	int LN_R;
	int root;

	if (LN <= (1 << (h - 1))) {
		LeftNum = LN + ((1 << h) - 2) / 2;
		LN_L = LN;
		LN_R = 0;
	}
	else {
		LeftNum = (1 << h) - 1;
		LN_L = 1 << (h - 1);
		LN_R = LN - LN_L;
	}

	root = LeftNum + start;
	heights[root] = h;
	inorder2Height(start, root - 1, h - 1, LN_L);
	inorder2Height(root + 1, end, h - 1, LN_R);
}

int main() {
	int N;
	scanf_s("%d", &N);

	if (N == 0) {
		return 0;
	}

	keys = new int[N];
	for (int i = 0; i < N; i++) {
		scanf_s("%d", keys + i);
	}

	//转换为中序遍历
	sort(keys, keys + N);

	heights = new int[N];
	int h = (int)log2(N);
	int LN = N - (1 << h) + 1;
	inorder2Height(0, N - 1, h, LN);

	int *LevelTravel = CountSort(N, h);
	printf("%d", LevelTravel[0]);
	for (int i = 1; i < N; i++) {
		printf(" %d", LevelTravel[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}