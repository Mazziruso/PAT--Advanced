package PAT1016;


import java.io.BufferedReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.InputStreamReader;

public class Main1016 {
    private static int N;
    private static double[] fee;
    private static NameID[] nID;
    private static String month;
    private static double Dayfee;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str;
        String[] strs;
        String[] strTmp;
        int indexTmp;
        int time;
        int startT;
        int endT;
        double cost;
        double total;
        boolean flag;

        while((str=br.readLine())!=null) {
            strs = str.split(" ");

            Dayfee = 0.0;
            fee = new double[24];
            for(int i=0; i<24; i++) {
                fee[i] = Integer.valueOf(strs[i])/100.0;
                Dayfee += fee[i]*60.0;
            }

            str = br.readLine();
            N = Integer.valueOf(str);

            nID = new NameID[N];
            month = null;

            for(int i=0; i<N; i++) {
                strs = br.readLine().split(" ");

                month = (month==null) ? strs[1].substring(0,2) : month;

                nID[i] = new NameID(strs[0], i);

                strTmp = strs[1].split(":");
                time = Integer.valueOf(strTmp[1])*24*60+Integer.valueOf(strTmp[2])*60+Integer.valueOf(strTmp[3]);

                nID[i].recordTime = time;
                nID[i].line = strs[2].equals("on-line");
            }

            Arrays.sort(nID);

            indexTmp = 0;
            while(indexTmp<N-1) {
                flag = true;
                total = 0.0;
                while(indexTmp<(N-1) && nID[indexTmp].name.equals(nID[indexTmp+1].name)) {
                    if(nID[indexTmp].line && !nID[indexTmp+1].line) {
                        if(flag) {
                            System.out.println(nID[indexTmp].name + " " + month);
                            flag = false;
                        }
                        startT = nID[indexTmp].recordTime;
                        endT = nID[indexTmp+1].recordTime;
                        cost  = charge(startT, endT);
                        System.out.print(toTime(startT) + " " + toTime(endT) + " " + (endT-startT) + " $");
                        System.out.println(String.format("%.2f", cost));
                        total += cost;
                    }
                    indexTmp++;
                }
                if(!flag) {
                    System.out.println("Total amount: $" + String.format("%.2f", total));
                }
                indexTmp++;
            }

        }
    }

    private static double charge(int start, int end) {
        int startD = start/(24*60);
        start %= (24*60);
        int startH = start/60;
        int startM = start%60;
        int endD = end/(24*60);
        end %= (24*60);
        int endH = end/60;
        int endM = end%60;

        double cost = 0;

        if(startD!=endD) {
            for (int i = startD; i < endD; i++) {
                cost += Dayfee;
            }
            for(int i=0; i<startH; i++) {
                cost -= fee[i]*60;
            }
            cost -= fee[startH]*startM;
            for(int i=0; i<endH; i++) {
                cost += fee[i]*60;
            }
            cost += fee[endH]*endM;
        } else {
            for (int i = startH; i < endH; i++) {
                cost += fee[i] * 60;
            }
            cost = cost + endM * fee[endH] - startM * fee[startH];
        }

        return cost;
    }

    private static String toTime(int time) {
        String dhm;
        int minutes;
        int hours;
        int days;

        days = time/(24*60);
        time = time%(24*60);
        hours = time/60;
        time = time%60;
        minutes = time;

        dhm = String.format("%02d:%02d:%02d", days, hours, minutes);

        return dhm;
    }
}

class NameID implements Comparable<NameID> {
    String name;
    int id;
    int recordTime;
    boolean line;

    public NameID(String name, int id) {
        this.name = name;
        this.id = id;
    }

    public NameID() {
        this(null, 0);
    }

    public int compareTo(NameID nId) {
        if(this.name.compareTo(nId.name)==0) {
            return Integer.compare(this.recordTime, nId.recordTime);
        } else {
            return this.name.compareTo(nId.name);
        }
    }
}