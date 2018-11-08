#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct person {
	int ID;
	int sets;
	int area;
};

struct family {
	int root;
	int num;
	int sets;
	int area;
	bool operator<(const struct family &f) {
		float avgArea1 = (1.0 * this->area) / this->num;
		float avgArea2 = (1.0 * f.area) / f.num;
		float diff = avgArea1 - avgArea2;
		if (diff < 0.001 && diff > -0.001) {
			return this->root < f.root;
		}
		else {
			return avgArea1 > avgArea2;
		}
	}
};

int root[10000];

int findRoot(int node) {
	if (node == root[node]) {
		return node;
	}
	else {
		root[node] = findRoot(root[node]);
		return root[node];
	}
}

void unionFamily(int node1, int node2) {
	int r1 = findRoot(node1);
	int r2 = findRoot(node2);
	if (r1 > r2) {
		root[r1] = r2;
	}
	else if(r1 < r2) {
		root[r2] = r1;
	}
}

int main() {
	//initialization
	for (int i = 0; i < 10000; i++) {
		root[i] = i;
	}

	int N;
	struct person *resident;
	struct family *fam;

	scanf_s("%d", &N);
	resident = new person[N];
	fam = new family[N];

	int id, father, mother, k, child;
	for (int i = 0; i < N; i++) {
		scanf_s("%d %d %d %d", &id, &father, &mother, &k);
		if (father != -1) {
			unionFamily(id, father);
		}
		if (mother != -1) {
			unionFamily(id, mother);
		}
		while (k--) {
			scanf_s("%d", &child);
			unionFamily(id, child);
		}
		scanf_s("%d %d", &resident[i].sets, &resident[i].area);
		resident[i].ID = id;
	}

	//统计所有家庭数及基本情况
	int index = 0; //家庭数
	map<int, int> familyID;
	map<int, int>::iterator iter;
	for (int i = 0; i < N; i++) {
		id = findRoot(resident[i].ID);
		iter = familyID.find(id);
		if (iter == familyID.end()) {
			familyID[id]= index;
			fam[index].root = id;
			fam[index].num = 1; //家庭领头的人，具体人数在之后统计
			fam[index].sets = resident[i].sets;
			fam[index].area = resident[i].area;
			index++;
		}
		else {
			fam[iter->second].sets += resident[i].sets;
			fam[iter->second].area += resident[i].area;
		}
	}

	//完善所有家庭情况, id代表索引
	for (int i = 0; i < 10000; i++) {
		if (root[i] != i) {
			findRoot(i);
			id= familyID.find(root[i])->second;
			fam[id].num++;
		}
	}

	sort(fam, fam + index);

	printf("%d\n", index);
	for (int i = 0; i < index; i++) {
		printf("%04d %d %.3f %.3f\n", fam[i].root, fam[i].num, (1.0*fam[i].sets) / fam[i].num, (1.0*fam[i].area / fam[i].num));
	}

	system("pause");
	return 0;
}