package PAT1002;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws NullPointerException {
        Scanner sc = new Scanner(System.in);

        String aPoly;
        String bPoly;
        String[] aRex;
        String[] bRex;
        long aNum;
        long bNum;
        int aIndex = 0;
        int bIndex = 0;
        double outCoef;
        StringBuffer outString;
        long outOrder;

        while(sc.hasNextLine()) {
            aPoly = sc.nextLine();
            bPoly = sc.nextLine();
            aRex = aPoly.split(" ");
            bRex = bPoly.split(" ");

            aNum = Integer.valueOf(aRex[0]) * 2;
            bNum = Integer.valueOf(bRex[0]) * 2;

            outString = new StringBuffer();
            outOrder = 0;
            aIndex = 0;
            bIndex = 0;
            while(aIndex<aNum && bIndex<bNum) {
                if(aRex[1+aIndex].equals(bRex[1+bIndex])) {
                    outCoef = Double.valueOf(aRex[2+aIndex]) + Double.valueOf(bRex[2+bIndex]);
                    outCoef = Math.round(outCoef*10)/10.0;
                    if(outCoef != 0) {
                        outString.append(aRex[1+aIndex]);
                        outString.append(" ");
                        outString.append(outCoef);
                        outString.append(" ");
                    }
                    aIndex = aIndex + 2;
                    bIndex = bIndex + 2;
                } else if(Integer.valueOf(aRex[1+aIndex]) > Integer.valueOf(bRex[1+bIndex])) {
                    outCoef = Double.valueOf(aRex[2+aIndex]);
                    outCoef = Math.round(outCoef*10)/10.0;
                    if(outCoef != 0) {
                        outString.append(aRex[1 + aIndex]);
                        outString.append(" ");
                        outString.append(outCoef);
                        outString.append(" ");
                    }
                    aIndex = aIndex + 2;
                } else {
                    outCoef = Double.valueOf(bRex[2+bIndex]);
                    outCoef = Math.round(outCoef*10)/10.0;
                    if(outCoef != 0) {
                        outString.append(bRex[1 + bIndex]);
                        outString.append(" ");
                        outString.append(outCoef);
                        outString.append(" ");
                    }
                    bIndex = bIndex + 2;
                }

                outOrder = (outCoef != 0) ? (outOrder + 1) : outOrder;
            }

            if(aIndex >= aNum) {
                while(bIndex < bNum) {
                    outCoef = Double.valueOf(bRex[2+bIndex]);
                    outCoef = Math.round(outCoef*10)/10.0;
                    if(outCoef != 0) {
                        outString.append(bRex[1 + bIndex]);
                        outString.append(" ");
                        outString.append(outCoef);
                        outString.append(" ");
                    }
                    bIndex = bIndex + 2;
                    outOrder = outOrder + 1;
                }
            } else {
                while(aIndex < aNum) {
                    outCoef = Double.valueOf(aRex[2+aIndex]);
                    outCoef = Math.round(outCoef*10)/10.0;
                    if(outCoef != 0) {
                        outString.append(aRex[1 + aIndex]);
                        outString.append(" ");
                        outString.append(outCoef);
                        outString.append(" ");
                    }
                    aIndex = aIndex + 2;
                    outOrder = outOrder + 1;
                }
            }

            //如果两式子相消，则输出0；若出现0项则不输出那项
            if(outOrder != 0) {
                System.out.println(outOrder + " " + outString.deleteCharAt(outString.length() - 1));
            } else {
                System.out.println(0);
            }
        }
    }
}
