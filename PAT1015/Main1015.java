package PAT1015;

public class Main1015 {
    public static void main(String[] args) {
        System.out.println(reserseNum(23,2));
    }

    private static int reserseNum(int N, int D) {
        int res = 0;
        int bit;

        while(N != 0) {
            bit = N%D;
            N = N/D;
            res = res*D + bit;
        }

        return res;
    }
}
