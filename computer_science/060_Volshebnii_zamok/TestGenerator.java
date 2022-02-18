import java.io.*;
import java.util.*;
import java.math.*;
import java.util.stream.*;

public class TestGenerator {
    private static void solve(Test t) {
	boolean[] b = new boolean[10];    
	for (char ch : t.m) {
		if (Character.isDigit(ch)) {
			b[ch - '0'] = true;	
		} else {
			t.let += Character.toUpperCase(ch);
		}
	}

	for (int i = 1; i < b.length; i++) {
		if (b[i]) {
			t.num += i;
			if (t.num.length() == 1) {
				if (b[0]) {
					t.num += '0';
				}
			}
		}
	}	
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
                solve(test);
		testIn.append(String.format("%d", test.m.length));
                testIn.newLine();
                for (int j = 0; j < test.m.length; j++) {
                    testIn.append(String.format("%c", test.m[j]));
		    if (j != test.m.length - 1) {
		    	testIn.append(" ");
		    }
                }

                testIn.newLine();

                testOut.append(test.let);
                testOut.newLine();
		testOut.append(test.num);
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
	    test.m = new char[N];
            for (int j = 0; j < N; j++) {
		char ch;
		int rnd = random.nextInt(3);
		if (rnd == 0) {
			// digit
			test.m[j] = (char)('0' + random.nextInt(10));
		} else if (rnd == 1) {
			// small letter
			test.m[j] = (char)('a' + random.nextInt(26));
		} else if (rnd == 2) {
			// capital letter
			test.m[j] = (char)('A' + random.nextInt(26));
		}
            }

            result.add(test);
        }

        return result;
    }

    private static class Test {
        char[] m;
	String let = "";
	String num = "";

        @Override
        public String toString() {
        	return "";
	}
    }
}
