import java.io.*;
import java.util.*;
public class G_Precise_Prime_Patterns {
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
    static long mod = 1000000007; static long[] fact; static HashMap<Integer,Integer> multiset;
    public static void main(String[] args) {
        int n = r.nextInt();
        int k = r.nextInt();
        int L = 1000000;
        List<Integer>[] primeFactors = new ArrayList[L+5];
        for (int i = 1; i <= L; i ++) {
            primeFactors[i] = new ArrayList<Integer>();
        }
        for (int i = 2; i <= L; i ++) {
            if (primeFactors[i].size() == 0) {
                for (int j = i; j <= L; j +=i) {
                    primeFactors[j].add(i);
                }
            }
        }
        multiset = new HashMap<Integer,Integer>();
        int[] a = new int[n];
        for (int i = 0; i < n; i ++) {
            a[i] = r.nextInt();
        }
        int end = 0;
        int countPrimes = 0;
        int[] max = new int [n];
        boolean[] works = new boolean[n];

        for (int start = 0; start < n - 2; start ++) {
            if (countPrimes == k) {works[start] = true; max[start] = Math.max(end-1,max[start]);}
            while (true) {
                for (int prime: primeFactors[a[end]]) {
                    countPrimes += add(prime);
                }
                if (countPrimes == k) {
                    works[start] = true; 
                    max[start] = Math.max(end, max[start]);
                }
                if (countPrimes > k || (end == n - 1)) {
                    for (int prime: primeFactors[a[end]]) {
                        countPrimes += remove(prime);
                    }
                    break;
                }
                end ++; 
            }
            for (int prime: primeFactors[a[start]]) {
                countPrimes += remove(prime);
            }
        }
        
        int ans = 0;
        for (int start = 0; start < n - 1; start ++) {
            
            int div = a[start];
            for (int j = start; j <= max[start]; j ++) {
                 div = gcd(div,a[j]);
            }
            
            if (works[start] && div == 1) {
                ans = Math.max(ans, max[start]-start + 1); 
            }
        }
        pw.println(ans);
        pw.close();
    }
    static int add (int x) {
        if (multiset.containsKey(x)) {
            multiset.put(x,multiset.get(x)+1);
            return 0;
        }
        else {
            multiset.put(x,1);
            return 1;
        }
    }
    static int remove (int x) {
        if (multiset.get(x) == 1) {
            multiset.remove(x);
            return -1;
        }
        else {
            multiset.put(x,multiset.get(x)-1);
            return 0;
        }
    }
    static int gcd (int a, int b) {
        if (b == 0) {
            return a;
        }
        return (gcd(b,a%b));
    }
}
