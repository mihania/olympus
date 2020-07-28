import java.io.*;
import java.util.*;
import java.math.*;
import java.util.stream.*;

public class Mihania {
    private static int solve(String S) {
        if (S.length() == 0) {
            return 0;
        }

        BigInteger[] m = new BigInteger[S.length()];
        BigInteger TEN = new BigInteger("10");
        BigInteger mult = BigInteger.ONE;
        for (int i = S.length() - 1; i > 0; i--) {
            m[i] = convert(S, i).multiply(mult).add(i == S.length() - 1 ? BigInteger.ZERO : m[i + 1]);
            mult = mult.multiply(TEN);
        }

        BigInteger cur = convert(S, 0);
        int res = 0;
        for (int i = 1; i < S.length() - 1; i++) {
            if (cur.compareTo(m[i]) <= 0) {
                if (S.charAt(i) != '0') {
                    res++;
                }
            } else {
                break;
            }

            cur = cur.multiply(TEN).add(convert(S, i));
        }

        return res;
    }

    private static BigInteger convert(String S, int i) {
        return new BigInteger(String.valueOf(S.charAt(i)));
    }

    public static void main(String[] args) throws Exception {
        List<Test> tests = loadTests();
        boolean success = true;
        for (Test test : tests) {
            int realResult = solve(test.S);
            if (!Objects.equals(realResult, test.expectedResult)) {
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

    private static List<Test> loadTests() throws Exception {
        final String testCasesFolderName = "tests_pagini";
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
            result.S = scanner.nextLine();
        } finally {
            if (scanner != null) {
                scanner.close();
            }
        }

        return result;
    }

    private static int readOutput(File file) throws Exception {
        Scanner scanner = null;
        try {
            scanner = new Scanner(file);
            return scanner.nextInt();
        } finally {
            if (scanner != null) {
                scanner.close();
            }
        }
    }

    private static class Test {
        String testId;
        String S;
        int expectedResult;

        @Override
        public String toString() {
            return String.format("%s (S=%s)", testId, S);
        }
    }
}