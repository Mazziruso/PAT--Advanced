package PAT1035;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main1035 {
    private static int N;
    private static String[] accounts;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str;
        String[] strs;

        int M;
        while((str=br.readLine())!=null) {
            N = Integer.valueOf(str);
            accounts = new String[N];
            M = 0;

            for(int i=0; i<N; i++) {
                strs = br.readLine().split(" ");
                str = strs[1];
                if(str.contains("l") || str.contains("O") || str.contains("1") || str.contains("0")) {
                    str = str.replace('l','L').replace('O','o').replace('1','@').replace('0','%');
                    accounts[M] = strs[0] + " " + str;
                    M++;
                }
            }

            if(M==0) {
                if(N==1) {
                    System.out.println("There is 1 account and no account is modified");
                } else {
                    System.out.println(String.format("There are %d accounts and no account is modified", N));
                }
            } else {
                System.out.println(M);
                for (int i = 0; i < M; i++) {
                    System.out.println(accounts[i]);
                }
            }
        }
    }
}
