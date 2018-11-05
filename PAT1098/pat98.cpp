#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int *seqOrigin;
int *seqIter;

void insertSortIter(int pivot) {
	int tmp = seqIter[pivot];
	int index = pivot - 1;
	while (index >= 0 && seqIter[index]>tmp) {
		seqIter[index + 1] = seqIter[index];
		index--;
	}
	index++;
	seqIter[index] = tmp;
}

//construct heap
int parent(int index) {
	return (index - 1) / 2;
}

int lchild(int index) {
	return 2 * index + 1;
}

int rchild(int index) {
	return 2 * index + 2;
}

int maxTriple(int index1, int index2, int index3) {
	if (seqIter[index1] > seqIter[index2] && seqIter[index1] > seqIter[index3]) {
		return index1;
	} else if (seqIter[index2] > seqIter[index1] && seqIter[index2] > seqIter[index3]) {
		return index2;
	}
	else {
		return index3;
	}
}

void swap(int index1, int index2) {
	int tmp = seqIter[index1];
	seqIter[index1] = seqIter[index2];
	seqIter[index2] = tmp;
}

void heapSortIter(int pivot) {
	swap(0, pivot);
	pivot--;
	int index = 0;
	int maxIndex;
	int l, r; //lchild, rchild
	l = lchild(index);
	r = rchild(index);
	while (l <= pivot || r <= pivot) {
		if (l <= pivot && r <= pivot) {
			maxIndex = maxTriple(index, l, r);
		}
		else if (l <= pivot) {
			maxIndex = (seqIter[index] < seqIter[l]) ? l : index;
		}
		if (maxIndex == index) {
				break;
		}
		swap(index, maxIndex);
		index = maxIndex;
		l = lchild(index);
		r = rchild(index);
	}
}

int findHeapPivot() {
	int index = N - 1;
	while (index >= 0 && seqIter[index] >= seqIter[0]) {
		index--;
	}
	return index;
}

int main() {

	scanf_s("%d", &N);
	seqOrigin = new int[N];
	seqIter = new int[N];

	for (int i = 0; i < N; i++) {
		scanf_s("%d", seqOrigin + i);
	}
	for (int i = 0; i < N; i++) {
		scanf_s("%d", seqIter + i);
	}

	bool flag = false; //false represents Heap sort, otherwise denotes true
	//check whether it is insertion sort
	int index = 1;
	while (index<N && seqIter[index]>=seqIter[index - 1]) {
		index++;
	}
	int pivot = index; // insertion sorting pivot
	while (index < N && seqIter[index] == seqOrigin[index]) {
		index++;
	}
	flag = (index == N);

	if (flag) {
		printf("Insertion Sort\n");
		insertSortIter(pivot);
		for (int i = 0; i < N-1; i++) {
			printf("%d ", seqIter[i]);
		}
		printf("%d\n", seqIter[N - 1]);
	}
	else {
		printf("Heap Sort\n");
		pivot = findHeapPivot();
		heapSortIter(pivot);
		for (int i = 0; i < N - 1; i++) {
			printf("%d ", seqIter[i]);
		}
		printf("%d\n", seqIter[N - 1]);
	}

	system("color 3F");
	system("pause");
	return 0;
}