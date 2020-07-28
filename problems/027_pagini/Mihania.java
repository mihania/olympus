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
        BufferedWriter testOut = null;
        try {
            testOut = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("TESTS.MIHANIA.OUT"), "utf-8"));
            for (int i = 0; i < tests.size(); i++) {
                Test test = tests.get(i);
                testOut.append(String.valueOf(solve(test.S)));
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
        final List<Test> result = new ArrayList<>();
        Scanner scanner = null;
        try {
            scanner = new Scanner(file);
            int n = Integer.valueOf(scanner.nextLine());
            for (int i = 0; i < n; i++) {
                Test test = new Test();
                test.S = scanner.nextLine();
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
        String S;
        int expectedResult;

        @Override
        public String toString() {
            return String.format("(S=%s)", S);
        }
    }
}