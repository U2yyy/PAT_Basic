import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] a = new int[3000];
        for(int i = 0;i < n;i++){
            int num = in.nextInt();
            do {
                a[num] += 1;
                if (num % 2 == 0) {
                    num /= 2;
                } else {
                    num = (num * 3 + 1) / 2;
                }
            }while (num != 1);
        }
        int[] b = new int[3000];
        int j = 0;
        for(int i = 2999;i >= 0;i--){
            if(a[i] == 1){
                b[j] = i;
                j++;
            }
        }
        for(int i = 0; ;i++){
            System.out.print(b[i]);
            if(b[i+1] != 0){
                System.out.print(" ");
            }else{
                System.out.println();
                break;
            }
        }

    }

}
