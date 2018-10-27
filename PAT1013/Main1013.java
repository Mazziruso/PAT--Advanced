package PAT1013;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main1013 {

    private static int N;
    private static int[][] graph;
    private static int[] visit;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str;
        String[] strs;
        int M;
        int K;
        int indexI;
        int indexJ;
        int NumConnect;
        int node;

        while((str=br.readLine())!=null) {

            strs = str.split(" ");
            N = Integer.valueOf(strs[0]);
            M = Integer.valueOf(strs[1]);
            K = Integer.valueOf(strs[2]);

            graph = new int[N][N];
            for(int i=0; i<M; i++) {
                strs = br.readLine().split(" ");
                indexI = Integer.valueOf(strs[0])-1;
                indexJ = Integer.valueOf(strs[1])-1;
                graph[indexI][indexJ] = 1;
                graph[indexJ][indexI] = 1;
            }

            strs = br.readLine().split(" ");
            for(int k=0; k<K; k++) {
                node = Integer.valueOf(strs[k])-1;
                visit = new int[N];
                visit[node] = 1;
                NumConnect = 0;
                for (int i = 0; i < N; i++) {
                    if (visit[i] == 0) {
                        DFSVisit(i);
                        NumConnect++;
                    }
                }

                if(NumConnect==0) {
                    System.out.println(0);
                } else {
                    System.out.println(NumConnect - 1);
                }
            }
        }
    }

    private static void DFSVisit(int u) {
        visit[u] = 1;
        for(int k=0; k<N; k++) {
            if(visit[k]==0 && graph[u][k]>0) {
                DFSVisit(k);
            }
        }
    }
}
