import java.io.*;
import java.util.*;
import java.math.*;

public class Mihania {
    private static int solve(int[] h, int[] a, int[] b, int[] f) {
        // dp[i] - maximum effectives of rockets block that starts at index i.
        int[] dp = new int[h.length];
        int res = 0;
        for (int i = 0; i < dp.length; i++) {
            dp[i] = f[i];
        }

        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < i; j++) {
                if (h[i] >= a[j] && h[i] <= b[j]) {
                    dp[i] = Math.max(dp[i], dp[j] + f[i]);
                    res = Math.max(res, dp[i]);
                }
            }
        }

        return res;
    }

    public static void main(String[] args) throws Exception {
        List<Test> tests = loadTests();
        BufferedWriter testOut = null;
        try {
            testOut = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("TESTS.MIHANIA.OUT"), "utf-8"));
            for (int i = 0; i < tests.size(); i++) {
                Test test = tests.get(i);
                testOut.append(String.valueOf(solve(test.h, test.a, test.b, test.f)));
                testOut.newLine();
            }
        } finally {
            if (testOut != null) {
                testOut.close();
            }
        }
    }

    private static List<Test> loadTests() throws Exception {
        final File file = new File("TESTS.IN");
        final List<Test> result = new ArrayList<>();
        Scanner scanner = null;
        try {
            scanner = new Scanner(file);
            int tests = Integer.valueOf(scanner.nextLine());
            for (int i = 0; i < tests; i++) {
                Test test = new Test();
                int n = scanner.nextInt();
                test.h = new int[n];
                test.a = new int[n];
                test.b = new int[n];
                test.f = new int[n];
                for (int j = 0; j < n; j++) {
                    test.h[j] = scanner.nextInt();
                    test.a[j] = scanner.nextInt();
                    test.b[j] = scanner.nextInt();
                    test.f[j] = scanner.nextInt();
                }

                result.add(test);
            }
        } finally {
            if (scanner != null) {
                scanner.close();
            }
        }

        return result;
    }

    private static class Test {
        int[] h;
        int[] a;
        int[] b;
        int[] f;

        @Override
        public String toString() {
            return String.format(
                    "(h=%s a=%s b=%s f=%s)",
                    Arrays.toString(h),
                    Arrays.toString(a),
                    Arrays.toString(b),
                    Arrays.toString(f));
        }
    }
}