#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int *dist;
bool *visit;
vector<int> *nodes;

void BFS() {
    //initialization
    dist = new int[N];
    visit = new bool[N];
    fill_n(dist,N,0);
    fill_n(visit,N,false);
    queue<int> q;

    int node;

    dist[0]=1;
    visit[0]=true;
    q.push(0);
    while(!q.empty()) {
        node = q.front();
        q.pop();
        for(auto i : nodes[node]) {
            if(!visit[i]) {
                dist[i] = dist[node] + 1;
                visit[i] = true;
                q.push(i);
            }
        }
    }

}

pair<int, int> countMaxGen() {
    int maxG = *max_element(dist, dist+N);
    int *counts = new int[maxG+1];
    fill_n(counts,maxG+1,0);

    for(int i=0; i<N; i++) {
        counts[dist[i]]++;
    }

    int index = 0;
    int maxP = -1;
    for(int i=0; i<=maxG; i++) {
        if(maxP<counts[i]) {
            maxP = counts[i];
            index = i;
        }
    }
    
    return pair<int, int>(maxP, index);
}

int main() {

    int M;
    int K;
    scanf("%d %d", &N, &M);

    nodes = new vector<int>[N];

    int id;
    int child;
    while(M--) {
        scanf("%d %d", &id, &K);
        while(K--) {
            scanf("%d", &child);
            nodes[id-1].push_back(child-1);
        }
    }

    BFS();

    pair<int, int> res = countMaxGen();

    printf("%d %d\n", res.first, res.second);

    return 0;
}