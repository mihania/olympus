import java.io.*;
import java.util.*;
import java.math.*;
import java.util.stream.*;

public class Mihania {

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
        List<Test> tests = loadTests();
        BufferedWriter testOut = null;
        try {
            testOut = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("TESTS.MIHANIA.OUT"), "utf-8"));
            for (int i = 0; i < tests.size(); i++) {
                Test test = tests.get(i);
                testOut.append(String.format("%.4f", solve(test.P)));
                testOut.newLine();
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
                test.P = new int[scanner.nextInt()][2];
                for (int k = 0; k < test.P.length; k++) {
                    test.P[k][0] = scanner.nextInt();
                    scanner.skip(" ");
                    test.P[k][1] = scanner.nextInt();
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
