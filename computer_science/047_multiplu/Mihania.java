import java.io.*;
import java.util.*;
import java.math.*;

public class Mihania {
    private static String solve(String N) {
        int[] m = new int[N.length()];
        int sum = 0;
        for (int i = 0; i < m.length; i++) {
            m[i] = N.charAt(i) - '0';
            sum += m[i];
        }

        int d = sum % 3;
        if (d == 0) {
            d = 3;
        }

        boolean found = false;
        for (int i = 0; i < m.length; i++) {
            if (maxInc(m[i], d) != m[i]) {
                m[i] = maxInc(m[i], d);
                found = true;
                break;
            }
        }

        if (!found) {
            for (int i = m.length -1; i >= 0; i--) {
                if (minDec(m[i], d) != m[i]) {
                    m[i] = minDec(m[i], d);
                    break;
                }
            }
        }

        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < m.length; i++) {
            builder.append(m[i]);
        }

        return builder.toString();
    }

    private static int maxInc(int v, int d) {
        if (v + d > 9) {
            return v;
        }

        int k = (9 - v) / d;
        return v + k * d;
    }

    private static int minDec(int v, int d) {
        if (v < d) {
            return v;
        }

        return v - d;
    }

    public static void main(String[] args) throws Exception {
        List<Test> tests = loadTests();
        BufferedWriter testOut = null;
        try {
            testOut = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("TESTS.MIHANIA.OUT"), "utf-8"));
            for (int i = 0; i < tests.size(); i++) {
                Test test = tests.get(i);
                testOut.append(solve(test.N));
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
                test.N = scanner.nextLine();
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
        String N;
        String Mmax;

        @Override
        public String toString() {
            return String.format("(N=%s)", N);
        }
    }
}