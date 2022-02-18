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

        return state == 1 ? "DA" : "NU";
    }

    private static boolean isSign(char ch) {
        return ch == '+' || ch == '-' || ch == '/' || ch == '*';
    }

    public static void main(String[] args) throws Exception {
        List<Test> tests = loadTests();
        BufferedWriter testOut = null;
        try {
            testOut = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("TESTS.MIHANIA.OUT"), "utf-8"));
            for (int i = 0; i < tests.size(); i++) {
                Test test = tests.get(i);
                testOut.append(solve(test.S));
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

    private static class Test {
        String S;

        @Override
        public String toString() {
            return String.format("(S=%s)", S);
        }
    }
}