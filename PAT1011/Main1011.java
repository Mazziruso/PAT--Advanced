package PAT1011;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main1011 {
    private static int[] visit;
    private static double[][] bet;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str;
        String[] strs;
        double prod;

        while((str=br.readLine())!=null) {
            visit = new int[3];
            bet = new double[3][3];
            strs = str.split(" ");
            for(int i=0; i<3; i++) {
                bet[0][i] = Double.valueOf(strs[i]);
            }
            for(int j=0; j<2; j++) {
                str = br.readLine();
                strs = str.split(" ");
                for(int i=0; i<3; i++) {
                    bet[j+1][i] = Double.valueOf(strs[i]);
                }
            }
            prod = 1.0;

            for(int i=0; i<3; i++) {
                prod *= maxMat(i);
            }

            String profit = String.format("%.2f", (prod*0.65-1.0)*2.0);

            //display
            System.out.println(toName(visit[0]) + " " + toName(visit[1]) + " " + toName(visit[2]) + " " + profit);
        }
    }

    private static String toName(int num) {
        String str;
        switch (num) {
            case(0) : str = "W";break;
            case(1) : str = "T";break;
            case(2) : str = "L";break;
            default: str = null;
        }

        return str;
    }

    private static double maxMat(int row) {
        double max = -1.0;
        int index = 0;
        for(int i=0; i<3; i++) {
            if(max < bet[row][i]) {
                max = bet[row][i];
                index = i;
            }
        }
        visit[row] = index;

        return max;

    }
}
