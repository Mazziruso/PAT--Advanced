package PAT1010;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main1010 {

    private static String num;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str;
        String[] strs;

        //要用double来存储转换后的十进制值，否则会溢出（java没有long long型）
        double ans1;
        int len;
        int tag;
        long radix;
        long start;
        long end;
        long bit;
        double fvalue;

        while((str=br.readLine())!=null) {
            strs = str.split(" ");

            tag = Integer.valueOf(strs[2]);
            radix = Long.valueOf(strs[3]);

            num = strs[tag-1];
            ans1 = toDecimal(radix);

            //find max R in N2
            num = strs[2-tag];
            len = num.length();
            bit = (num.charAt(0)>'a') ? (num.charAt(0)-87) : (num.charAt(0)-48);

            //when N is 1 and N1==N2, then R must be a0+1; or non-solution
            if(len==1 && bit==ans1) {
                System.out.println(bit+1);
                continue;
            } else if(len==1) {
                System.out.println("Impossible");
                continue;
            }

            //end's upper bound, start's lower bound
//            end = (long)Math.pow(ans1/bit, 1.0/(len-1)) + 1; //PAT上的库函数不精确
            end = (long)ans1 + 1;
            start = -1;
            for(int i=0; i<len; i++) {
                bit = (num.charAt(i)>'a') ? (num.charAt(i)-86) : (num.charAt(i)-47);
                if(start < bit) {
                    start = bit;
                }
            }

            //if f(R)=ans2-ans1>0 when R=0, there is no solution
            fvalue = toDecimal(start);
            if(fvalue > ans1) {
                System.out.println("Impossible");
                continue;
            }

            radix = binarySearch(ans1, start, end);

            if(radix == -1) {
                System.out.println("Impossible");
            } else {
                System.out.println(radix);
            }

        }
    }

    private static long binarySearch(double ans, long start, long end) {
        long radix = (start+end)/2;
        double ans2 = toDecimal(radix);

        while(ans2!=ans && start<end) {
            if(ans2 > ans) {
                end = radix-1;
            } else {
                start = radix+1;
            }
            radix = (start+end)/2;
            ans2 = toDecimal(radix);
        }

        if(ans2 == ans) {
            return radix;
        } else {
            return -1;
        }
    }

    private static double toDecimal(long radix) {
        double ans1 = 0;
        double radixTemp = 1;
        int len = num.length();
        for(int i=len-1; i>=0; i--) {
            if(num.charAt(i) >= 'a') {
                ans1 += radixTemp*(num.charAt(i)-87);
            } else {
                ans1 += radixTemp*(num.charAt(i)-48);
            }
            radixTemp *= radix;
        }

        return ans1;
    }
}
