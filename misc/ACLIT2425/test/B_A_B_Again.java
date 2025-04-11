import java.io.*;
import java.util.*;
import java.math.BigInteger;
public class B_A_B_Again {
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }
        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
            return Long.parseLong(next());
        }
        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    static InputReader r = new InputReader(System.in);
    static PrintWriter pw = new PrintWriter(System.out);
    static long mod = 1000000007; static long[] fact;

    static ArrayList<Integer>[] al; 
    public static void main(String[] args) {
        int t = r.nextInt();
        for (int test = 0; test < t; test ++) {
            solve();
        }

        pw.close();
    }
    public static void solve() {
        int n = r.nextInt();
        pw.println(n/10+n%10);
    }
}