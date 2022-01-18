import java.io.*;
import java.util.*;
import java.math.*;

public class Mihania {
    private static int solve(int N, int K, int P, int[] A) {
        for (int i = A.length - 1; i >= 0; i--) {
            if (P == N) {
                // Dan lost
                P = A[i];
            } else if (A[i] <= P) {

                // smbd before Dan in rating lost
                P++;
            }
        }

        return P;
    }

    public static void main(String[] args) throws Exception {
        List<Test> tests = loadTests();
        BufferedWriter testOut = null;
        try {
            testOut = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("TESTS.MIHANIA.OUT"), "utf-8"));
            for (int i = 0; i < tests.size(); i++) {
                Test test = tests.get(i);
                testOut.append(String.valueOf(solve(test.N, test.K, test.P, test.A)));
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
                test.N = scanner.nextInt();
                scanner.skip(" ");
                test.K = scanner.nextInt();
                scanner.skip(" ");
                test.A = new int[scanner.nextInt()];
                for (int j = 0; j < test.A.length; j++) {
                    test.A[j] = scanner.nextInt();
                    if (j != test.A.length - 1) {
                        scanner.skip(" ");
                    }
                }

                scanner.nextLine();
                test.P = scanner.nextInt();

                if (i != n - 1) {
                    scanner.nextLine();
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
        int N;
        int K;
        int P; // last rating
        int[] A; // protocol of competion

        @Override
        public String toString() {
            return String.format("(N=%d K=%d A=%s)", N, K, Arrays.toString(A));
        }
    }
}