import java.io.*;   // Import the FileWriter class
import java.util.*;

public class TestGenerator {
    public static void main(String[] args) throws Exception {
        List<Test> tests = generateTests();
        BufferedWriter testIn = null;
        BufferedWriter testOut = null;
        try {
            testIn = new BufferedWriter(
                    new OutputStreamWriter(
                            new FileOutputStream("TEST1.IN"), "utf-8"));

            testOut = new BufferedWriter(
                    new OutputStreamWriter(
                            new FileOutputStream("TEST1.OUT"), "utf-8"));
            testIn.append(String.valueOf(tests.size()));
            testIn.newLine();
            for (Test test : tests) {
                testIn.append(String.valueOf(test.number));
                testIn.newLine();
                testOut.append(test.expectedString);
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
        for (int i = 100; i <= 999; i++) {
            Test test = new Test();
            test.number = i;
            test.expectedString = solve(test.number);
            result.add(test);
        }

        return result;
    }

    private static String solve(int number) {
        while (number > 9) {
            int sum = 0;
            while (number > 0) {
                sum += number % 10;
                number /= 10;
            }

            number = sum;
        }

        final String result;
        switch (number) {
            case 7:
                result = "norocos";
                break;
            case 8:
                result = "vorbaret";
                break;
            case 9:
                result = "inteligent";
                break;
            default:
                result = "obisnuit";
        }

        return result;
    }

    private static class Test {
        private int number;
        private String expectedString;
    }
}