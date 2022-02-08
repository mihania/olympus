import java.io.*;
import java.util.*;
import java.math.*;
import java.util.stream.*;

public class TestGenerator {
    private static int solve1(List<int[]> m, int K) {
    	// dp[i][j] = max LIS of not more than j intersected intervals on [0, i]
	Collections.sort(m, (a, b) -> (a[1] == b[1] ? a[0] - b[0] : a[1] - b[1]));
	int[][] dp = new int[m.size()][K + 1];
	int maxLis = 0;
	for (int i = 0; i < dp.length; i++) {
		dp[i][0] = 1;
		for (int k = 0; k <= K; k++) {
			for (int j = 0; j < i; j++) {
				int d = m.get(j)[1] < m.get(i)[0] ? 0 : 1;
				if (d == 0) {
					dp[i][0] = Math.max(dp[i][0], dp[j][k] + 1);
				} else if (d + k <= K) {
					dp[i][d + k] = Math.max(dp[i][d + k], dp[j][k] + 1);
				}
			}

			maxLis = Math.max(maxLis, dp[i][k]);
		}
	}
	
	return  maxLis;
    }
    
    private static int solve2(List<int[]> m, int k) {
	Collections.sort(m, (a, b) -> (a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]));
	
	// max duration of all intervals
	int max = 0;
	for (int[] p : m) {
		max = Math.max(max, p[1] - p[0]); 
	}

	// binary searching the right most duration that will be able to serve with k rooms
	int i = 0;
	int j = max;
	while (i < j) {
		int mid = i + (j - i + 1) / 2;
		boolean val = canServeWithKRooms(m, mid, k);
	        if (val) {
			i = mid;
		} else {
			j = mid - 1;
		}

		// System.out.printf("i=%d j=%d mid=%d val=%b\n", i, j, mid, val);
	}
	
    	return i;
    }

    private static int getEnd(int[] m, int duration) {
    	return m[1] - m[0] < duration ? m[1] : m[0] + duration;
    }

    // returns false if m k more than k intersected intervals with  duration.
    private static boolean canServeWithKRooms(List<int[]> m, int duration, int k) {
	// System.out.printf("can duration=%d k=%d\n", duration, k);
	for (int i = 0; i < m.size(); ) {
		int max = getEnd(m.get(i), duration);
		int j = i;
		for (; j < m.size() && m.get(j)[0] < max; j++) {
			max = Math.max(max, getEnd(m.get(j), duration));
		}

		// System.out.printf("\t duration=%d i=%d j=%d max=%d\n", duration, i, j, max);
		
		if (j - i > k) {
			return false;
		}


		i = j == i ? i + 1 : j;
	}

	return true;
    }
    
    private static void solve(Test t) {
    	if (t.c == 1) {
		t.res = solve1(t.m, t.k);
	} else {
		t.res = solve2(t.m, t.k);
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
		testIn.append(String.valueOf(test.c));
		testIn.newLine();
		testIn.append(String.format("%d %d", test.m.size(), test.k));
                testIn.newLine();
                for (int j = 0; j < test.m.size(); j++) {
                    testIn.append(String.format("%d %d", test.m.get(j)[0], test.m.get(j)[1]));
		    testIn.newLine();
                }

                testOut.append(String.valueOf(test.res));
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
        Test t1 = new Test();
	int[][] t1m = {{2, 16}, {1, 3}, {3, 18}, {1, 20}};
	for (int[] k : t1m) {
		t1.m.add(k);
	}
	t1.k = 2;
	t1.c = 1;
	result.add(t1);
	int[][] t2m = {{5, 12}, {9, 18}, {1, 3}, {1, 7}};
	
	Test t2 = new Test();
	t2.k = 2;
	t2.c = 2;
	for (int[] k : t2m) {
		t2.m.add(k);
	}

	result.add(t2);
	
	for (int i = 0; i < T; i++) {
            
	    Test test = new Test();
	    int N = random.nextInt(i + 1) + 1;
	    test.m = new ArrayList<>();
	    int abMax = i < T / 2 ? 1 + i * 10 : 100_000;
	    test.c = 1 + random.nextInt(2);
	    test.k = 1 + random.nextInt(N);
            for (int j = 0; j < N; j++) {
		int a = random.nextInt(abMax);
		test.m.add(new int[] {
			a,
			Math.min(100_000, a + random.nextInt(abMax))});
            }

            result.add(test);
        }

        return result;
    }

    private static class Test {
        List<int[]> m = new ArrayList<>();
	int c;
	int k;
	int res;
    }
}
