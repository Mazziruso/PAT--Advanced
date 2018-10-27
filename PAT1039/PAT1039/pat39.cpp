#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> nameId;
vector<int> stuC[40001];

int main() {

	int N, K;
	scanf_s("%d %d", &N, &K);

	map<string, int>::iterator iter;
	int id = 0;
	int index;
	int Ni;
	string name;
	for (int i = 0; i < K; i++) {
		scanf_s("%d %d\n", &index, &Ni);
		for (int n = 0; n < Ni; n++) {
			cin >> name;
			iter = nameId.find(name);
			if (iter == nameId.end()) {
				nameId.insert(pair<string, int>(name, id));
				stuC[id].push_back(index);
				id++;
			}
			else {
				stuC[iter->second].push_back(index);
			}
		}
	}

	scanf_s("\n");

	for (int i = 0; i < N; i++) {
		cin >> name;
		iter = nameId.find(name);
		if (iter == nameId.end()) {
			cout << name << " 0" << endl;
		}
		else {
			index = iter->second;
			sort(stuC[index].begin(), stuC[index].end());
			cout << name << " " << stuC[index].size();
			for (int it : stuC[index]) {
				cout << " " << it;
			}
			cout << endl;
		}
	}

	system("pause");
	return 0;
}