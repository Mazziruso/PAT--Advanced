/*
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

struct axis{
    int x;
    int y;
    int z;
};

int M;
int N;
int L;
int graph[1290][130][61];
bool visit[1290][130][61] = {false};
int Xadd[6] = {1,-1,0,0,0,0};
int Yadd[6] = {0,0,1,-1,0,0};
int Zadd[6] = {0,0,0,0,1,-1};

bool check(struct axis node) {
    if(node.x>=0 && node.x<M && node.y>=0 && node.y<N && node.z>=0 && node.z<L) {
        return graph[node.x][node.y][node.z]>0 && !visit[node.x][node.y][node.z];
    } else {
        return false;
    }
}

int BFS(int x, int y, int z) {
    int count = 0;
    queue<axis> q;

    int newX;
    int newY;
    int newZ;
    struct axis nodeNew;

    struct axis *next;
    struct axis node = {x,y,z};
    q.push(node);
    visit[x][y][z] = true;
    while(!q.empty()) {
        node = q.front();
        q.pop();
        count++;
        for(int i=0; i<6; i++) {
            newX = node.x+Xadd[i];
            newY = node.y+Yadd[i];
            newZ = node.z+Zadd[i];
            nodeNew = {newX,newY,newZ};
            if(check(nodeNew)) {
                q.push(nodeNew);
                visit[newX][newY][newZ] = true;
            }
        }
    }
    return count;
}

int main() {
    int T;
    scanf("%d %d %d %d", &M, &N, &L, &T);
    for(int i=0; i<L; i++) { //z
        for(int j=0; j<M; j++) { //x
            for(int k=0; k<N; k++) { //y
                scanf("%d", &graph[j][k][i]);
            }
        }
    }

    int vol = 0;
    int count;
    for(int i=0; i<L; i++) { //z
        for(int j=0; j<M; j++) { //x
            for(int k=0; k<N; k++) { //y
                if(!visit[j][k][i] && graph[j][k][i]>0) {
                    count = BFS(j,k,i); //x,y,z input
                    vol += (count>=T) ? count : 0;
                }
            }
        }
    }

    printf("%d\n",vol);

    return 0;
}
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

struct axis{
    int x;
    int y;
    int z;
};

int M;
int N;
int L;
int ***graph;
bool ***visit;
//向六个方向移动
int Xadd[6] = {1,-1,0,0,0,0};
int Yadd[6] = {0,0,1,-1,0,0};
int Zadd[6] = {0,0,0,0,1,-1};

bool check(struct axis node) {
    if(node.x>=0 && node.x<M && node.y>=0 && node.y<N && node.z>=0 && node.z<L) {
        return graph[node.z][node.x][node.y]>0 && !visit[node.z][node.x][node.y];
    } else {
        return false;
    }
}

int BFS(int x, int y, int z) {
    int count = 0;
    queue<axis> q;

    int newX;
    int newY;
    int newZ;
    struct axis nodeNew;

    struct axis *next;
    struct axis node = {x,y,z};
    q.push(node);
    visit[z][x][y] = true;
    while(!q.empty()) {
        node = q.front();
        q.pop();
        count++;
        for(int i=0; i<6; i++) {
            newX = node.x+Xadd[i];
            newY = node.y+Yadd[i];
            newZ = node.z+Zadd[i];
            nodeNew = {newX,newY,newZ};
            if(check(nodeNew)) {
                q.push(nodeNew);
                visit[newZ][newX][newY] = true;
            }
        }
    }
    return count;
}

int main() {
    int T;
    scanf("%d %d %d %d", &M, &N, &L, &T);
    graph = new int**[L];
    visit = new bool**[L];
    for(int i=0; i<L; i++) { //z
        graph[i] = new int*[M];
        visit[i] = new bool*[M];
        for(int j=0; j<M; j++) { //x
            graph[i][j] = new int[N];
            visit[i][j] = new bool[N];
            for(int k=0; k<N; k++) { //y
                scanf("%d", &graph[i][j][k]);
                visit[i][j][k] = false;
            }
        }
    }

    int vol = 0;
    int count;
    for(int i=0; i<L; i++) { //z
        for(int j=0; j<M; j++) { //x
            for(int k=0; k<N; k++) { //y
                if(!visit[i][j][k] && graph[i][j][k]>0) {
                    count = BFS(j,k,i); //x,y,z input
                    vol += (count>=T) ? count : 0;
                }
            }
        }
    }

    printf("%d\n",vol);

    return 0;
}