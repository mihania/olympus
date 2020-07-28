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
        boolean success = true;
        for (Test test : tests) {
            int realResult = solve(test.W, test.H, test.rects);
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
        final String testCasesFolderName = "tests_arta";
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
            result.W = scanner.nextInt();
            scanner.skip(" ");
            result.H = scanner.nextInt();
            result.n = scanner.nextInt();
            result.rects = new int[result.n][4];
            for (int i = 0; i < result.n; i++) {
                for (int j = 0; j < 4; j++) {
                    result.rects[i][j] = scanner.nextInt();
                    if (j != 3) {
                        scanner.skip(" ");
                    }
                }
            }
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

            return String.format("%s (W=%d H=%d n=%d rect=%s)", testId, W, H, n, rectBuilder.toString());
        }
    }
}