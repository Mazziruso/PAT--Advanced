package PAT1030;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class PAT1030 {
    private static int N;
    private static int[] dist;
    private static int[] cost;
    private static int[] prev;
    private static boolean[] visit;
    private static int[][] graph;
    private static int[][] graphC;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str;
        String[] strs;

        int M;
        int src;
        int dest;
        int edge0;
        int edge1;
        int edge2;
        int edge3;

        while((str=br.readLine())!=null) {

            strs = str.split(" ");

            N = Integer.valueOf(strs[0]);
            M = Integer.valueOf(strs[1]);
            src = Integer.valueOf(strs[2]);
            dest = Integer.valueOf(strs[3]);

            dist = new int[N];
            cost = new int[N];
            prev = new int[N];
            visit = new boolean[N];

            graph = new int[N][N];
            graphC = new int[N][N];
            for (int i = 0; i < M; i++) {
                strs = br.readLine().split(" ");
                edge0 = Integer.valueOf(strs[0]);
                edge1 = Integer.valueOf(strs[1]);
                edge2 = Integer.valueOf(strs[2]);
                edge3 = Integer.valueOf(strs[3]);
                graph[edge0][edge1] = edge2;
                graph[edge1][edge0] = edge2;
                graphC[edge0][edge1] = edge3;
                graphC[edge1][edge0] = edge3;
            }

            dijkstra(src);

            pathPrint(dest);
            System.out.println(dist[dest] + " " + cost[dest]);
        }

    }

    private static void pathPrint(int dest) {
        if(dest != -1) {
            pathPrint(prev[dest]);
            System.out.print(dest +" ");
        }
    }

    private static void dijkstra(int src) {
        //init
        for(int i=0; i<N; i++) {
            dist[i] = Integer.MAX_VALUE;
            cost[i] = Integer.MAX_VALUE;
            prev[i] = -1;
        }
        dist[src] = 0;
        cost[src] = 0;

        //algorithm
        int minIndex;
        int temp;
        int tempC;
        for(int n=0; n<N-1; n++) {
            minIndex=-1;
            for(int k=0; k<N; k++) {
                if(!visit[k] && (minIndex<0||dist[k]<dist[minIndex])) {
                    minIndex = k;
                }
            }

            visit[minIndex] = true;
            for(int k=0; k<N; k++) {
                if(!visit[k] && graph[minIndex][k]>0) {
                    temp = dist[minIndex] + graph[minIndex][k];
                    tempC = cost[minIndex] + graphC[minIndex][k];
                    if(temp < dist[k]) {
                        dist[k] = temp;
                        cost[k] = tempC;
                        prev[k] = minIndex;
                    } else if(temp==dist[k] && tempC<cost[k]) {
                        cost[k] = tempC;
                        prev[k] = minIndex;
                    }
                }
            }
        }
    }
}
