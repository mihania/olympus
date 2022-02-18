import java.io.*;
import java.util.*;
import java.math.*;

public class Mihania {

    /**
     * Time complexity: O(N^4)
     * @param P
     * @return
     */
    private static int solveN4(int[][] P) {
        int res = 0;
        for (int i = 0; i < P.length; i++) {
            for (int j = 0; j < P.length; j++) {
                if (i != j && P[i][2] == P[j][2]) {
                    double dist = dist(P[i], P[j]);
                    for (int k = 0; k < P.length; k++) {
                        if (i != k && j != k && P[i][2] == P[k][2] && dist(P[j], P[k]) == dist) {
                            for (int l = 0; l < P.length; l++) {
                                if (i != l && j != l && k != l && P[i][2] == P[l][2]
                                        && dist(P[l], P[k]) == dist
                                        && dist(P[l], P[i]) == dist
                                        && dist(P[i], P[k]) == dist(P[j], P[l])) {
                                    // System.out.printf("i=%d j=%d k=%d l=%d res=%d\n", i, j, k, l, res);
                                    res++;
                                }
                            }
                        }
                    }
                }
            }
        }

        // dividing by 8 because we can go around the square 8 times (4 times clockwise, 4 times counterclockwise)
        return res / 8;
    }

    /**
     * Time complexity: O(N^2)
     * @param P
     * @return
     */
    private static int solveN2(int[][] P) {
        Set<String> set = new HashSet<>();
        for (int[] point : P) {
            set.add(Arrays.toString(point));
        }

        int res = 0;
        for (int i = 0; i < P.length; i++) {
            for (int j = i + 1; j < P.length; j++) {

                // P[i] and P[j] - are points of square main diagonal (the diagonal that goes from SW to NE)
                if (P[i][0] <= P[j][0] && P[i][1] < P[j][1]) {

                    // checking that points color matching.
                    if (P[i][2] == P[j][2]) {

                        // calculations are done based on https://www.quora.com/Given-two-diagonally-opposite-points-of-a-square-how-can-I-find-out-the-other-two-points-in-terms-of-the-coordinates-of-the-known-points
                        int m1 = P[i][0] + P[j][0] + P[j][1] - P[i][1];
                        int m2 = P[i][1] + P[j][1] + P[i][0] - P[j][0];
                        int m3 = P[i][0] + P[j][0] + P[i][1] - P[j][1];
                        int m4 = P[i][1] + P[j][1] + P[j][0] - P[i][0];
                        if (m1 % 2 == 0 && m2 % 2 == 0 && m3 % 2 == 0 && m4 % 2 == 0) {
                            int[] b = new int[]{m1 / 2, m2 / 2, P[i][2]};
                            int[] d = new int[]{m3 / 2, m4 / 2, P[i][2]};
                            if (set.contains(Arrays.toString(b)) && set.contains(Arrays.toString(d))) {
                                res++;
                            }

                            // System.out.printf("A=%s C=%s B=%s D=%s res=%d\n", Arrays.toString(P[i]), Arrays.toString(P[j]), Arrays.toString(b), Arrays.toString(d), res);
                        }
                    }
                }
            }
        }

        return res;
    }

    private static double dist(int[] a, int[] b) {
        return Math.pow(a[0] - b[0], 2) + Math.pow(a[1] - b[1], 2);
    }

    public static void main(String[] args) throws Exception {
        List<Test> tests = loadTests();
        BufferedWriter testOut = null;
        try {
            testOut = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("TESTS.MIHANIA.OUT"), "utf-8"));
            for (int i = 0; i < tests.size(); i++) {
                // System.out.printf("Starting test %d\n", i);
                Test test = tests.get(i);
                testOut.append(String.valueOf(solveN2(test.P)));
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
            int T = scanner.nextInt();
            // System.out.printf("T=%d\n", T);
            for (int k = 0; k < T; k++) {
                int N = scanner.nextInt();
                // System.out.printf("N=%d\n", N);
                Test test = new Test();
                test.P = new int[N][3];
                for (int i = 0; i < N; i++) {
                    int x = scanner.nextInt();
                    scanner.skip(" ");
                    int y = scanner.nextInt();
                    scanner.skip(" ");
                    int c = scanner.nextInt();
                    test.P[i][0] = x;
                    test.P[i][1] = y;
                    test.P[i][2] = c;
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