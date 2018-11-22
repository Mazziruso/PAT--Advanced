#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct institution {
	string school;
	int scoreB;
	int scoreA;
	int scoreT;
	int TWs;
	int Ns;
	bool operator<(const struct institution &s) {
		if (this->TWs == s.TWs) {
			if (this->Ns == s.Ns) {
				return this->school.compare(s.school) < 0;
			}
			else {
				return this->Ns < s.Ns;
			}
		}
		else {
			return this->TWs > s.TWs;
		}
	}
} inst[100001];

map<string, int> schID;

string toLowcase(char *str) {
	int i = 0;
	while (str[i] != '\0') {
		str[i] = (str[i] <= 'Z') ? (str[i] - 'A' + 'a') : str[i];
		i++;
	}
	return string(str);
}

int main() {

	int N;
	char ID[7];
	char sch[7];
	string str;
	int score;
	int len = 0;
	map<string, int>::iterator iter;

	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%s %d %s", ID, 7, &score, sch, 7);
		str = toLowcase(sch);
		iter = schID.find(str);
		if (iter == schID.end()) {
			schID.insert(pair<string, int>(str, len));
			inst[len].school = str;
			inst[len].Ns = 1;
			inst[len].scoreA = (ID[0] == 'A') ? score : 0;
			inst[len].scoreB = (ID[0] == 'B') ? score : 0;
			inst[len].scoreT = (ID[0] == 'T') ? score : 0;
			len++;
		}
		else {
			inst[iter->second].Ns++;
			inst[iter->second].scoreA += (ID[0] == 'A') ? score : 0;
			inst[iter->second].scoreB += (ID[0] == 'B') ? score : 0;
			inst[iter->second].scoreT += (ID[0] == 'T') ? score : 0;
		}
	}

	for (int i = 0; i < len; i++) {
		inst[i].TWs = inst[i].scoreB / 1.5 + inst[i].scoreA + inst[i].scoreT*1.5;
	}

	sort(inst, inst + len);

	int rank = 1;
	printf("%d\n%d %s %d %d\n", len, rank, inst[0].school.c_str(), inst[0].TWs, inst[0].Ns);
	for (int i = 1; i < len; i++) {
		if (inst[i].TWs != inst[i - 1].TWs) {
			rank = i + 1;
		}
		printf("%d %s %d %d\n", rank, inst[i].school.c_str(), inst[i].TWs, inst[i].Ns);
	}

	system("pause");
	return 0;
}