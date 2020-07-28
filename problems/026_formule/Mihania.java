import java.io.*;
import java.util.*;
import java.math.*;
import java.util.stream.*;

public class Mihania {
    private static String solve(String S) throws Exception {
        int state = 0;
        for (int i = 0; i < S.length(); i++) {
            char ch = S.charAt(i);
            switch (state) {
                case 0:
                    if (Character.isDigit(ch)) {
                        state = 1;
                    } else {
                        state = 4;
                    }
                    break;
                case 1:
                    if (isSign(ch)) {
                        state = 2;
                    } else if (!Character.isDigit(ch)) {
                        state = 4;
                    }
                    break;
                case 2:
                    if (Character.isDigit(ch)) {
                        state = 1;
                    } else {
                        state = 4;
                    }
                    break;
                default:
                    break;
            }
        }

        return state == 1 ? "1" : "0";
    }

    private static boolean isSign(char ch) {
        return ch == '+' || ch == '-' || ch == '/' || ch == '*';
    }

    public static void main(String[] args) throws Exception {
        List<Test> tests = loadTests();
        boolean success = true;
        for (Test test : tests) {
            String realResult = solve(test.S);
            if (!realResult.equals(test.expectedResult)) {
                System.out.printf(
                        "Test %s failed. Expected %s, but real was %s\n",
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
        final String testCasesFolderName = "tests_formule";
        final File testcasesFolder = new File(testCasesFolderName);
        final List<Test> result = new ArrayList<>();
        for (final File file : testcasesFolder.listFiles()) {
            final String fileName = file.getName();
            if (fileName.startsWith("input")) {
                String testId = fileName.substring(fileName.indexOf('.') + 1);
                List<Test> tests = readInput(file);
                readOutput(new File(testCasesFolderName, "output." + testId), tests);
                for (Test test : tests) {
                    test.testId = testId;
                }

                result.addAll(tests);
            }
        }

        // sort by testId in ascending order.
        return result.stream().sorted((a, b) -> a.testId.compareTo(b.testId)).collect(Collectors.toList());
    }

    private static List<Test> readInput(File file) throws Exception {
        Scanner scanner = null;
        List<Test> result = new ArrayList<>();
        try {
            scanner = new Scanner(file);
            int n = Integer.parseInt(scanner.nextLine());
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

    private static void readOutput(File file, List<Test> tests) throws Exception {
        Scanner scanner = null;
        try {
            scanner = new Scanner(file);
            for (Test test : tests) {
                test.expectedResult = scanner.nextLine();
            }
        } finally {
            if (scanner != null) {
                scanner.close();
            }
        }
    }

    private static class Test {
        String testId;
        String S;
        String expectedResult;

        @Override
        public String toString() {
            return String.format("%s (S=%s)", testId, S);
        }
    }
}