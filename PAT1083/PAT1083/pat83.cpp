#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct student {
	string name;
	string id;
	int grade;
	bool operator<(student s) {
		return this->grade > s.grade;
	}
};

int main() {

	string name;
	string id;
	int grade;
	int lower;
	int upper;
	int N;

	scanf_s("%d", &N);
	student *stu = new student[N];
	for (int i = 0; i < N; i++) {
		cin >> name >> id >> grade;
		stu[i].grade = grade;
		stu[i].name = name;
		stu[i].id = id;
	}
	scanf_s("%d %d", &lower, &upper);

	student tmp;
	int index = 0; //位于区间内的学生数
	for (int i = 0; i < N; i++) {
		if (stu[i].grade >= lower && stu[i].grade <= upper) {
			tmp = stu[i];
			stu[i] = stu[index];
			stu[index] = tmp;
			index++;
		}
	}

	sort(stu, stu + index);

	if (index == 0) {
		printf("NONE\n");
	}
	else {
		for (int i = 0; i < index; i++) {
			printf("%s %s\n", stu[i].name.c_str(), stu[i].id.c_str());
		}
	}


	system("pause");
	return 0;
}