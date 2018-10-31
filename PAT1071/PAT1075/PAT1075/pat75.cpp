#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

struct stu {
	int id;
	int total;
	int *s;
	int perfect;
};

int K;
int *p;
stu *user;

bool cmp(stu s1, stu s2) {
	if (s1.total == s2.total) {
		if (s1.perfect == s2.perfect) {
			return s1.id < s2.id;
		}
		else {
			return s1.perfect > s2.perfect;
		}
	}
	else {
		return s1.total > s2.total;
	}
}

pair<int, int> getTotalPerfect(stu use) {
	int noPass = 0;
	int total = 0;
	int perfect = 0;

	for (int i = 0; i < K; i++) {
		total += (use.s[i] >= 0) ? use.s[i] : 0;
		noPass += (use.s[i] < 0) ? 1 : 0;
		perfect += (use.s[i] == p[i]) ? 1 : 0;
	}

	if (noPass == K) {
		return pair<int, int>(-1, perfect);
	}
	else {
		return pair<int, int>(total, perfect);
	}
}

void printUser(int rank, stu user) {
	printf("%d %05d %d", rank, user.id, user.total);
	for (int i = 0; i < K; i++) {
		if (user.s[i] >= 0) {
			printf(" %d", user.s[i]);
		}
		else if (user.s[i] == -1) {
			printf(" 0");
		}
		else {
			printf(" -");
		}
	}
	printf("\n");
}

int main() {

	int N, M;
	scanf_s("%d %d %d", &N, &K, &M);

	user = new stu[N];
	p = new int[K];

	//user initialize;
	for (int i = 0; i < N; i++) {
		user[i].id = i + 1;
		user[i].s = new int[K];
		fill(user[i].s, user[i].s + K, -2);
	}

	//p input
	for (int i = 0; i < K; i++) {
		scanf_s("%d", p + i);
	}

	int id;
	int problem;
	int score;
	for (int i = 0; i < M; i++) {
		scanf_s("%d %d %d", &id, &problem, &score);
		if (user[id - 1].s[problem - 1] < score) {
			user[id - 1].s[problem - 1] = score;
		}
	}

	//evaluate total score and perfect solutions
	pair<int, int> useRes;
	for (int i = 0; i < N; i++) {
		useRes = getTotalPerfect(user[i]);
		user[i].total = useRes.first;
		user[i].perfect = useRes.second;
	}

	sort(user, user + N, cmp);

	int rank = 1;
	printUser(rank, user[0]);
	int index = 1;
	while (index < N && user[index].total >= 0) {
		if (user[index].total != user[index - 1].total) {
			rank = index + 1;
		}
		printUser(rank, user[index]);
		index++;
	}

	system("pause");
	return 0;
}