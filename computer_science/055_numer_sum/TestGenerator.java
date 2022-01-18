import java.io.*;
import java.util.*;
import java.math.*;
import java.util.stream.*;

public class TestGenerator {
    private static List<Integer> solve(int[] m) {
	List<Integer> res = new ArrayList<>();
	for (int k : m) {
		int kCopy = k;
		int sum = 0;
		while (k > 9) {
			sum += k % 10;
			k /= 10;
		}

		if (k == sum) {
			res.add(kCopy);
		}
	}

	Collections.sort(res, Collections.reverseOrder());
	return res;
    }

    public static void main(String[] args) throws Exception {
        List<Test> tests = generateTests(1000);
        BufferedWriter testIn = null;
        BufferedWriter testOut = null;
        try {
            testIn = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("tests.in"), "utf-8"));
            testOut = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("tests.expected.out"), "utf-8"));
            testIn.append(String.valueOf(tests.size()));
            testIn.newLine();
            for (int i = 0; i < tests.size(); i++) {
                Test test = tests.get(i);
                testIn.append(String.format("%d", test.m.length));
                testIn.newLine();
                for (int j = 0; j < test.m.length; j++) {
                    testIn.append(String.format("%d", test.m[j]));
                    testIn.newLine();
                }

		for (int k : solve(test.m)) {
                	testOut.append(String.format("%d", k));
			testOut.newLine();
		}

		testOut.newLine();
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

    private static List<Test> generateTests(int T) {
        Random random = new Random();
        List<Test> result = new ArrayList<>();
        for (int i = 0; i < T; i++) {
            Test test = new Test();
	    int N = 1000;
            test.m = new int[N];
            for (int j = 0; j < N; j++) {
            	test.m[j] = random.nextInt(1_000_000_000);
            }

            result.add(test);
        }

        return result;
    }

    private static class Test {
        int[] m;

        @Override
        public String toString() {
        	return "";
	}
    }
}
