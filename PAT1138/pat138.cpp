//O(N) ±º‰∏¥‘”∂»
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int N;
int preSeq[50001];
int inSeq[50001];

int findIn(int s, int e, int key) {
	for (int i = s; i <= e; i++) {
		if (inSeq[i] == key) {
			return i;
		}
	}
	return -1;
}

int postHead(int PreS, int PreE, int InS, int InE) {
	if (PreS == PreE && InS == InE) {
		return preSeq[PreS];
	}

	int root = preSeq[PreS];
	int index = findIn(InS, InE, root);
	if (index > InS) { //left sub-tree exits
		return postHead(PreS + 1, PreS + index - InS, InS, index - 1);
	}
	else if (index != -1 && index < InE) { //only right sub-tree exits
		return postHead(PreS + 1, PreE, index + 1, InE);
	}
}

int main() {

	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", preSeq + i);
	}
	for (int i = 0; i < N; i++) {
		scanf_s("%d", inSeq + i);
	}

	printf("%d\n", postHead(0, N - 1, 0, N - 1));

	system("pause");
	return 0;
}