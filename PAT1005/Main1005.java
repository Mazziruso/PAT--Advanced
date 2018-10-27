package PAT1005;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main1005 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str;
        String strs;
        char[] chs;

        int sum;
        int bit;
        int len;

        while((str=br.readLine())!=null) {
            len = str.length();
            sum = 0;
            for(int i=0; i<len; i++) {
                bit = Integer.valueOf(str.charAt(i)) - Integer.valueOf('0');
                sum += bit;
            }

            strs = String.valueOf(sum);
            chs = strs.toCharArray();
            len = chs.length;
            for(int i=0; i<len-1; i++) {
                System.out.print(toLetter(chs[i]) + " ");
            }
            System.out.println(toLetter(chs[len-1]));
        }
    }

    private static String toLetter(char ch) {
        String str;
        switch (ch) {
            case '1' : str = "one";break;
            case '2' : str = "two";break;
            case '3' : str = "three";break;
            case '4' : str = "four";break;
            case '5' : str = "five";break;
            case '6' : str = "six";break;
            case '7' : str = "seven";break;
            case '8' : str = "eight";break;
            case '9' : str = "nine";break;
            default: str = "zero";
        }

        return str;
    }
}
