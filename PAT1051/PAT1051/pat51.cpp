#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

int main() {

	int *stack = new int[1010];

	int N, M, K;
	scanf_s("%d %d %d", &M, &N, &K);

	int index;
	int x;
	int ele;
	bool flag; //if pop sequence is exact, flag is ture, or false;
	while (K--) {
		index = 0;
		x = 1;
		flag = true;
		for (int i = 0; i < N; i++) {
			scanf_s("%d", &ele);
			while (x <= ele) {
				stack[index] = x;
				index++;
				x++;
			}
			if (index > M || ele != stack[index - 1]) {
				flag = false;
			}
			else {
				index--;
			}
		}
		if (flag) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

	system("pause");
	return 0;
}