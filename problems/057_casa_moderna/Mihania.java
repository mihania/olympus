import java.io.*;
import java.util.*;
import java.math.*;

public class Mihania {

    private static void solveN2(Test test) {
        int sum = 0;
        int[][] m = new int[test.P.length][3];
        for (int i = 0; i < test.P.length; i++) {
            m[i][0] = test.P[i][0];
            m[i][1] = test.P[i][1];
            m[i][2] = i + 1;
            sum += test.P[i][1];
        }

        Arrays.sort(m, (a, b) -> a[0] - b[0]);

        int MAX = 25;
        // dp[i][j] - max hour required to complete tasks to achieve j profit or MAX if not possible.
        int[][] dp = new int[test.P.length][sum + 1];
        List<Integer>[][] plan = new List[test.P.length][sum + 1];

        for (int i  = 0; i < dp.length; i++) {
            Arrays.fill(dp[i], MAX);
        }

        for (int i = 0; i < dp.length; i++) {
            int time = m[i][0];
            int profit = m[i][1];

            for (int j = dp[0].length - 1; j >= 1; j--) {
                if (i > 0 && dp[i - 1][j] != MAX) {
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][j]);
                    plan[i][j] = new ArrayList<>(plan[i - 1][j]);
                }

                if (dp[i][j] != MAX && dp[i][j] + 1 <= time && dp[i][j] + 1 < dp[i][j + profit] ) {
                    dp[i][j + profit] = Math.min(dp[i][j + profit], dp[i][j] + 1);
                    plan[i][j + profit] = new ArrayList<>(plan[i][j]);
                    plan[i][j + profit].add(m[i][2]);
                }
            }

            dp[i][profit] = 1;
            plan[i][profit] = new ArrayList<>();
            plan[i][profit].add(m[i][2]);
        }

        int maxSum = 0;
        int maxI = 0;
        int maxJ = 0;
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[0].length; j++) {
                if (dp[i][j] != MAX) {
                    if (j > maxSum) {
                        maxSum = j;
                        maxI = i;
                        maxJ = j;
                    }
                }
            }
        }


        test.s = maxSum;
        test.pMin = sum - test.s;
        test.plan = plan[maxI][maxJ];
    }

    private static void solve(Test test) {
        int[][] m = new int[test.P.length][3];
        int sum = 0;
        for (int i = 0; i < m.length; i++) {
            m[i][0] = i + 1;
            m[i][1] = test.P[i][0];
            m[i][2] = test.P[i][1];
            sum += test.P[i][1];
        }

        Arrays.sort(m, (a, b) -> (a[1] - b[1]));
        dfs(m, 0, 1, new ArrayList<>(), 0, test);
        test.pMin = sum - test.s;
    }

    private static void dfs(int[][] m, int idx, int curHour, List<Integer> plan, int curSum, Test test) {
        // System.out.printf("idx=%d curHour=%d plan=%s, curSum=%d test.s=%d\n", idx, curHour, plan.toString(), curSum, test.s);
        if (idx == m.length) {
            if (curSum > test.s) {
                test.plan = new ArrayList<>(plan);
                test.s = curSum;
            }

            return;
        }

        dfs(m, idx + 1, curHour, plan, curSum, test);
        if (curHour <= m[idx][1]) {
            plan.add(m[idx][0]);
            dfs(m, idx + 1, curHour + 1, plan, curSum + m[idx][2], test);
            plan.remove(plan.size() - 1);
        }
    }

    public static void main(String[] args) throws Exception {
        List<Test> tests = loadTests();
        BufferedWriter testOut = null;
        try {
            testOut = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("TESTS.MIHANIA.OUT"), "utf-8"));
            for (int i = 0; i < tests.size(); i++) {
                Test test = tests.get(i);
                solveN2(test);
                testOut.append(String.valueOf(test.s));
                testOut.append(" ");
                testOut.append(String.valueOf(test.pMin));
                testOut.newLine();
                for (int k : test.plan) {
                    testOut.append(String.valueOf(k));
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
            int T = scanner.nextInt();
            // System.out.printf("T=%d\n", T);
            for (int k = 0; k < T; k++) {
                int N = scanner.nextInt();
                // System.out.printf("N=%d\n", N);
                Test test = new Test();
                test.P = new int[N][2];
                for (int i = 0; i < N; i++) {
                    test.P[i][0] = scanner.nextInt();
                    test.P[i][1] = scanner.nextInt();
                    // System.out.printf("P[%d]=%s\n", i, Arrays.toString(test.P[i]));
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
        int[][] P;
        int s;
        int pMin;
        List<Integer> plan = new ArrayList<>();

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < P.length; i++) {
                sb.append(Arrays.toString(P[i]));
            }

            return String.format("(P=%s)", sb.toString());
        }
    }
}