import java.io.*;
import java.util.*;
import java.math.*;
import java.util.stream.*;

public class Mihania {
    private static int solve(int W, int H, int[][] rects) {
        int res = 0;
        for (int x = 0; x < W; x++) {
            for (int y = 0; y < H; y++) {
                boolean filled = false;
                for (int[] rect : rects) {
                    if (x >= rect[0] && x < rect[2] && y >= rect[1] && y < rect[3]) {
                        filled = true;
                        break;
                    }
                }

                if (!filled) {
                    res++;
                }
            }
        }

        return res;
    }

    public static void main(String[] args) throws Exception {
        List<Test> tests = loadTests();
        BufferedWriter testOut = null;
        try {
            testOut = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("TESTS.MIHANIA.OUT"), "utf-8"));
            for (int i = 0; i < tests.size(); i++) {
                Test test = tests.get(i);
                testOut.append(String.valueOf(solve(test.W, test.H, test.rects)));
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
        Scanner scanner = null;
        List<Test> result = new ArrayList<>();
        try {
            scanner = new Scanner(file);
            int N = Integer.parseInt(scanner.nextLine());
            for (int i = 0; i < N; i++) {
                Test test = new Test();
                test.W = scanner.nextInt();
                scanner.skip(" ");
                test.H = scanner.nextInt();
                test.n = scanner.nextInt();
                test.rects = new int[test.n][4];
                for (int k = 0; k < test.rects.length; k++) {
                    for (int j = 0; j < 4; j++) {
                        test.rects[k][j] = scanner.nextInt();
                        if (j != 3) {
                            scanner.skip(" ");
                        }
                    }

                    if (k != test.rects.length - 1) {
                        scanner.nextLine();
                    }
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
        int W;
        int H;
        int n;
        int[][] rects;
        int expectedResult;

        @Override
        public String toString() {
            StringBuilder rectBuilder = new StringBuilder();
            if (rects != null) {
                for (int i = 0; i < rects.length; i++) {
                    rectBuilder.append(Arrays.toString(rects[i]));
                }
            }

            return String.format("(W=%d H=%d n=%d rect=%s)", W, H, n, rectBuilder.toString());
        }
    }
}