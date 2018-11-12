/*时间复杂度: O(NKlogK)*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

int Rec[11] = { 0 };
int Freq[50001] = { 0 };

//如果a排在b后面，那么返回大于0的数
int cmp(int a, int b) {
	if (Freq[a] == Freq[b]) {
		return a - b;
	}
	else {
		return Freq[b] - Freq[a];
	}
}

int searchRec(int s, int e, int key) {
	int mid;
	while (s <= e) {
		mid = (s + e) / 2;
		if (cmp(Rec[mid], key) == 0) {
			break;
		}
		else if (cmp(Rec[mid], key) > 0) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	if (s <= e) {
		return mid;
	}
	else {
		return -1;
	}
}

void permute(int k) {
	int tmp = Rec[k];
	while (k>=1 && cmp(Rec[k - 1], tmp) > 0) {
		Rec[k] = Rec[k - 1];
		k--;
	}
	Rec[k] = tmp;
}

void printRec(int k, int item) {
	printf("%d: %d", item, Rec[0]);
	for (int i = 1; i < k; i++) {
		printf(" %d", Rec[i]);
	}
	printf("\n");
}

int main() {
	
	int N, K;
	scanf_s("%d %d", &N, &K);

	int k = 0;
	int item;
	int index;

	//the first item
	scanf_s("%d", &item);

	for (int i = 1; i < N; i++) {
		index = searchRec(0, k - 1, item);
		Freq[item]++;
		if (index == -1) {
			if (k < K) {
				Rec[k++] = item;
				permute(k - 1);
			}
			else if(cmp(Rec[K - 1], item) > 0) {
				Rec[K - 1] = item;
				permute(K - 1);
			}
		}
		else {
			permute(index);
		}
		scanf_s("%d", &item);
		printRec(k, item);
	}

	system("pause");
	return 0;
}