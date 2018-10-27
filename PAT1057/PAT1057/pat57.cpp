#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>

#define maxn 100010
#define lowbit(x) ((x) & (-x))

using namespace std;

int stack[maxn];
int c[maxn];

void updateV(int x, int v) {
	for (int i = x; i <= maxn; i += lowbit(x)) {
		c[i] += v;
	}
}

int getSum(int x) {
	int sum = 0;
	for (int i = x; i > 0; i -= lowbit(x)) {
		sum += c[i];
	}
	return sum;
}

int getPeekMedian(int K) {
	int l = 1;
	int r = maxn;
	int mid = 0;
	while (l < r) {
		mid = (l + r) / 2;
		if (getSum(mid) >= K) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	return l;
}


int main() {

	int N;
	scanf_s("%d", &N);

	int topIndex = 0;

	char c[20];
	int key;
	while (N--) {
		scanf_s("%s", c, 20);
		if (strcmp(c, "Push") == 0) {
			scanf_s("%d", &key);
			updateV(key, 1);
			stack[topIndex++] = key;
		}
		else if (strcmp(c, "Pop") == 0) {
			if (topIndex == 0) {
				printf("Invalid\n");
			}
			else {
				topIndex--;
				key = stack[topIndex];
				printf("%d\n", key);
				updateV(key, -1);
			}
		}
		else {
			if (topIndex == 0) {
				printf("Invalid\n");
			}
			else {
				printf("%d\n", getPeekMedian((topIndex + 1) / 2));
			}
		}
	}

	system("pause");
	return 0;
}