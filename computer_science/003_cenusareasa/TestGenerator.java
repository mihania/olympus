import java.io.*;
import java.util.*;
import java.math.*;
import java.util.stream.*;

public class TestGenerator {
    private static double solve(int[][] P) {
        double maxSqrDist = 0;
        for (int i = 0; i < P.length; i++) {
            for (int j = i + 1; j < P.length; j++) {
                maxSqrDist = Math.max(maxSqrDist, Math.pow(P[i][0] - P[j][0], 2) + Math.pow(P[i][1] - P[j][1], 2));
            }
        }

        return Math.sqrt(maxSqrDist);
    }

    public static void main(String[] args) throws Exception {
        List<Test> tests = generateTests(1000);
        BufferedWriter testIn = null;
        BufferedWriter testOut = null;
        try {
            testIn = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("tests.in"), "utf-8"));
            testOut = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("tests.expected.out"), "utf-8"));
            testIn.append(String.valueOf(tests.size()));
            testIn.newLine();
            for (int i = 0; i < tests.size(); i++) {
                Test test = tests.get(i);
                testIn.append(String.format("%d", test.P.length));
                testIn.newLine();
                for (int j = 0; j < test.P.length; j++) {
                    testIn.append(String.format("%d %d", test.P[j][0], test.P[j][1]));
                    testIn.newLine();
                }

                testOut.append(String.format("%.4f", solve(test.P)));
                testOut.newLine();
            }
        } finally {
            if (testIn != null) {
                testIn.close();
            }

            if (testOut != null) {
                testOut.close();
            }
        }
    }

    private static List<Test> generateTests(int N) {
        Random random = new Random();
        List<Test> result = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            Test test = new Test();
            test.P = new int[random.nextInt(i + 1) + 2][2];
            for (int j = 0; j < test.P.length; j++) {
                for (int k = 0; k < test.P.length; k++) {
                    test.P[k][0] = random.nextInt(i + 1) - random.nextInt(i + 1);
                    test.P[k][1] = random.nextInt(i + 1) - random.nextInt(i + 1);
                }
            }

            result.add(test);
        }

        return result;
    }

    private static class Test {
        int[][] P;

        @Override
        public String toString() {
            StringBuilder rectBuilder = new StringBuilder();
            if (P != null) {
                for (int i = 0; i < P.length; i++) {
                    rectBuilder.append(Arrays.toString(P[i]));
                }
            }

            return String.format("P=%s", P.toString());
        }
    }
}
