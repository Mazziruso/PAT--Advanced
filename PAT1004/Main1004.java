package PAT1004;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main1004 {

    private static int N;
    private static int[][] FTree;
    private static int[] numLevel;
    private static int maxLevel;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str;
        String[] strs;

        int M;
        int vertex;

        while((str=br.readLine())!=null) {

            strs = str.split(" ");

            N = Integer.valueOf(strs[0]);
            M = Integer.valueOf(strs[1]);

            FTree = new int[100][N+1];

            for(int i=0; i<M; i++) {
                strs = br.readLine().split(" ");

                vertex = Integer.valueOf(strs[0]);
                for(int j=1; j<strs.length; j++) {
                    FTree[vertex][j-1] = Integer.valueOf(strs[j]);
                }
            }

            numLevel = new int[M + 1];
            maxLevel = 0;

            preorder(1, 0);

            if(N == 0) {
                System.out.println(1);
                continue;
            }

            for(int i=0; i<maxLevel; i++) {
                System.out.print(numLevel[i] + " ");
            }
            System.out.println(numLevel[maxLevel]);
        }

    }

    private static void preorder(int root, int level) {
        if(root>99 || FTree[root][0]==0) {
            numLevel[level]++;
            if(maxLevel < level) {
                maxLevel = level;
            }
        } else {
            int K = FTree[root][0];
            for(int k=1; k<=K; k++) {
                preorder(nextNode(root, k), level+1);
            }
        }
    }

    private static int nextNode(int root, int k) {
        if(k<=FTree[root][0]) {
            return FTree[root][k];
        }
        return 0;
    }
}
