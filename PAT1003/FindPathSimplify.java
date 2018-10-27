package PAT1003;

//import java.util.Scanner;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.Vector;

public class FindPathSimplify {

    private static int N;
    private static int[] visit;
    private static int[][] graph;
    private static int[] Vnum;
    private static Stack<Integer> resV;
    private static Vector<Integer> weightP;
    private static Vector<Integer> numRes;

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
            for(int i=0; i<N; i++) {
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
            visit = new int[N];
            resV = new Stack<>();
            weightP = new Vector<>();
            numRes = new Vector<>();

            dfs(src, dest, 0, Vnum[src]);

            int minP = Integer.MAX_VALUE;
            int numPath = weightP.size();
            int maxRes = 0;
            int numShortest = 0;

            for (int i=0; i<numPath; i++) {
                if (minP > weightP.get(i)) {
                    minP = weightP.get(i);
                }
            }

            for (int i = 0; i < numPath; i++) {
                if (minP == weightP.get(i)) {
                    numShortest++;
                    if (maxRes < numRes.get(i)) {
                        maxRes = numRes.get(i);
                    }
                }
            }

            System.out.println(numShortest + " " + maxRes);
        }
    }

    private static void dfs(int src, int dest, int weight, int accRes) {
        resV.push(src);
        visit[src] = 1;

        if(src == dest) {
            weightP.add(weight);
            numRes.add(accRes);
            resV.pop();
            visit[src] = 0;
        } else {
            for(int i=0; i<N; i++) {
                if(graph[src][i]>0 && visit[i]==0) {
                    int weightNew = weight + graph[src][i];
                    int accResNew = accRes + Vnum[i];
                    dfs(i,dest, weightNew, accResNew);
                }
            }
            resV.pop();
            visit[src] = 0;
        }
    }
}
