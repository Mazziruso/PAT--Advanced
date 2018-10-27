package PAT1003;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class DFSFindPath {
    public static void main(String[] args) {
        int N ;
        int M;

        int[] vNum;
        int[][] eId;
        int src;
        int dest;

        Scanner sc = new Scanner(System.in);
        while(sc.hasNextLine()) {
            N = sc.nextInt();
            M = sc.nextInt();

            src = sc.nextInt();
            dest = sc.nextInt();

            vNum = new int[N];
            for(int i=0; i<N; i++) {
                vNum[i] = sc.nextInt();
            }
            eId = new int[M][3];
            for(int i=0; i<M; i++) {
                eId[i][0] = sc.nextInt();
                eId[i][1] = sc.nextInt();
                eId[i][2] = sc.nextInt();
            }

            ArrayList<Integer[]> pathInfo = UGraph.findAllPath(vNum, eId, src, dest);

            int minPath = Integer.MAX_VALUE;
            int numPath = pathInfo.size();

            //找到最短路径权重
            for (int i = 0; i < numPath; i++) {
                if (minPath > pathInfo.get(i)[0]) {
                    minPath = pathInfo.get(i)[0];
                }
            }

            int numShort = 0;
            int maxVertex = 0;

            for (int i = 0; i < numPath; i++) {
                if (minPath == pathInfo.get(i)[0]) {
                    numShort++;
                    if (maxVertex < pathInfo.get(i)[1]) {
                        maxVertex = pathInfo.get(i)[1];
                    }
                }
            }

            System.out.println(numShort + " " + maxVertex);
        }
    }
}

class UGraph {
    int N;
    int[] V;
    int[] Vnum;
    int[][] edge;

    //维护dfs性质
    static Stack<Integer> res;
    static int[] visit;
    static ArrayList<Integer[]> PathInfo;

    public UGraph(int[] vNum, int[][] eId) {
        int M = eId.length;
        this.N = vNum.length;

        this.V = new int[this.N];
        this.Vnum = new int[this.N];
        this.edge = new int[this.N][this.N];

        for(int i=0; i<N; i++) {
            this.V[i] = i;
            this.Vnum[i] = vNum[i];
        }
        for(int i=0; i<M; i++) {
            this.edge[eId[i][0]][eId[i][1]] = eId[i][2];
            this.edge[eId[i][1]][eId[i][0]] = eId[i][2];
        }
    }

    public static ArrayList<Integer[]> findAllPath(int[] vNum, int[][] eId, int src, int dest) {
        int N = vNum.length;

        res = new Stack<Integer>();
        visit = new int[N];
        PathInfo = new ArrayList<Integer[]>();

        UGraph G = new UGraph(vNum, eId);

        UGraph.dfs(G, src, dest,0);

        return PathInfo;
    }

    private static void dfs(UGraph G, int src, int dest, int weight) {
        res.push(src);
        visit[src] = 1;
        int pathLen;

        while(true) {
            if(src == dest) {
                pathLen = res.size();
                Integer[] pathPart = new Integer[2];
                pathPart[0] = weight;
                pathPart[1] = 0;
                for(int i=1; i<=pathLen; i++) {
                    pathPart[1] += G.Vnum[res.get(i-1)];
                }
                PathInfo.add(pathPart);
                res.pop();
                visit[src]=0;
                break;
            }

            for(int i=0; i<G.N; i++) {
                if(G.edge[src][i] != 0) {
                    if(visit[i] == 0) {
                        UGraph.dfs(G, i, dest, (G.edge[src][i]+weight));
                    }
                }
            }

            res.pop();
            visit[src] = 0;
            break;
        }
    }
}