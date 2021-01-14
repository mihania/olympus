public class Main {
    private static long gcd(long a, long b) {
        if (a < b) {
            return gcd(b, a);
        }
        
        if (b == 0) {
            return a;
        }
        
        return gcd(a - b, b);
    }
    
    public static void main(String[] args) {
        long c = 3121;
        List<long[]> res = new ArrayList<>();
        for (int m = 1; m <= Math.sqrt(c); m++) {
            long n2 = c - m * m;
            long n = (int)Math.sqrt(n2);
            if (n * n == n2 && m > n && gcd(m, n) == 1 && (m - n) % 2 == 1) {
                long a = m * m - n * n;
                long b = 2 * m * n;                        
                if (b < a) {
                    long tmp = a;
                    a = b;
                    b = tmp;
                }
                
                res.add(new long[] {a, b});                
            }
        }
        
        Collections.sort(res, (a, b) -> (int)(a[0] - b[0]));
        for (long[] ab : res) {
            System.out.printf("%d %d %d\n", ab[0], ab[1], c);
        }
    }
}
