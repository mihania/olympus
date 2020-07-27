import java.io.*;
import java.util.*;
import java.math.*;
import java.util.stream.*;

public class Mihania {
    public static void main(String[] args) throws Exception {
        List<Test> tests = loadTests();
        boolean success = true;
        for (Test test : tests) {
            BigInteger realResult = solve(test.S, test.N);
            if (!realResult.equals(test.expectedResult)) {
                System.out.printf(
                        "Test %s failed. Expected %d, but real was %d\n",
                        test,
                        test.expectedResult,
                        realResult);
                success = false;
                break;
            } else {
                System.out.printf("Test %s passed.\n", test);
            }
        }

        if (success) {
            System.out.println("Success");
        }
    }

    private static BigInteger solve(int S, int N) {
        BigInteger[][] dp = new BigInteger[N + 1][N * S + 1];
        return gen(0, 0, N, S, dp);
    }

    private static BigInteger gen(int id, int start, int N, int S, BigInteger[][] dp) {
        BigInteger res;
        if (dp[id][start] != null) {
            res = dp[id][start];
        } else {
            if (id < N) {
                res = BigInteger.ZERO;
                for (int i = start; i < (id + 1) * S; i++) {
                    res = res.add(gen(id + 1, i + 1, N, S, dp));
                }
            } else {
                res = BigInteger.ONE;
            }

            dp[id][start] = res;
        }

        return res;
    }

    private static List<Test> loadTests() throws Exception {
        final String testCasesFolderName = "testcases";
        final File testcasesFolder = new File(testCasesFolderName);
        final List<Test> result = new ArrayList<>();
        for (final File file : testcasesFolder.listFiles()) {
            final String fileName = file.getName();
            if (fileName.startsWith("input")) {
                String testId = fileName.substring(fileName.indexOf('.') + 1);
                Test test = readInput(file);
                test.expectedResult = readOutput(new File(testCasesFolderName, "output." + testId));
                test.testId = testId;
                result.add(test);
            }
        }

        // sort by testId in ascending order.
        return result.stream().sorted((a, b) -> a.testId.compareTo(b.testId)).collect(Collectors.toList());
    }

    private static Test readInput(File file) throws Exception {
        Scanner scanner = null;
        Test result = new Test();
        try {
            scanner = new Scanner(file);
            result.S = scanner.nextInt();
            scanner.skip(" ");
            result.N = scanner.nextInt();
        } finally {
            if (scanner != null) {
                scanner.close();
            }
        }

        return result;
    }

    private static BigInteger readOutput(File file) throws Exception {
        Scanner scanner = null;
        try {
            scanner = new Scanner(file);
            return scanner.nextBigInteger();
        } finally {
            if (scanner != null) {
                scanner.close();
            }
        }
    }

    private static class Test {
        String testId;
        int S;
        int N;
        BigInteger expectedResult;

        @Override
        public String toString() {
            return String.format("%s (S=%d N=%d)", testId, S, N);
        }
    }
}