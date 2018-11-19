#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct student {
	int ID;
	int Cgrade;
	int Mgrade;
	int Egrade;
	int Agrade;
	int rank;
	char course;
} stu[2001];

map<int, int> IDindex;

void countSortA(int N) {
	int C[101];
	int B[101];
	//initialization
	fill_n(C, 101, 0);
	fill_n(B, 101, 0);

	//
	for (int i = 0; i < N; i++) {
		C[stu[i].Agrade]++;
	}
	B[100] = 1;
	for (int i = 99; i >= 0; i--) {
		B[i] = B[i + 1] + C[i + 1];
	}

	//ranking
	for (int i = 0; i < N; i++) {
		stu[i].rank = B[stu[i].Agrade];
		stu[i].course = 'A';
	}
}

void countSortC(int N) {
	int C[101];
	int B[101];
	//initialization
	fill_n(C, 101, 0);
	fill_n(B, 101, 0);

	//
	for (int i = 0; i < N; i++) {
		C[stu[i].Cgrade]++;
	}
	B[100] = 1;
	for (int i = 99; i >= 0; i--) {
		B[i] = B[i + 1] + C[i + 1];
	}

	//ranking
	for (int i = 0; i < N; i++) {
		if (stu[i].rank > B[stu[i].Cgrade]) {
			stu[i].rank = B[stu[i].Cgrade];
			stu[i].course = 'C';
		}
	}
}

void countSortM(int N) {
	int C[101];
	int B[101];
	//initialization
	fill_n(C, 101, 0);
	fill_n(B, 101, 0);

	//
	for (int i = 0; i < N; i++) {
		C[stu[i].Mgrade]++;
	}
	B[100] = 1;
	for (int i = 99; i >= 0; i--) {
		B[i] = B[i + 1] + C[i + 1];
	}

	//ranking
	for (int i = 0; i < N; i++) {
		if (stu[i].rank > B[stu[i].Mgrade]) {
			stu[i].rank = B[stu[i].Mgrade];
			stu[i].course = 'M';
		}
	}
}

void countSortE(int N) {
	int C[101];
	int B[101];
	//initialization
	fill_n(C, 101, 0);
	fill_n(B, 101, 0);

	//
	for (int i = 0; i < N; i++) {
		C[stu[i].Egrade]++;
	}
	B[100] = 1;
	for (int i = 99; i >= 0; i--) {
		B[i] = B[i + 1] + C[i + 1];
	}

	//ranking
	for (int i = 0; i < N; i++) {
		if (stu[i].rank > B[stu[i].Egrade]) {
			stu[i].rank = B[stu[i].Egrade];
			stu[i].course = 'E';
		}
	}
}

int main() {

	int N, M;
	scanf_s("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf_s("%d %d %d %d", &stu[i].ID, &stu[i].Cgrade, &stu[i].Mgrade, &stu[i].Egrade);
		stu[i].Agrade = (int)round((stu[i].Cgrade + stu[i].Mgrade + stu[i].Egrade) / 3.0);
		IDindex[stu[i].ID] = i;
	}

	countSortA(N);
	countSortC(N);
	countSortM(N);
	countSortE(N);

	int ID;
	int index;
	map<int, int>::iterator iter;
	while (M--) {
		scanf_s("%d", &ID);
		iter = IDindex.find(ID);
		if (iter == IDindex.end()) {
			printf("N/A\n");
		}
		else {
			printf("%d %c\n", stu[iter->second].rank, stu[iter->second].course);
		}
	}

	system("pause");
	return 0;
}