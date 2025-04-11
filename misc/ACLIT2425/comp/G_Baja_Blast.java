import java.io.*;
import java.util.*;
import java.math.BigInteger;
public class G_Baja_Blast {
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
	// al = newArrayList[n];
        int t = 1;
        for (int test = 0; test < t; test ++) {
            solve();
        }

        pw.close();
    }
    public static void solve() {
        int n = r.nextInt();
        long x = r.nextLong();
        long[] a = new long[n]; long[] d = new long[n]; int b[] = new int[n];
        for (int i = 0; i < n; i ++) {
            a[i] = r.nextLong();
            d[i] = r.nextLong();
            b[i] = r.nextInt();
        }
        PriorityQueue<Long> pq = new PriorityQueue<Long>();
        for (int i = 0; i < n; i ++) {
            
            pq.add(a[i]*(long)n+(long) i);
            b[i]--;
        }
        long curr = 0;
        int num = 0;
        while (!pq.isEmpty()) {
            long next = pq.poll();
            long val = next/n;
            int i = ((int) next)%n;
            if (val + curr > x) {
                break;
            }
            curr += val;
            num ++;
            if (b[i] > 0) {
                pq.add((val+d[i])*n+(long) i);
                b[i]--;
            }
        }
        pw.println(num + " " + curr);
    }
}

