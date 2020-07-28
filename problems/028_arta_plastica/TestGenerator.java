import java.io.*;
import java.util.*;
import java.math.*;
import java.util.stream.*;

public class TestGenerator {
    public static void main(String[] args) throws Exception {
        List<Test> tests = loadTests();
        BufferedWriter testIn = null;
        BufferedWriter testOut = null;
        try {
            testIn = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("TESTS.IN"), "utf-8"));
            testOut = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("TESTS.OUT"), "utf-8"));
            testIn.append(String.valueOf(tests.size()));
            testIn.newLine();
            for (int i = 0; i < tests.size(); i++) {
                Test test = tests.get(i);
                testIn.append(String.format("%d %d", test.W, test.H));
                testIn.newLine();
                testIn.append(String.format("%d", test.n));
                testIn.newLine();
                for (int j = 0; j < test.rects.length; j++) {
                    testIn.append(String.format("%d %d %d %d", test.rects[j][0], test.rects[j][1], test.rects[j][2], test.rects[j][3]));
                    if (j != test.rects.length - 1) {
                        testIn.newLine();
                    }
                }

                testOut.append(String.valueOf(test.expectedResult));
                if (i != tests.size() - 1) {
                    testIn.newLine();
                    testOut.newLine();
                }
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