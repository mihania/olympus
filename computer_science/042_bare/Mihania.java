import java.io.*;
import java.util.*;
import java.math.*;

public class Mihania {
    private static int solve(int L, int[] D) {
        int[] dp = new int[L + 1];
        Arrays.fill(dp, L);
        dp[0] = 0;
        for (int i = 0; i < L; i++) {
            if (i > 0) {
                dp[i] = Math.min(dp[i], dp[i - 1] + 1);
            }

            for (int d : D) {
                if (i + d <= L) {
                    dp[i + d] = Math.min(dp[i + d], dp[i]);
                }
            }
        }

        return dp[L];
    }

    public static void main(String[] args) throws Exception {
        List<Test> tests = loadTests();
        BufferedWriter testOut = null;
        try {
            testOut = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("TESTS.MIHANIA.OUT"), "utf-8"));
            for (int i = 0; i < tests.size(); i++) {
                Test test = tests.get(i);
                testOut.append(String.valueOf(solve(test.L, test.D)));
                if (i != tests.size() - 1) {
                    testOut.newLine();
                }
            }
        } finally {
            if (testOut != null) {
                testOut.close();
            }
        }
    }

    private static List<Test> loadTests() throws Exception {
        final File file = new File("TESTS.IN");
        Scanner scanner = null;
        List<Test> result = new ArrayList<>();
        try {
            scanner = new Scanner(file);
            int N = Integer.parseInt(scanner.nextLine());
            for (int i = 0; i < N; i++) {
                Test test = new Test();
                test.L = scanner.nextInt();
                scanner.skip(" ");
                int K = scanner.nextInt();
                scanner.nextLine();
                test.D = new int[K];
                for (int j = 0; j < K; j++) {
                    test.D[j] = scanner.nextInt();
                    if (j != K - 1) {
                        scanner.skip(" ");
                    }
                }

                result.add(test);

                if (i != N - 1) {
                    scanner.nextLine();
                }
            }
        } finally {
            if (scanner != null) {
                scanner.close();
            }
        }

        return result;
    }

    private static class Test {
        int L;
        int[] D;
        int expectedResult;

        @Override
        public String toString() {
            return String.format("(L=%d D=%s)", L, Arrays.toString(D));
        }
    }
}