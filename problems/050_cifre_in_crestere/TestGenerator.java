import java.io.*;   // Import the FileWriter class
import java.util.*;

public class TestGenerator {
    private static Random random = new Random();

    private static int solve(String A, String B) {
        int a = Integer.parseInt(A);
        int b = Integer.parseInt(B);
        int res = 0;
        for (int k = a; k <= b; k++) {
            if (isNonDecreasing(k)) {
                res++;
            }
        }

        return res;
    }

    private static boolean isNonDecreasing(int k) {
        String s = String.valueOf(k);
        int i = 1;
        for (; i < s.length() && s.charAt(i - 1) <= s.charAt(i); i++);
        return i == s.length();
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
                testIn.append(String.format("%s %s", test.A, test.B));
                testOut.append(String.valueOf(solve(test.A, test.B)));
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
        int N = 10000;
        for (int i = 0; i < N; i++) {
            Test test = new Test();
            int A = random.nextInt(i + 1) + 1;
            int B = A + random.nextInt(i + 1) + 1;
            test.A = String.valueOf(A);
            test.B = String.valueOf(B);
            result.add(test);
        }

        return result;
    }

    private static class Test {
        String A;
        String B;

        @Override
        public String toString() {
            return String.format("(A=%s B=%s)", A, B);
        }
    }
}