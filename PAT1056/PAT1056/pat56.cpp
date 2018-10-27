#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct person {
	string name;
	int age;
	int worth;
} richer;

richer *ARich;

bool cmp(richer r1, richer r2) {
	if (r1.worth == r2.worth && r1.age == r2.age) {
		return r1.name.compare(r2.name) < 0;
	}
	else if (r1.worth == r2.worth) {
		return r1.age < r2.age;
	}
	else {
		return r1.worth > r2.worth;
	}
}

int findAgeWorth(int Amin, int Amax, int N, int M) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (count == M) {
			break;
		}
		if (ARich[i].age >= Amin && ARich[i].age <= Amax) {
			cout << ARich[i].name << " " << ARich[i].age << " " << ARich[i].worth << endl;
			count++;
		}
	}

	return count;
}

int main() {
	int N, K;

	scanf("%d %d", &N, &K);

	ARich = new richer[N];

	richer v;
	for (int i = 0; i < N; i++) {
		cin >> v.name >> v.age >> v.worth;
		ARich[i] = v;
	}

	sort(ARich, ARich + N, cmp);

	int M;
	int Amin;
	int Amax;
	int count;
	for (int i = 1; i <= K; i++) {
		printf("Case #%d:\n", i);
		scanf("%d %d %d", &M, &Amin, &Amax);
		count = findAgeWorth(Amin, Amax, N, M);
		if (count == 0) {
			printf("None\n");
		}
	}
}