package PAT1004;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class test1004 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {//注意while处理多个case
            String s=in.nextLine();
            String[] r=s.split(" ");
            int a=Integer.parseInt(r[0]);
            int b=Integer.parseInt(r[1]);
            int index=0;
            if(b==0) {
                System.out.println(1);
                continue;
            }
            ArrayList<Integer>[] arr=new ArrayList[a+1];
            for (int i = 0; i < arr.length; i++) {
                arr[i]=new ArrayList<Integer>();
            }
            while(index++<b){
                String temp=in.nextLine();
                String[] s1=temp.split(" ");
                int index1=Integer.parseInt(s1[0]);
                for (int i = 2; i < s1.length; i++) {
                    arr[index1].add(Integer.parseInt(s1[i]));
                }
            }
            do_1(a,b,arr);
        }

    }

    private static void do_1(int a, int b, ArrayList<Integer>[] arr) {
        Queue<Integer> queue=new LinkedList<Integer>();
        queue.add(1);
        int depth=0;
        int[] res=new int[a];
        while(!queue.isEmpty()){
            int size=queue.size();
            for (int i = 0; i < size; i++) {
                int temp=queue.remove();
                if(arr[temp].size()==0) res[depth]++;
                for (int j = 0; j <arr[temp].size(); j++) {
                    queue.add(arr[temp].get(j));
                }
            }
            depth++;
        }
        for (int i = 0; i < depth-1; i++) {
            System.out.print(res[i]+" ");
        }
        System.out.print(res[depth-1]);
    }
}
