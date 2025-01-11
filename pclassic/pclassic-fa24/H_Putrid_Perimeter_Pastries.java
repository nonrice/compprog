import java.io.*;
import java.util.*;
import java.math.BigInteger;
public class H_Putrid_Perimeter_Pastries {
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
    public static void main(String[] args) {
        int n = r.nextInt();
        int P = r.nextInt();
        double S = 0;
        for (int i = 0; i < n; i ++) {
            int L = r.nextInt();
            int H = r.nextInt();
            S += L;
            S += H;
            S += Math.sqrt(L*L+H*H);
        }
        pw.println(Math.min(2*S,(double) P));

        pw.close();
    }
}
