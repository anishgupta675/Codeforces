import java.util.Scanner;

public class Quadratic_Inversion {

    private static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int x = sc.nextInt(), n = sc.nextInt(), sum = 0;
        for(int i = 0; i <= n; i++) {
            if(i % 2 == 0) sum+= Math.pow(x, i);
            else sum-= Math.pow(x, i);
        }
        System.out.println(sum);
    }
}