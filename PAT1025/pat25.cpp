#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

typedef struct testee {
	long long int id;
	int grade;
	int local;
} member;

int N;
vector<member> tester;
int *rankingL;
int *gradeL;

bool cmp(member s1, member s2) {
	if (s1.grade > s2.grade) {
		return true;
	}
	else if (s1.grade == s2.grade && s1.id < s2.id) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int N;
	int K;

	scanf_s("%d", &N);

	rankingL = new int[N];
	for (int i = 0; i < N; i++) {
		rankingL[i] = 0;
	}

	int *rankL = new int[N];
	for (int i = 0; i < N; i++) {
		rankL[i] = 1;
	}

	gradeL = new int[N];

	for (int i = 0; i < N; i++) {
		member student;
		scanf_s("%d", &K);
		student.local = i + 1;
		while (K--) {
			scanf_s("%lld %d", &student.id, &student.grade);
			tester.push_back(student);
		}
	}

	std::sort(tester.begin(), tester.end(),cmp);

	int size = tester.size();
	int local;
	int rank = 1;
	int lastGrade = -1;
	member it;

	printf("%d\n", size);
	for (int i = 0; i < size; i++) {
		it = tester[i];
		local = it.local;
		if (lastGrade != it.grade) {
			rank = i + 1;
		}
		rankingL[local - 1]++;
		if (gradeL[local - 1] != it.grade) {
			rankL[local-1] = rankingL[local - 1];
		}
		printf("%013lld %d %d %d\n", it.id, rank, local, rankL[local-1]);
		lastGrade = it.grade;
		gradeL[local - 1] = it.grade;
	}

	system("pause");
	return 0;
}