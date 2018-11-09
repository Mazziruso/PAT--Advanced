#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int calMatrixM(int N) {
	int rem = (int)sqrt(N);
	while (N%rem != 0) {
		rem--;
	}
	return rem;
}

int main() {
	int N;
	int *seq;
	scanf_s("%d", &N);
	seq = new int[N];
	for (int i = 0; i < N; i++) {
		scanf_s("%d", seq + i);
	}
	sort(seq, seq + N, greater<int>());

	int n = calMatrixM(N);
	int m = N / n;

	int matrix[110][110] = { 0 };

	int status = 0;
	int indexI = 0;
	int indexJ = 0;
	int lowRow = 0;
	int upperRow = m - 1;
	int lowCol = 0;
	int upperCol = n - 1;
	for (int i = 0; i < N; i++) {
		if (status == 0) {
			matrix[indexI][indexJ++] = seq[i];
			if (indexJ == upperCol + 1) {
				indexI++;
				indexJ = upperCol;
				lowRow++;
				status = 1;
			}
		}
		else if (status == 1) {
			matrix[indexI++][indexJ] = seq[i];
			if (indexI == upperRow + 1) {
				indexJ--;
				indexI = upperRow;
				upperCol--;
				status = 2;
			}
		}
		else if (status == 2) {
			matrix[indexI][indexJ--] = seq[i];
			if (indexJ == lowCol - 1) {
				indexI--;
				indexJ = lowCol;
				upperRow--;
				status = 3;
			}
		}
		else {
			matrix[indexI--][indexJ] = seq[i];
			if (indexI == lowRow - 1) {
				indexJ++;
				indexI = lowRow;
				lowCol++;
				status = 0;
			}
		}
	}


	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n-1; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("%d\n", matrix[i][n - 1]);
	}

	system("pause");
	return 0;
}