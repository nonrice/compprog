import java.io.*;
import java.util.*;
import java.math.BigInteger;
public class A_Watermelon {
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
        int t = 1;
        for (int test = 0; test < t; test ++) {
            solve();
        }

        pw.close();
    }
    public static void solve() {
        int n = r.nextInt();
        if (n == 2 || n%2 == 1) {
            pw.println("NO");
        }
        else {
            pw.println("YES");
        }
        import java.io.*;
import java.util.*;
import java.math.BigInteger;
public class A_Watermelon {
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
        int t = 1;
        for (int test = 0; test < t; test ++) {
            solve();
        }

        pw.close();
    }
    public static void solve() {
        //PUT CODE FOR PROBLEM HERE
        
    }

    //CUSTOM COMPARATOR
    static class Triple implements Comparable<Triple> {
        public int x,y,z;
        public Triple(int x, int y, int z) {
            this.x=x;
            this.y=y;
            this.z=z;
        }

        @Override
        public int compareTo(Triple t) {
            if (x != t.x) {
                return x-t.x;
            }
            if (y != t.y) {
                return y-t.y;
            }
            return z-t.z;
        }
    }


    //COORDINATE COMPRESSION

    static int[] rank(int[] arr) {
        int n = arr.length;
        Integer[] indices = new Integer[n];
        for (int i = 0; i < n; i++) indices[i] = i;
        Arrays.sort(indices, (a, b) -> Integer.compare(arr[a], arr[b]));
        int[] ranked = new int[n];
        for (int i = 0; i < n; i++) ranked[indices[i]] = i + 1;
        return ranked;
    }

    //Finds minimum value such that a condition is true
    static int binSearchMin(int lo, int hi) {
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;
            // if (condition(mid) == true) {hi=mid;}
            //else {lo = mid + 1;}
        }
        return lo;
    }

    //Finds maximum value such that a condition is true
    static int binSearchMax(int lo, int hi) {
        while (lo < hi) {
            int mid = lo + (hi - lo + 1)/2;
            // if (condition(mid) == true) {hi=mid;}
            //else {hi = mid-1;}
            
        }
        return lo;
    }

    //Longest Common Subsequence
    public static int longestCommonSubsequence(String s1, String s2) {
        int m = s1.length(), n = s2.length();
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = s1.charAt(i - 1) == s2.charAt(j - 1) 
                           ? dp[i - 1][j - 1] + 1 
                           : Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
    //DSU
    static class DSU {
        int[] parent;
        int[] rank;
        public DSU(int n) {
            parent = new int[n]; rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i; rank[i] = 0;
            }
        }
        public int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        public int union(int a, int b) {
            int rootA = find(a); int rootB = find(b);
            if (rootA == rootB) {return 0;}
            if (rank[rootA] > rank[rootB]) {
                parent[rootB] = rootA;
            } else if (rank[rootA] < rank[rootB]) {
                parent[rootA] = rootB;
            } else {
                parent[rootB] = rootA;
                rank[rootA]++;
            }
            return 1;
        }
    }

    static class BIT {
        int[] bit;
        int n;
        public BIT(int size) {
            this.n = size;
            this.bit = new int[n+1];
        }
        public void update (int index, int value) {
            for (; index <= n; index += index & -index) {
                bit[index] += value;
            }
        }
        public int query(int index) { //Prefix sum from 1 to index
            int sum = 0;
            for (; index > 0; index -= index & -index) {
                sum += bit[index];
            }
            return sum;
        }
        public int rangeQuery(int left, int right) {
            return query(right) - query(left - 1);
        }
    }

    public static int[] dijkstra(int n, ArrayList<int[]>[] adj, int start) {
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));
        pq.offer(new int[]{start, 0});
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int u = curr[0], d = curr[1];
            if (d > dist[u]) continue;
            for (int[] edge : adj[u]) {
                int v = edge[0], weight = edge[1];
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.offer(new int[]{v, dist[v]});
                }
            }
        }
        return dist;
    }

    public static long pow(long base, long exp) {
        long result = 1; long b = base;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = result * b % mod;
            }
            b = b * b % mod; exp >>= 1;
        }
        return result;
    }
    public static long pow(long base, long exp, long p) {
        long result = 1; long b = base;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = result * b % p;
            }
            b = b * b % p; exp >>= 1;
        }
        return result;
    }
    public static long[] computeFactorials(int n) {
        long[] fact = new long[n+1]; fact[0]=1;
        for (int i = 1; i <= n; i ++) {
            fact[i]=fact[i-1]*i%mod;
        }
        return fact;
    }
    public static long inv(long x) {
        return pow(x,mod-2);
    }
    public static long inv(long x, long p) {
        long result = 1; long b = x; long exp=p-2;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = result * b % p;
            }
            b = b * b % p;
            exp >>= 1;
        }
        return result;
    }
    public static long[] computeInverses(int n) {
        long[] fact = new long[n + 1]; long[] invFact = new long[n + 1]; long[] inv = new long[n + 1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % mod;
        }
        invFact[n] = pow(fact[n], mod - 2);
        for (int i = n; i > 0; i--) {
            invFact[i - 1] = invFact[i] * i % mod;
        }
        for (int i = 1; i <= n; i++) {
            inv[i] = invFact[i] * fact[i - 1] % mod;
        }
        return Arrays.copyOfRange(inv, 1, n + 1);
    }
    public static long nCr(int a, int b) {
        long res = fact[a];
        res*= inv(fact[b]);
        res%=mod;
        res *= inv(fact[a-b]);
        res%=mod;
        return res;
    }
    public static long nCr(int a, int b, long[] fact, long[] invFact) {
        long res = fact[a];
        res*= invFact[b];
        res%=mod;
        res *= invFact[a-b];
        res%=mod;
        return res;
    }
    public static long gcd(long a, long b) {
        if(b == 0) {return a;}
        return gcd(b, a % b);
    }
    public static long lcm(long a, long b) {
        return a * (b / gcd(a, b));
    }
    public static long crt(long[] nums, long[] rems) {
        long prod = 1;
        for (long num : nums) {
            prod *= num;
        }

        long result = 0;
        for (int i = 0; i < nums.length; i++) {
            long pp = prod / nums[i];
            result += rems[i] * inv(pp, nums[i]) * pp;
            result %= prod;
        }

        return result;
    }
    public static long fibonacci(long n) {
        if (n <= 1) return n;
        long[][] F = {{1, 1}, {1, 0}};
        matrixExp(F, n - 1);
        return F[0][0];
    }

    public static void matrixExp(long[][] F, long n) {
        if (n <= 1) return;
        long[][] M = {{1, 1}, {1, 0}};
        matrixExp(F, n / 2);
        long[][] result = matrixMultiply(F, F);
        for (int i = 0; i < F.length; i++) {     
            System.arraycopy(result[i], 0, F[i], 0, F.length);
        }
        if (n % 2 != 0) {
            result = matrixMultiply(F, M); 
            for (int i = 0; i < F.length; i++) { 
                System.arraycopy(result[i], 0, F[i], 0, F.length);
            }
        }
    }

    public static long[][] matrixMultiply(long[][] A, long[][] B) {
        int n = A.length;
        long[][] C = new long[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
                }
            }
        }
        return C;
    }

    
}

    }

    //CUSTOM COMPARATOR
    static class Triple implements Comparable<Triple> {
        public int x,y,z;
        public Triple(int x, int y, int z) {
            this.x=x;
            this.y=y;
            this.z=z;
        }

        @Override
        public int compareTo(Triple t) {
            if (x != t.x) {
                return x-t.x;
            }
            if (y != t.y) {
                return y-t.y;
            }
            return z-t.z;
        }
    }


    //COORDINATE COMPRESSION

    static int[] rank(int[] arr) {
        int n = arr.length;
        Integer[] indices = new Integer[n];
        for (int i = 0; i < n; i++) indices[i] = i;
        Arrays.sort(indices, (a, b) -> Integer.compare(arr[a], arr[b]));
        int[] ranked = new int[n];
        for (int i = 0; i < n; i++) ranked[indices[i]] = i + 1;
        return ranked;
    }

    //Finds minimum value such that a condition is true
    static int binSearchMin(int lo, int hi) {
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;
            // if (condition(mid) == true) {hi=mid;}
            //else {lo = mid + 1;}
        }
        return lo;
    }

    //Finds maximum value such that a condition is true
    static int binSearchMax(int lo, int hi) {
        while (lo < hi) {
            int mid = lo + (hi - lo + 1)/2;
            // if (condition(mid) == true) {hi=mid;}
            //else {hi = mid-1;}
            
        }
        return lo;
    }

    //Longest Common Subsequence
    public static int longestCommonSubsequence(String s1, String s2) {
        int m = s1.length(), n = s2.length();
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = s1.charAt(i - 1) == s2.charAt(j - 1) 
                           ? dp[i - 1][j - 1] + 1 
                           : Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
    //DSU
    static class DSU {
        int[] parent;
        int[] rank;
        public DSU(int n) {
            parent = new int[n]; rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i; rank[i] = 0;
            }
        }
        public int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        public int union(int a, int b) {
            int rootA = find(a); int rootB = find(b);
            if (rootA == rootB) {return 0;}
            if (rank[rootA] > rank[rootB]) {
                parent[rootB] = rootA;
            } else if (rank[rootA] < rank[rootB]) {
                parent[rootA] = rootB;
            } else {
                parent[rootB] = rootA;
                rank[rootA]++;
            }
            return 1;
        }
    }

    static class BIT {
        int[] bit;
        int n;
        public BIT(int size) {
            this.n = size;
            this.bit = new int[n+1];
        }
        public void update (int index, int value) {
            for (; index <= n; index += index & -index) {
                bit[index] += value;
            }
        }
        public int query(int index) { //Prefix sum from 1 to index
            int sum = 0;
            for (; index > 0; index -= index & -index) {
                sum += bit[index];
            }
            return sum;
        }
        public int rangeQuery(int left, int right) {
            return query(right) - query(left - 1);
        }
    }

    public static int[] dijkstra(int n, ArrayList<int[]>[] adj, int start) {
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));
        pq.offer(new int[]{start, 0});
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int u = curr[0], d = curr[1];
            if (d > dist[u]) continue;
            for (int[] edge : adj[u]) {
                int v = edge[0], weight = edge[1];
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.offer(new int[]{v, dist[v]});
                }
            }
        }
        return dist;
    }

    public static long pow(long base, long exp) {
        long result = 1; long b = base;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = result * b % mod;
            }
            b = b * b % mod; exp >>= 1;
        }
        return result;
    }
    public static long pow(long base, long exp, long p) {
        long result = 1; long b = base;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = result * b % p;
            }
            b = b * b % p; exp >>= 1;
        }
        return result;
    }
    public static long[] computeFactorials(int n) {
        long[] fact = new long[n+1]; fact[0]=1;
        for (int i = 1; i <= n; i ++) {
            fact[i]=fact[i-1]*i%mod;
        }
        return fact;
    }
    public static long inv(long x) {
        return pow(x,mod-2);
    }
    public static long inv(long x, long p) {
        long result = 1; long b = x; long exp=p-2;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = result * b % p;
            }
            b = b * b % p;
            exp >>= 1;
        }
        return result;
    }
    public static long[] computeInverses(int n) {
        long[] fact = new long[n + 1]; long[] invFact = new long[n + 1]; long[] inv = new long[n + 1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % mod;
        }
        invFact[n] = pow(fact[n], mod - 2);
        for (int i = n; i > 0; i--) {
            invFact[i - 1] = invFact[i] * i % mod;
        }
        for (int i = 1; i <= n; i++) {
            inv[i] = invFact[i] * fact[i - 1] % mod;
        }
        return Arrays.copyOfRange(inv, 1, n + 1);
    }
    public static long nCr(int a, int b) {
        long res = fact[a];
        res*= inv(fact[b]);
        res%=mod;
        res *= inv(fact[a-b]);
        res%=mod;
        return res;
    }
    public static long nCr(int a, int b, long[] fact, long[] invFact) {
        long res = fact[a];
        res*= invFact[b];
        res%=mod;
        res *= invFact[a-b];
        res%=mod;
        return res;
    }
    public static long gcd(long a, long b) {
        if(b == 0) {return a;}
        return gcd(b, a % b);
    }
    public static long lcm(long a, long b) {
        return a * (b / gcd(a, b));
    }
    public static long crt(long[] nums, long[] rems) {
        long prod = 1;
        for (long num : nums) {
            prod *= num;
        }

        long result = 0;
        for (int i = 0; i < nums.length; i++) {
            long pp = prod / nums[i];
            result += rems[i] * inv(pp, nums[i]) * pp;
            result %= prod;
        }

        return result;
    }
    public static long fibonacci(long n) {
        if (n <= 1) return n;
        long[][] F = {{1, 1}, {1, 0}};
        matrixExp(F, n - 1);
        return F[0][0];
    }

    public static void matrixExp(long[][] F, long n) {
        if (n <= 1) return;
        long[][] M = {{1, 1}, {1, 0}};
        matrixExp(F, n / 2);
        long[][] result = matrixMultiply(F, F);
        for (int i = 0; i < F.length; i++) {     
            System.arraycopy(result[i], 0, F[i], 0, F.length);
        }
        if (n % 2 != 0) {
            result = matrixMultiply(F, M); 
            for (int i = 0; i < F.length; i++) { 
                System.arraycopy(result[i], 0, F[i], 0, F.length);
            }
        }
    }

    public static long[][] matrixMultiply(long[][] A, long[][] B) {
        int n = A.length;
        long[][] C = new long[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
                }
            }
        }
        return C;
    }

    
}
