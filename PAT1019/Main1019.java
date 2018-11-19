package PAT1019;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main1019 {

    private static String[] num;
    private static int maxIndex;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str;
        String[] strs;

        int N;
        int D;

        while((str=br.readLine())!=null) {

            strs = str.split(" ");

            N = Integer.valueOf(strs[0]);
            D = Integer.valueOf(strs[1]);

            num = new String[32];
            maxIndex = 0;

            if(N == reverseBit(N, D)) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }


            for(int i=maxIndex-1; i>=1; i--) {
                System.out.print(num[i] + " ");
            }
            if(maxIndex == 0) {
                System.out.println(0);
            } else {
                System.out.println(num[0]);
            }

        }

    }

    private static int reverseBit(int N, int D) {
        int res = 0;
        int bit;
        while(N > 0) {
            bit = N%D;
            N = N/D;
            res = res*D + bit;
            num[maxIndex++] = String.valueOf(bit);
        }

        return res;
    }
}
