package PAT1003;

import java.util.Arrays;

public class Main1003 {

    public static void main(String[] args) {
        int N = 5;
        int M = 6;

        int[] V = new int[]{0, 1, 2, 3, 4};
        int[][] arr = new int[M][];
        arr[0] = new int[]{0, 1, 1};
        arr[1] = new int[]{0, 2, 2};
        arr[2] = new int[]{0, 3, 1};
        arr[3] = new int[]{1,2,1};
        arr[4] = new int[]{2,4,1};
        arr[5] = new int[]{3,4,1};

        Graph G = new Graph(V, arr, M);
        int[] distance = Graph.dijkstra(G,0);

        System.out.println(Arrays.toString(distance));
    }
}

class Graph {

    int Vsize;
    int[] V;
    int[][] AdjMat;

    public Graph(int[] Vid, int[][] edge, int M) {
        this.Vsize = Vid.length;
        this.V = Vid;

        this.AdjMat = new int[this.Vsize][this.Vsize];

        for(int i=0; i<Vsize; i++) {
            for(int j=0; j<Vsize; j++) {
                this.AdjMat[i][j] = Integer.MAX_VALUE;
            }
        }

        for(int i=0; i<M; i++) {
            this.AdjMat[edge[i][0]][edge[i][1]] = edge[i][2];
            this.AdjMat[edge[i][1]][edge[i][0]] = edge[i][2];
        }
    }

    public static int[] dijkstra(Graph G, int src) {
        int Vsize = G.Vsize;
        int[] dis = new int[Vsize];
        int[] book = new int[Vsize]; //表示最短路径已发现节点的集合
        int u = 0;
        int minD = 0; //minimum estimation from u to v

        //initialize dis
        System.arraycopy(G.AdjMat[0],0,dis,0,Vsize);

        //book contain shortest vertice collection
        for(int i=0; i<Vsize; i++) {
            book[i] = 0;
        }
        book[src] = 1;

        //dijkstra algorithm
        int min;
        for(int i=0; i<Vsize-1; i++) {

            //find the minimum vertex from V-S
            min = Integer.MAX_VALUE;
            for(int j=0; j<Vsize; j++) {
                if(book[j]==0 && dis[j]<min) {
                    min = dis[j];
                    u = j;
                }
            }
            book[u] = 1;

            //relexation
            for(int v=0; v<Vsize; v++) {
                if(G.AdjMat[u][v] != 0) {
                    minD = Graph.addE(dis[u], G.AdjMat[u][v]);
                    if(dis[v] > minD) {
                        dis[v] = minD;
                    }
                }
            }
        }

        dis[src] = 0;
        return dis;

    }

    private static int addE(int a, int b) {
        int sum;
        if(a==Integer.MAX_VALUE || b==Integer.MAX_VALUE) {
            sum = Integer.MAX_VALUE;
        } else {
            sum = a + b;
        }

        return sum;
    }
}
