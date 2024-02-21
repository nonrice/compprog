import java.util.Scanner;

public class BigBenJenga {
    public static void main(String args[]) {
        Scanner io = new Scanner(System.in);
        int T = io.nextInt();
        for (int t = 0; t<T; t++) {
            long N = io.nextLong();
            long h = (long)Math.floor(N/3);
            if (h != 0) {
                System.out.println(exp(2, h+1, 3359232)-2);

            }
            if (h == 0) {
                System.out.println(0);
            }
        }
    }
    public static long exp(long x, long n, long m) {
        assert (n >= 0);
        x %= m;
        // note: m * m must be less than 2^63 to avoid ll overflow
        long res = 1;
        while (n > 0) {
            if (n % 2 == 1) { res = (res * x) % m; }
            x = (x * x) % m;
            n /= 2;
        }
        return res;
    }
}
