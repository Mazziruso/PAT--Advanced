package PAT1006;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main1006 {

    private static String[] ID;
    private static int[][] times;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N;
        String str;
        String[] strs;

        int minIndex;
        int maxIndex;
        int min;
        int max;

        while((str=br.readLine())!=null) {

            minIndex = 0;
            maxIndex = 0;
            min = Integer.MAX_VALUE;
            max = -1;

            N = Integer.valueOf(str);

            ID = new String[N];
            times = new int[N][2];
            for (int i = 0; i < N; i++) {
                strs = br.readLine().split("[: ]");
                ID[i] = strs[0];
                times[i][0] = 3600 * Integer.valueOf(strs[1]) + 60 * Integer.valueOf(strs[2]) + Integer.valueOf(strs[3]);
                times[i][1] = 3600 * Integer.valueOf(strs[4]) + 60 * Integer.valueOf(strs[5]) + Integer.valueOf(strs[6]);
            }

            for (int i = 0; i < N; i++) {
                if (min > times[i][0]) {
                    min = times[i][0];
                    minIndex = i;
                }
                if (max < times[i][1]) {
                    max = times[i][1];
                    maxIndex = i;
                }
            }

            System.out.println(ID[minIndex] + " " + ID[maxIndex]);
        }

    }
}
