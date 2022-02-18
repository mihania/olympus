import java.io.*;
import java.util.*;
import java.math.*;
import java.util.stream.*;

public class TestGenerator {
    public static void main(String[] args) throws Exception {
	if (args.length < 2) {
		System.out.println("Usage TestGenerator [tests folder] [output folder]");
		return;
	}

        BufferedWriter testIn = null;
        BufferedWriter testOut = null;
	String testCasesFolderName = args[0];
	String outputFolder = args[1];

        List<Test> tests = loadTests(testCasesFolderName);
        try {
            testIn = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(outputFolder + "/tests.in"), "utf-8"));
            testOut = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(outputFolder + "/tests.expected.out"), "utf-8"));
            testIn.append(String.valueOf(tests.size()));
            testIn.newLine();
            for (int i = 0; i < tests.size(); i++) {
                Test test = tests.get(i);
                testIn.append(test.input);
                testOut.append(test.output);
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

    private static List<Test> loadTests(String testCasesFolderName) throws Exception {
        final File testcasesFolder = new File(testCasesFolderName);
        final List<Test> result = new ArrayList<>();
        for (final File file : testcasesFolder.listFiles()) {
            final String fileName = file.getName();
            if (fileName.startsWith("input")) {
		int startIndex = fileName.indexOf('.') + 1;
                String testId = fileName.substring(startIndex);
                Test test = new Test();
		test.input = readFile(file);
		test.output = readFile(new File(testCasesFolderName, "output." + testId));
                test.testId = testId;
                result.add(test);
            }
        }

        // sort by testId in ascending order.
        return result.stream().sorted((a, b) -> a.testId.compareTo(b.testId)).collect(Collectors.toList());
    }

    private static String readFile(File file) throws Exception {
        Scanner scanner = null;
        StringBuilder res = new StringBuilder();
	try {
            scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
		    String line = scanner.nextLine();
		    if (line.length() > 0) {
		    	if (res.length() != 0) {
				res.append(System.lineSeparator());
			}

			res.append(line);
		    }	    
	    }

	    return res.toString();
        } finally {
            if (scanner != null) {
                scanner.close();
            }
        }
    }

    private static class Test {
        String testId;
	String input;
        String output;

        @Override
        public String toString() {
        	return null;
	}
    }
}
