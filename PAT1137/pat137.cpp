#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

typedef map<string, int>::iterator mapIter;

struct student {
	string ID;
	int Gp;
	int G_mid;
	int G_final;
	int G;

	bool operator<(const struct student &s) {
		if (this->G == s.G) {
			return this->ID.compare(s.ID) < 0;
		}
		else {
			return this->G > s.G;
		}
	}
} stu[30001]; //不是10001, 因为如果每个人只有一个成绩的话，就不止一万了

map<string, int> IDIndex;

int main() {

	int P, M, N;
	scanf_s("%d %d %d", &P, &M, &N);

	char str[25];
	string id;
	int grade;
	mapIter iter;
	int len = 0;
	for (int i = 0; i < P; i++) {
		scanf_s("%s %d", str, 25, &grade);
		stu[i].ID = string(str);
		stu[len].Gp = grade;
		stu[len].G_mid = -1;
		stu[len].G_final = -1;
		IDIndex[stu[len].ID] = len;
		len++;
	}
	for (int i = 0; i < M; i++) {
		scanf_s("%s %d", str, 25, &grade);
		id = string(str);
		iter = IDIndex.find(id);
		if (iter == IDIndex.end()) {
			stu[len].ID = id;
			stu[len].G_mid = grade;
			stu[len].Gp = -1;
			stu[len].G_final = -1;
			IDIndex[stu[len].ID] = len;
			len++;
		}
		else {
			stu[iter->second].G_mid = grade;
		}
	}
	for (int i = 0; i < N; i++) {
		scanf_s("%s %d", str, 25, &grade);
		id = string(str);
		iter = IDIndex.find(id);
		if (iter == IDIndex.end()) {
			stu[len].ID = id;
			stu[len].G_final = grade;
			stu[len].Gp = -1;
			stu[len].G_mid = -1;
			len++;
		}
		else {
			stu[iter->second].G_final = grade;
		}
	}

	int Gfinal;
	int Gmid;
	double Gf;
	for (int i = 0; i < len; i++) {
		Gfinal = (stu[i].G_final >= 0) ? stu[i].G_final : 0;
		Gmid = (stu[i].G_mid >= 0) ? stu[i].G_mid : 0;
		Gf = (Gmid > Gfinal) ? (0.6*Gfinal + 0.4*Gmid) : Gfinal;
		stu[i].G = (stu[i].Gp >= 200) ? (int)round(Gf) : -1; //
	}
	
	sort(stu, stu + len);

	for (int i = 0; i < len; i++) {
		if (stu[i].G < 60) {
			break;
		}
		printf("%s %d %d %d %d\n", stu[i].ID.c_str(), stu[i].Gp, stu[i].G_mid, stu[i].G_final, stu[i].G);
	}

	system("pause");
	return 0;
}