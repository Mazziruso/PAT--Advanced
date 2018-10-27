package PAT1024;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

/*这题要考虑大整数的问题，超出了long的表示范围，而且用double表示不精确*/
public class Main1024 {
    private static int times;
    private static BigInteger num;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str;
        String[] strs;

        long N;
        int K;
        BigInteger numTmp;

        while((str=br.readLine())!=null) {

            strs = str.split(" ");
//            N = Long.valueOf(strs[0]);
            K = Integer.valueOf(strs[1]);

            numTmp = new BigInteger(strs[0]);
            num = new BigInteger("0");
            times = 0;
            while(times <= K) {
                times++;

                numTmp = numTmp.add(num);
                num = reverseBit(numTmp);
                if(numTmp.compareTo(num) == 0) {
                    break;
                }

            }

            System.out.println(numTmp);
            System.out.println(times-1);
        }
    }

    private static BigInteger reverseBit(BigInteger n) {
        BigInteger res = new BigInteger("0");
        BigInteger bit;

        while(n.compareTo(BigInteger.ZERO) > 0) {
            bit = n.remainder(BigInteger.TEN);
            n = n.divide(BigInteger.TEN);

            res = res.multiply(BigInteger.TEN).add(bit);
        }

        return res;
    }

}
