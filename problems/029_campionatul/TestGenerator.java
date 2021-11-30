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
            testIn = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("tests.in"), "utf-8"));
            testOut = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("tests.expected.out"), "utf-8"));
            testIn.append(String.valueOf(tests.size()));
            testIn.newLine();
            for (int i = 0; i < tests.size(); i++) {
                Test test = tests.get(i);
                testIn.append(String.format("%d %d", test.m.size(), test.s));
		testIn.newLine();
		if (i == 0) {
			System.out.println(test.m);
		}

                for (long s : test.m) {
			testIn.append(String.valueOf(s));
			testIn.append(" ");
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
        final String testCasesFolderName = "testcases_campionat";
        final File testcasesFolder = new File(testCasesFolderName);
        final List<Test> result = new ArrayList<>();
        for (final File file : testcasesFolder.listFiles()) {
            final String fileName = file.getName();
            if (fileName.startsWith("input")) {
		int startIndex = fileName.indexOf('.') + 1;
                String testId = fileName.substring(startIndex);
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
            result.n = scanner.nextInt();
	    result.s = scanner.nextLong(); 
            scanner.nextLine();
	    for (int i = 0; i < result.n; i++) {
            	result.m.add(scanner.nextLong());
	    }
        } finally {
            if (scanner != null) {
                scanner.close();
            }
        }

        return result;
    }

    private static long readOutput(File file) throws Exception {
        Scanner scanner = null;
        try {
            scanner = new Scanner(file);
            return scanner.nextLong();
        } finally {
            if (scanner != null) {
                scanner.close();
            }
        }
    }

    private static class Test {
        String testId;
        int n;
	long s;
	List<Long> m = new ArrayList<>();
        long expectedResult;
	

        @Override
        public String toString() {
        	return null;
	}
    }
}
