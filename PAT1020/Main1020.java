package PAT1020;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main1020 {
    private static int N;
    private static int[] PostArray;
    private static int[] InArray;
    private static int[] LevelArray;
    private static int maxn = 1000;

    public static void main(String[] args) throws IOException {

//        N = 18;
//
//        PostArray = new int[]{9 ,14 ,8 ,15 ,11 ,6 ,1 ,7 ,16 ,2 ,12 ,18 ,3 ,4 ,10 ,5 ,13 ,17};
//        InArray = new int[]{9 ,17 ,13 ,14 ,8 ,5 ,10 ,11 ,15 ,6 ,7 ,1 ,4 ,16 ,3 ,18 ,12 ,2};
//        LevelArray = new int[N];

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str;
        String[] strs1;
        String[] strs2;

        while((str=br.readLine())!=null) {
            N = Integer.valueOf(str);

            PostArray = new int[N];
            InArray = new int[N];
            LevelArray = new int[maxn];

            strs1 = br.readLine().split(" ");
            strs2 = br.readLine().split(" ");
            for(int i=0; i<N; i++) {
                PostArray[i] = Integer.valueOf(strs1[i]);
                InArray[i] = Integer.valueOf(strs2[i]);
            }

            levelOrderRer(0, N - 1, 0, N - 1, 1);

            countingSort();

            for(int i=0; i<N-1; i++){
                System.out.print(LevelArray[i] + " ");
            }
            System.out.println(LevelArray[N-1]);
        }
    }

    private static void countingSort() {
        int max = -1;
        for(int i=0; i<maxn; i++) {
            if(max < LevelArray[i]) {
                max = LevelArray[i];
            }
        }

        int[] C = new int[max];

        for(int i=0; i<maxn; i++) {
            if(LevelArray[i]>0) {
                C[LevelArray[i]-1]++;
            }
        }

        for(int i=1; i<max; i++) {
            C[i] += C[i-1];
        }

        int[] B = new int[N];
        int index;
        for(int i=N-1; i>=0; i--) {
            index = InArray[i]-1;
            B[C[LevelArray[index]-1]-1] = index+1;
            C[LevelArray[index]-1]--;
        }

        LevelArray = B;
    }

    private static void levelOrderRer(int startI, int endI, int startP, int endP, int level) {
        if(startI <= endI) {
            int insertI = 0;
            int insertP;

            //root
            int root = PostArray[endP];

            //find insertI
            for(int i=startI; i<=endI; i++) {
                if(InArray[i] == root) {
                    insertI = i;
                    break;
                }
            }
            insertP = insertI-startI+startP-1;

            LevelArray[root-1] = level;

            levelOrderRer(startI, insertI-1, startP, insertP, level+1);
            levelOrderRer(insertI+1, endI, insertP+1, endP-1, level+1);
        }
    }

}
