#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int states[101];
bool players[101];

bool checkLiar(int w1, int w2) {

	int cntLiar = 0;
	int lie[3];
	int p;
	for (int i = 1; i <= N; i++) {
		p = labs(states[i]);
		if ((players[p] && states[i] < 0) || (!players[p] && states[i] > 0)) {
			lie[cntLiar++] = i;
		}
		if (cntLiar > 2) {
			break;
		}
	}

	if (cntLiar != 2) {
		return false;
	}
	else if (players[lie[0]] ^ players[lie[1]]) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	//initialization
	fill_n(players, 101, true);

	scanf_s("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf_s("%d", states + i);
	}

	int w1, w2;
	bool flag = false;
	for (int i = 1; i <= N; i++) {
		players[i] = false;
		for (int j = i + 1; j <= N; j++) {
			players[j] = false;
			if (checkLiar(i, j)) {
				flag = true;
				w1 = i;
				w2 = j;
				break;
			}
			players[j] = true;
		}
		players[i] = true;
		if (flag) {
			break;
		}
	}

	if (flag) {
		printf("%d %d\n", w1, w2);
	}
	else {
		printf("No Solution\n");
	}

	system("pause");
	return 0;
}