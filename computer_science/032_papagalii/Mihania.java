import java.io.*;
import java.util.*;
import java.math.*;
import java.util.stream.*;

public class Mihania {
    public static void main(String[] args) throws Exception {
        List<Test> tests = readInput();
	BufferedWriter out = null;
        try {
		out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("tests.out"), "utf-8"));
		for (int i = 0; i < tests.size(); i++) {
            		Test test = tests.get(i);
			BigInteger result = solve(test.S, test.N);
			out.append(result.toString());
			out.newLine();
        	}
	} finally {
		if (out != null) {
			out.close();
		}
	}
    }

    private static BigInteger solveRecursive(int S, int N) {
        // dp[i][j] = number of combinations if starting to buy at day i from j parrot.
	BigInteger[][] dp = new BigInteger[N + 1][N * S + 1];
        return solveRecursive(0, 0, N, S, dp);
    }

    private static BigInteger solveRecursive(int id, int start, int N, int S, BigInteger[][] dp) {
        if (dp[id][start] == null) {
	    BigInteger res;
            if (id == N) {
                res = BigInteger.ONE;
            } else {
                res = BigInteger.ZERO;
                for (int i = start; i < (id + 1) * S; i++) {
                    res = res.add(solveRecursive(id + 1, i + 1, N, S, dp));
                }
            }

            dp[id][start] = res;
        }

        return dp[id][start];
    }

    private static BigInteger solve(int S, int N) {
        // we can see that we need to find all possible sequences of the following properties:
	// 1. The length of the sequence is N
	// 2. The elements in sequence are sorted.
	// 3. The elements in sequence are unique.
	
	// dp[i][j] = number of sequencies of size i if last element in the sequence is j
	
	BigInteger[][] dp = new BigInteger[N + 1][N * S + 1];
	for (int j = 1; j < dp[0].length; j++) {
		dp[1][j] = j <= S ?  BigInteger.ONE : BigInteger.ZERO;
	}

	for (int i = 2; i < dp.length; i++) {
		for (int j = 1; j < dp[0].length; j++) {
			dp[i][j] = BigInteger.ZERO;
		        if (j <= i * S) {	
				for (int k = j - 1; k > 0; k--) {
					dp[i][j] = dp[i][j].add(dp[i - 1][k]);
				}
			}
		}
	}

	BigInteger res = BigInteger.ZERO;
	for (int j = 1; j < dp[0].length; j++) {
		res = res.add(dp[N][j]);
	}

	return res;
    }
    
    private static List<Test> readInput() throws Exception {
        File file = new File("tests.in");
	Scanner scanner = null;
	List<Test> res = new ArrayList<>();
        try {	
            scanner = new Scanner(file);
	    int T = scanner.nextInt();
	    for (int i = 0; i < T; i++) {
	    	Test test = new Test();
            	test.S = scanner.nextInt();
            	scanner.skip(" ");
            	test.N = scanner.nextInt();
		if (scanner.hasNextLine()) {
			scanner.nextLine();
		}
		
		res.add(test);
	    }
        } finally {
            if (scanner != null) {
                scanner.close();
            }
        }

        return res;
    }

    private static class Test {
        String testId;
        int S;
        int N;
        BigInteger expectedResult;

        @Override
        public String toString() {
            return String.format("%s (S=%d N=%d)", testId, S, N);
        }
    }
}
