import java.io.*;   // Import the FileWriter class
import java.util.*;

public class TestGenerator {
    private static Random random = new Random();

    private static int solve(int N, int K) {

        // dp[i][j][0] - number of desirable subsets ending at index i of size j without element 1
        // dp[i][j][1] - number of desirable subsets ending at index i of size j with element 1
        long[][][] dp = new long[N + 1][K + 1][2];

        for (int i = 1; i <= N; i++) {

            // adding self element {i}
            dp[i][1][i == 1 ? 1 : 0] = 1;

            // traversing up to i - 2 to exclude adjancent element (i - 1), adjacent to i
            for (int k = 1; k < i - 1; k++) {
                for (int j = 2; j <= K; j++) {
                    dp[i][j][0] += dp[k][j - 1][0];
                    dp[i][j][1] += dp[k][j - 1][1];
                }
            }
        }

        int res = 0;
        for (int i = 1; i <= N; i++) {
            res += dp[i][K][0];

            // preventing N and 1 to be adjacent.
            if (i != N || N == 1) {
                res += dp[i][K][1];
            }
        }

        return res;
    }

    public static void main(String[] args) throws Exception {
        List<Test> tests = generateTests();
        BufferedWriter testIn = null;
        BufferedWriter testOut = null;
        try {
            testIn = new BufferedWriter(
                    new OutputStreamWriter(
                            new FileOutputStream("TESTS.IN"), "utf-8"));

            testOut = new BufferedWriter(
                    new OutputStreamWriter(
                            new FileOutputStream("TESTS.OUT"), "utf-8"));
            testIn.append(String.valueOf(tests.size()));
            testIn.newLine();
            for (int i = 0; i < tests.size(); i++) {
                Test test = tests.get(i);
                testIn.append(String.format("%s %s", test.N, test.K));
                testOut.append(String.valueOf(solve(test.N, test.K)));
                testIn.newLine();
                testOut.newLine();
            }
        } finally {
            try {
                if (testIn != null) {
                    testIn.close();
                }
            } catch (Exception ex) {
            }

            try {
                if (testOut != null) {
                    testOut.close();
                }
            } catch (Exception ex) {
            }
        }
    }

    private static List<Test> generateTests() {
        List<Test> result = new ArrayList<>();
        int N = 20;
        for (int n = 1; n < N; n++) {
            for (int k = 1; k <= n; k++) {
                Test test = new Test(n, k);
                result.add(test);
            }
        }

        return result;
    }

    private static class Test {
        int N;
        int K;

        public Test(int N, int K) {
            this.N = N;
            this.K = K;
        }

        @Override
        public String toString() {
            return String.format("(N=%d K=%d)", N, K);
        }
    }
}