import java.io.*;
import java.util.*;
import java.math.*;
import java.util.stream.*;

public class TestGenerator {
    private static void solve(Test t) {
        
        // sorting array to ensure countries 
	int[] v = t.m;
        Arrays.sort(v);
        int[][] T = new int[v.length][t.S + 1];
        for (int i = 0; i < v.length; i++) {
            for (int j = 0; j <= t.S; j++) {
                if (j < v[i]) {
                    
                    // we cannot conquer country i
                    if (i != 0) {
                        T[i][j] = T[i - 1][j];    
                    }
                    
                } else {
                    
                    if (i != 0) {
                        T[i][j] = T[i - 1][j];    
                    }                    
                    
                    int prevSpace = (i == 0 ? 0 : T[i - 1][j < v[i] ? 0 : j - v[i]]);
                    
                    // checking that prev territory is greater than current country.
                    if (v[i] > prevSpace && T[i][j] < v[i] + prevSpace) {
                        T[i][j] = v[i] + prevSpace;
                    }
                }
            }
        }        
        
        t.K = T[T.length - 1][T[0].length - 1];
        
        // traversing back to find the path
        int curS = T[T.length - 1][T[0].length - 1];
        int i = T.length - 1;
        int j = T[0].length - 1;
        t.countries = new ArrayList<>();
        while (curS > 0) {
            if (i > 0 && T[i][j] == T[i - 1][j]) {
            } else {
                t.countries.add(0, v[i]);
                j -= v[i];
                curS -= v[i];
            }
            
            i--;
        }
    }


    public static void main(String[] args) throws Exception {
        List<Test> tests = generateTests(100);
        BufferedWriter testIn = null;
        BufferedWriter testOut = null;
        try {
            testIn = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("tests.in"), "utf-8"));
            testOut = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("tests.expected.out"), "utf-8"));
            testIn.append(String.valueOf(tests.size()));
            testIn.newLine();
            for (int i = 0; i < tests.size(); i++) {
                Test test = tests.get(i);
                testIn.append(String.format("%d %d", test.m.length, test.S));
                testIn.newLine();
                for (int j = 0; j < test.m.length; j++) {
                    testIn.append(String.format("%d", test.m[j]));
                    testIn.newLine();
                }

                solve(test);
		testOut.append(String.format("%d %d", test.countries.size(), test.K));
		testOut.newLine();
		for (int k : test.countries) {
			testOut.append(String.valueOf(k));
			testOut.newLine();
		}

                // testOut.newLine();
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
	    int N = random.nextInt(20) + 1;
            test.m = new int[N];
	    int sum = 0;
            for (int j = 0; j < N; j++) {
            	test.m[j] = random.nextInt(20_000) + 1;
            	sum += test.m[j];
	    }

	    test.S = random.nextInt(sum + 1);
            result.add(test);
        }

        return result;
    }

    private static class Test {
        int[] m;
	int S;
	int K;
	List<Integer> countries;

        @Override
        public String toString() {
        	return "";
	}
    }
}
