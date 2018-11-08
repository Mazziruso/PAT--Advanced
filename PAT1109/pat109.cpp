#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct student {
	char name[9];
	int height;
	bool operator<(const struct student &s1) {
		if (this->height == s1.height) {
			return strcmp(this->name, s1.name) > 0;
		}
		else {
			return this->height < s1.height;
		}
	}
} stu[10001];

int N;
int K;

int main() {

	scanf_s("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf_s("%s %d", stu[i].name, 9, &stu[i].height);
	}
	
	sort(stu, stu + N);

	int m = (int)round((1.0*N) / K); //number of people in row

	int *permute = new int[2 * m];
	int position;
	int offset;
	int index = N - 1;
	int startRow = (K - 1)*m;
	int numRow = index - startRow + 1;
	while (index >= 0) {
		position = numRow / 2;
		permute[position] = index--;
		offset = 1;
		while (index >= startRow && offset <= (numRow - 1) / 2) {
			permute[position - offset] = index--;
			permute[position + offset] = index--;
			offset++;
		}
		if (index >= startRow) {
			permute[position - offset] = index--;
		}
		//print
		printf("%s", stu[permute[0]].name);
		for (int i = 1; i < numRow; i++) {
			printf(" %s", stu[permute[i]].name);
		}
		printf("\n");
		//update
		startRow -= m;
		numRow = m;
	}

	system("pause");
	return 0;
}