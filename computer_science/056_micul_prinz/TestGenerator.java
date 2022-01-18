import java.io.*;
import java.util.*;
import java.math.*;
import java.util.stream.*;

public class TestGenerator {

    private static boolean isPalindrome(int n) {
    	String s = String.valueOf(n);
	int i = 0;
	int j = s.length() - 1;
	for (; i < j && s.charAt(i) == s.charAt(j); i++, j--);
        return i >= j;	
    }
    
    private static int solve(int n) {
	int res = n + 1;
	for(; !isPalindrome(res); res++);
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
                testIn.append(String.valueOf(test.n));
                testIn.newLine();
                testOut.append(String.format("%d", solve(test.n)));
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
	    test.n = random.nextInt(1_000_000_000) + 1;
            result.add(test);
        }

        return result;
    }

    private static class Test {
        int n;

        @Override
        public String toString() {
        	return "";
	}
    }
}
