package PAT1002;

import java.util.Scanner;
import java.util.Vector;
import java.util.Arrays;

public class Main1 {

    static int maxn = 1005;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a;
        double b;
        int c;
        int k;
        int m;
        double sum;
        int sizePile;
        int[] N = new int[20];
        boolean[] flag = new boolean[20];
        Vector[] pile = new Vector[maxn];

        String[] aString;

        while(sc.hasNextLine()) {
            c = 0;
            for(int i=0; i<20; i++) {
                flag[i] = false;
            }

            for(int j=0; j<2; j++) {
                aString = sc.nextLine().split(" ");
                k = Integer.valueOf(aString[0]);
                for(int i=0; i<k; i++) {
                    a = Integer.valueOf(aString[2*i+1]);
                    b = Double.valueOf(aString[2*i+2]);
                    if(pile[a] == null) {
                        pile[a] = new Vector<Double>();
                    }
                    pile[a].addElement(b);
                    if(!flag[a]) {
                        flag[a] = true;
                        N[c++] = a;
                    }
                }
            }

            Arrays.sort(N,0,c);
            m = c;

            for(int i=0; i<c; i++) {
                sum = 0;
                sizePile = pile[N[i]].size();
                for(int j=0; j<sizePile; j++) {
                    sum += (double)pile[N[i]].elementAt(j);
                }
                if(sum == 0) {
                    m--;
                }
            }

            System.out.print(m);

            for(int i=c-1; i>=0; i--) {
                sum =0.0;
                sizePile = pile[N[i]].size();
                for(int j=0; j<sizePile; j++) {
                    sum += (double)pile[N[i]].elementAt(j);
                }
                if(sum != 0) {
                    System.out.print(String.format(" %d %.1f", N[i], sum));
                }
                pile[N[i]].clear();
            }

            System.out.println();
        }
    }
}
