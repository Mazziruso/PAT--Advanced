package PAT1036;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main1036 {
    private static String strM;
    private static String strF;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str;
        String[] strs;

        long N;
        int lowM;
        int highF;
        int grade;

        while((str=br.readLine())!=null) {
            N = Long.valueOf(str);

            lowM = Integer.MAX_VALUE;
            highF = Integer.MIN_VALUE;

            strF = null;
            strM = null;

            for(int i=0; i<N; i++) {
                str = br.readLine();
                strs = str.split(" ");

                grade = Integer.valueOf(strs[3]);
                if(strs[1].equals("M") && lowM>grade) {
                    lowM = grade;
                    strM = strs[0] +" "+ strs[2];
                } else if(strs[1].equals("F") && highF<grade) {
                    highF = grade;
                    strF = strs[0] +" "+ strs[2];
                }
            }

            str = (strM==null || strF==null) ? "NA" : String.valueOf(highF-lowM);

            strM = (strM==null) ? "Absent" : strM;
            strF = (strF==null) ? "Absent" : strF;

            System.out.println(strF);
            System.out.println(strM);
            System.out.println(str);
        }

    }
}
