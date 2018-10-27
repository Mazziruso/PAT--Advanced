package PAT1087;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main1087 {
    private static int N;
    private static int[][] graph;
    private static int[] val;
    private static String[] cities;
    private static boolean[] visit;
    private static int[] dist;
    private static int[] cost;
    private static int[] num;
    private static int[] prev;
    private static int[] pathNum;

    public static void main(String[] args) throws IOException {
        int K;
//        graph = new int[N][N];
//        graph[0] = new int[]{0,0,1,0,1,2};
//        graph[1] = new int[]{0,0,0,1,2,1};
//        graph[2] = new int[]{1,0,0,1,0,0};
//        graph[3] = new int[]{0,1,1,0,0,0};
//        graph[4] = new int[]{1,2,0,0,0,0};
//        graph[5] = new int[]{2,1,0,0,0,0};
//        val = new int[]{0,100,40,55,95,80};

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str;
        String[] strs;

        HashMap<String, Integer> cityInt;
        int s;
        int dest;
        int ii;
        int jj;

        while((str=br.readLine())!=null) {

            strs = str.split(" ");
            N = Integer.valueOf(strs[0]);
            K = Integer.valueOf(strs[1]);

            cities = new String[N];
            visit = new boolean[N];
            dist = new int[N];
            cost = new int[N];
            num = new int[N];
            prev = new int[N];
            val = new int[N];
            pathNum = new int[N];
            graph = new int[N][N];

            cityInt = new HashMap<String, Integer>();
            cities[0] = strs[2];
            val[0] = 0;
            s = 0;
            dest = 0;
            cityInt .put(strs[2],s);

            for(int i=1; i<N; i++) {
                strs = br.readLine().split(" ");
                cities[i] = strs[0];
                val[i] = Integer.valueOf(strs[1]);
                if(strs[0].equals("ROM")) {
                    dest = i;
                }
                cityInt.put(strs[0], i);
            }

            for(int i=0; i<K; i++) {
                strs = br.readLine().split(" ");
                ii = cityInt.get(strs[0]);
                jj = cityInt.get(strs[1]);
                graph[ii][jj] = Integer.valueOf(strs[2]);
                graph[jj][ii] = Integer.valueOf(strs[2]);
            }

            dijkstra(s);

            int x = 0;
            for(int i=0; i<N; i++) {

            }

            System.out.println(pathNum[dest]+" "+dist[dest]+" "+cost[dest]+" "+cost[dest]/num[dest]);
            printPath(s, dest);
            System.out.println();
        }

    }

    private static void  printPath(int s, int dest) {
        if(s == dest) {
            System.out.print(cities[dest]);
        } else if(dest != -1) {
            printPath(s,prev[dest]);
            System.out.print("->" + cities[dest]);
        }
    }

    private static void dijkstra(int s) {
        //init
        for(int i=0; i<N; i++) {
            dist[i]=Integer.MAX_VALUE;
            cost[i]=0;
            num[i]=Integer.MAX_VALUE;
            prev[i] = -1;
            pathNum[i] = 1;
        }
        dist[s] = 0;
        cost[s] = 0;
        num[s] = 0;

        //algorithm
        int index;
        int temp;
        for(int n=0; n<N-1; n++) {
            index = -1;
            for(int k=0; k<N; k++) {
                if(!visit[k] && (index<0 || dist[k]<dist[index])) {
                    index = k;
                }
            }

            visit[index] = true;

            for(int k=0; k<N; k++) {
                if(!visit[k] && graph[index][k]>0) {
                    temp = dist[index]+graph[index][k];
                    if(dist[k]>temp) {
                        dist[k] = temp;
                        cost[k] = cost[index] + val[k];
                        num[k] = num[index] + 1;
                        prev[k] = index;
                        pathNum[k] = pathNum[index];
                    } else if(dist[k] == temp) {
                        temp = cost[index] + val[k];
                        pathNum[k] += pathNum[index];
                        if(cost[k]<temp) {
                            cost[k] = temp;
                            num[k] = num[index]+1;
                            prev[k] = index;
                        } else if(cost[k]==temp && num[k]>(num[index]+1)) {
                            num[k] = num[index]+1;
                            prev[k] = index;
                        }
                    }
                }
            }
        }
    }
}
