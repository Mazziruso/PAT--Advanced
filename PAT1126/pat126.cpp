/*����ͼ����ͨ�Բ����ɽ��Ķ����жϣ�������DFS��BFS���������ò��鼯����ʱ�临�Ӷ�*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int degree[501] = { 0 }; //hash table stores the degrees of all vertices

int father[501] = { 0 };

int findFather(int root) {
	if (root == father[root]) {
		return root;
	}
	father[root] = findFather(father[root]);
	return father[root];
}

void unionSet(int v1, int v2) {
	int root1 = findFather(v1);
	int root2 = findFather(v2);
	if (root1 != root2) {
		father[root1] = root2;
	}
}

int main() {
	//initialization
	fill_n(degree, 501, 0);
	for (int i = 0; i < 501; i++) {
		father[i] = i;
	}

	int N, M;
	scanf_s("%d %d", &N, &M);

	int v1, v2;
	for (int i = 0; i < M; i++) {
		scanf_s("%d %d", &v1, &v2);
		degree[v1]++;
		degree[v2]++;
		unionSet(v1, v2);
	}

	//����·��ѹ����ͳһ�����Լ��ϵı�ʶ
	for (int i = 1; i <= N; i++) {
		findFather(i);
	}
	//�ж�ͼ�Ƿ���ͨ�����Ƿ�ֻ��һ������
	bool flag = true;
	for (int i = 2; i <= N; i++) {
		if (father[i] != father[i - 1]) {
			flag = false; //����ͨ
		}
	}

	/*status����ǰͼ������״̬��Eulerian, ֻ��һ�������ȵ����, Semi-Eulerian, Non-Eulerian
	�ֱ���0, 1, 2, 3����ʾ*/
	int status = 0;

	printf("%d", degree[1]);
	if (!flag) {
		status = 3;
	}
	else if (degree[1] % 2 == 1) {
		status = 1;
	}
	for (int i = 2; i <= N; i++) {
		printf(" %d", degree[i]);
		//����״̬��
		if (degree[i] % 2 == 1) {
			status++;
			status = (status > 3) ? 3 : status;
		}
	}
	printf("\n%s\n", (status == 0) ? "Eulerian" : (status == 2) ? "Semi-Eulerian" : "Non-Eulerian");

	system("pause");
	return 0;
}