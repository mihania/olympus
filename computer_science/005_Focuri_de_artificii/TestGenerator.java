import java.io.*;
import java.util.*;
import java.math.*;
import java.util.stream.*;

public class TestGenerator {
    private static int solve(int[] h, int[] a, int[] b) {

        // dp[i] - maximum length of block with i rocket in the begining.
        int[] dp = new int[h.length];
        int res = h.length == 0 ? 0 : 1;
        for (int i = 0; i < dp.length; i++) {
            dp[i] = 1;
        }

        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < i; j++) {
                if (h[i] >= a[j] && h[i] <= b[j]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                    res = Math.max(res, dp[i]);
                }
            }
        }

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
                testIn.append(String.format("%d", test.h.length));
                testIn.newLine();
                for (int j = 0; j < test.h.length; j++) {
                    testIn.append(String.format("%d %d %d", test.h[j], test.a[j], test.b[j]));
                    testIn.newLine();
                }

                testOut.append(String.format("%d", solve(test.h, test.a, test.b)));
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
	    int N = random.nextInt(i + 1) + 1;
            test.h = new int[N];
	    test.a = new int[N];
	    test.b = new int[N];
            for (int j = 0; j < N; j++) {
            	test.a[j] = random.nextInt(i + 1);
		test.b[j] = test.a[j] + random.nextInt(i + 1);
		test.h[j] = random.nextInt(i + 1);
            }

            result.add(test);
        }

        return result;
    }

    private static class Test {
        int[] h;
	int[] a;
	int[] b;


        @Override
        public String toString() {
        	return "";
	}
    }
}
