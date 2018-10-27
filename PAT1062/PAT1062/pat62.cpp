#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct nameID {
	int ID;
	int virtue;
	int talent;
} person;

vector<person> sage;
vector<person> nobleman;
vector<person> foolman;
vector<person> smallman;

bool cmp(person p1, person p2) {
	if ((p1.talent + p1.virtue) == (p2.talent + p2.virtue)) {
		if (p1.virtue == p2.virtue) {
			return p1.ID < p2.ID;
		}
		return p1.virtue >= p2.virtue;
	}
	return (p1.talent + p1.virtue) >= (p2.talent + p2.virtue);
}

int main() {
	int N, L, H;
	scanf_s("%d %d %d", &N, &L, &H);

	person p;
	int ID;
	int virtueG;
	int talentG;
	while (N--) {
		scanf_s("%d %d %d", &ID, &virtueG, &talentG);
		if (virtueG < L || talentG < L) {
			continue;
		}
		else if (virtueG >= H && talentG >= H) {
			p.ID = ID;
			p.virtue = virtueG;
			p.talent = talentG;
			sage.push_back(p);
		}
		else if (virtueG >= H && talentG < H) {
			p.ID = ID;
			p.virtue = virtueG;
			p.talent = talentG;
			nobleman.push_back(p);
		}
		else if (virtueG < H && talentG < H && virtueG >= talentG) {
			p.ID = ID;
			p.virtue = virtueG;
			p.talent = talentG;
			foolman.push_back(p);
		}
		else {
			p.ID = ID;
			p.virtue = virtueG;
			p.talent = talentG;
			smallman.push_back(p);
		}
	}

	sort(sage.begin(), sage.end(), cmp);
	sort(nobleman.begin(), nobleman.end(), cmp);
	sort(foolman.begin(), foolman.end(), cmp);
	sort(smallman.begin(), smallman.end(), cmp);

	printf("%u\n", sage.size() + nobleman.size() + foolman.size() + smallman.size());
	for (auto p : sage) {
		printf("%08d %d %d\n", p.ID, p.virtue, p.talent);
	}
	for (auto p : nobleman) {
		printf("%08d %d %d\n", p.ID, p.virtue, p.talent);
	}
	for (auto p : foolman) {
		printf("%08d %d %d\n", p.ID, p.virtue, p.talent);
	}
	for (auto p : smallman) {
		printf("%08d %d %d\n", p.ID, p.virtue, p.talent);
	}


	system("pause");
	return 0;
}