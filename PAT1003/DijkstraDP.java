package PAT1003;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class DijkstraDP {

    private static int N;
    private static int[] Vnum;
    private static int[][] graph;
    private static int[] cost;
    private static boolean[] visit;
    private static int[] ways;
    private static int[] numRes;

    public static void main(String[] args) throws IOException {

        int M;
        int src;
        int dest;
        int eId0;
        int eId1;
        int eId2;

        String str;
        String[] strs;
        BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        while((str=sc.readLine()) != null) {
            strs = str.split(" ");
            N = Integer.valueOf(strs[0]);
            M = Integer.valueOf(strs[1]);
            src = Integer.valueOf(strs[2]);
            dest = Integer.valueOf(strs[3]);

            strs = sc.readLine().split(" ");
            Vnum = new int[N];
            for (int i = 0; i < N; i++) {
                Vnum[i] = Integer.valueOf(strs[i]);
            }

            graph = new int[N][N];
            for (int i = 0; i < M; i++) {
                strs = sc.readLine().split(" ");
                eId0 = Integer.valueOf(strs[0]);
                eId1 = Integer.valueOf(strs[1]);
                eId2 = Integer.valueOf(strs[2]);
                graph[eId0][eId1] = eId2;
                graph[eId1][eId0] = eId2;
            }

            cost = new int[N];
            visit = new boolean[N];
            numRes = new int[N];
            ways = new int[N];

            dijkstra(src);

            System.out.println(ways[dest] + " " + numRes[dest]);
        }
    }

    private static void dijkstra(int src) {
        //init
        for(int i=0; i<N; i++) {
            cost[i] = Integer.MAX_VALUE;
            visit[i] = false;
            numRes[i] = 0;
            ways[i] = 0;
        }
        numRes[src] = Vnum[src];
        ways[src] = 1;
        cost[src] = 0;

        //dijkstra
        int minIndex;
        int temp;
        for(int i=0; i<N; i++) {

            //find minimum distance vertex
            minIndex = -1;
            for(int k=0; k<N; k++) {
                if(!visit[k] && ((minIndex<0) || cost[k] < cost[minIndex])) {
                    minIndex = k;
                }
            }

            visit[minIndex] = true;
            for(int k=0; k<N; k++) {
                if(!visit[k] && graph[minIndex][k]>0) {
                    temp = cost[minIndex] + graph[minIndex][k];
                    if(temp<cost[k]) {
                        cost[k] = temp;
                        numRes[k] = numRes[minIndex] + Vnum[k];
                        ways[k] = ways[minIndex];
                    } else if(temp == cost[k]) {
                        numRes[k] = Math.max(numRes[k],numRes[minIndex]+Vnum[k]);
                        ways[k] += ways[minIndex];
                    }
                }
            }
        }
    }
}
