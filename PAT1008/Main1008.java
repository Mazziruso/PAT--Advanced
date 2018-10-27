package PAT1008;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main1008 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str;
        String[] strs;

        int N;
        int sum;
        int lastFloor;
        int currFloor;

        while((str=br.readLine()) != null) {
            strs = str.split(" ");

            N = Integer.valueOf(strs[0]);
            lastFloor = 0;
            sum = 0;

            for(int i=0; i<N; i++) {
                currFloor = Integer.valueOf(strs[i+1]);
                sum += (currFloor>lastFloor) ? (6*(currFloor-lastFloor)) : (4*(lastFloor-currFloor));
                lastFloor = currFloor;
            }

            sum += (N*5);

            System.out.println(sum);
        }
    }
}
