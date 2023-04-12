import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Find_Unit_Consecutive_Difference {

    private static final Scanner sc = new Scanner(System.in);

    private static void checkUntil(int num, int K, int N, List<Integer> ans) {
        if(N == 1) {
            ans.add(num);
            return;
        }

        if((num % 10 + K) <= 9)
            checkUntil(10 * num + (num % 10 + K), K, N - 1, ans);
        
        if(K > 0) {
            if((num % 10 - K) >= 0) checkUntil(10 * num + num % 10 - K, K, N - 1, ans);
        }
    }

    private static void check(int K, int N, List<Integer> ans) {
        for(int i = 1; i <= 9; i++)
            checkUntil(i, K, N, ans);
    }

    private static void print(List<Integer> ans) {
        for(int i = 0; i < ans.size(); i++)
            System.out.println(ans.get(i) + " ");
    }

    public static void main(String[] args) throws Exception {
        int N = sc.nextInt();
        if(N == 1) {
            System.out.println("-1");
            return;
        }
        List<Integer> ans = new ArrayList<Integer>();
        check(1, N, ans);
        Collections.sort(ans);
        print(ans);
    }
}