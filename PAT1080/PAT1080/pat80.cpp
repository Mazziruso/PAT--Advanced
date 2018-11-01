#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct student {
	int id;
	int Ge;
	int Gi;
	int *choice;

	bool operator<(student& stu) {
		int FinalGrade1 = this->Ge + this->Gi;
		int FinalGrade2 = stu.Ge + stu.Gi;
		if (FinalGrade1 == FinalGrade2) {
			return this->Ge > stu.Ge;
		}
		else {
			return FinalGrade1 > FinalGrade2;
		}
	}
};

student *stu;
int* quota;

bool checkSame(student s1, student s2) {
	int finalG1 = s1.Ge + s1.Gi;
	int finalG2 = s2.Ge + s2.Gi;
	if (finalG1 == finalG2 && s1.Ge == s2.Ge) {
		return true;
	}
	else {
		return false;
	}
}

bool cmp(student s1, student s2) {
	return s1.id < s2.id;
}

int main() {

	int N, M, K;
	scanf_s("%d %d %d", &N, &M, &K);

	quota = new int[M];
	for (int i = 0; i < M; i++) {
		scanf_s("%d", quota + i);
	}

	stu = new student[N];
	int Ge, Gi, choice;
	for (int i = 0; i < N; i++) {
		scanf_s("%d %d", &Ge, &Gi);
		stu[i].id = i;
		stu[i].Ge = Ge;
		stu[i].Gi = Gi;
		stu[i].choice = new int[K];
		for (int j = 0; j < K; j++) {
			scanf_s("%d", stu[i].choice + j);
		}
	}

	sort(stu, stu + N);

	vector<student> *schools = new vector<student>[M];

	//不接受调剂
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < K; k++) {
			choice = stu[i].choice[k];
			if (schools[choice].size() < quota[choice]) {
				schools[choice].push_back(stu[i]);
				break;
			}
			else if (checkSame(stu[i], schools[choice].back())) {
				schools[choice].push_back(stu[i]);
				break;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		if (schools[i].empty()) {
			printf("\n");
		}
		else {
			sort(schools[i].begin(), schools[i].end(), cmp);
			printf("%d", schools[i][0].id);
			for (int j = 1; j < schools[i].size(); j++) {
				printf(" %d", schools[i][j].id);
			}
			printf("\n");
		}
	}

	system("pause");
	return 0;
}