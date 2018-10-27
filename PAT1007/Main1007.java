package PAT1007;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main1007 {
    private static int N;
    private static int[] sum;
    private static int[] start;
    private static int[] a;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str;
        String[] strs;

        while((str=br.readLine())!=null) {

            //read data
            N = Integer.valueOf(str);

            sum = new int[N];
            start = new int[N];
            a = new int[N];

            strs = br.readLine().split(" ");
            for(int i=0; i<N; i++) {
                a[i] = Integer.valueOf(strs[i]);
            }


            //init
            sum[0] = a[0];
            start[0] = 0;

            //iterative
            for (int i = 1; i < N; i++) {
                if (sum[i - 1] > 0) {
                    sum[i] = sum[i - 1] + a[i];
                    start[i] = start[i - 1];
                } else {
                    sum[i] = a[i];
                    start[i] = i;
                }
            }

            //reconstruction solution
            int max = Integer.MIN_VALUE;
            int index = 0;
            for (int i = 0; i < N; i++) {
                if (max < sum[i]) {
                    max = sum[i];
                    index = i;
                }
            }

            if (max < 0) {
                System.out.println(0 + " " + a[0] + " " + a[N - 1]);
            } else {
                System.out.println(max + " " + a[start[index]] + " " + a[index]);
            }
        }
    }
}
