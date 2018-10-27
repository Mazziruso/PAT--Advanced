package PAT1012;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main1012 {

    private static int N;
    private static int[][] ranking;
    private static HashMap<String,Integer> ID;
    private static int[][] grade;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str;
        String[] strs;

        int M;
        int temp;
        int max;
        int index=0;

        while((str=br.readLine())!=null) {
            strs = str.split(" ");
            N = Integer.valueOf(strs[0]);
            M = Integer.valueOf(strs[1]);

            ranking = new int[N][4];
            grade = new int[N][4];
            ID = new HashMap<>();

            for(int i=0; i<N; i++) {
                strs = br.readLine().split(" ");
                ID.put(strs[0],i);
                temp = 0;
                for(int k=1; k<4; k++) {
                    grade[i][k] = Integer.valueOf(strs[k]);
                    temp += grade[i][k];
                }
                grade[i][0] = Math.round(temp/3.0f);
            }

            RankCal();

            for(int i=0; i<M; i++) {
                str = br.readLine();
                if(!ID.containsKey(str)) {
                    System.out.println("N/A");
                } else {
                    temp = ID.get(str);
                    max = Integer.MAX_VALUE;
                    for(int k=0; k<4; k++) {
                        if(max>ranking[temp][k]) {
                            max = ranking[temp][k];
                            index = k;
                        }
                    }
                    System.out.println(max + " " + toCourse(index));
                }
            }
        }

    }

    private static String toCourse(int i) {
        String res;
        switch (i) {
            case 0: res = "A"; break;
            case 1: res = "C"; break;
            case 2: res = "M"; break;
            case 3: res = "E"; break;
            default: res=null;
        }

        return res;
    }

    private static void RankCal() {
        //init

        for(int i=0; i<4; i++) {
            CountSort(i);
        }
    }

    private static void CountSort(int k) {

        int[] C = new int[101];
        int[] B = new int[101];

        for(int i=0; i<N; i++) {
            C[grade[i][k]]++;
        }

        B[100] = 1;
        for(int i=100; i>0; i--) {
            B[i-1] = C[i] + B[i];
        }

        int temp;
        for(int i=N-1; i>=0; i--) {
            temp = grade[i][k];
            ranking[i][k] = B[temp];
        }
    }

}
